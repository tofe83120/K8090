/*
 * k8090cmd.cpp
 *
 *  Created on: 18 août 2011
 *      Author: cgarcia
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <exception>

#include <getopt.h>

#include "K8090.h"
#include "exceptions/UnknownCommandException.h"

using namespace std;
using namespace gsg::velleman::k8090;

// ******************************************

//#define DEBUG 1

// ******************************************

void usage(char * appName)
{
	cout << appName << " v1.0" << endl;
	cout << endl;
	cout << "Syntax : " << appName << " -c <command> -r <number> [-d <number>]" << endl;
	cout << "	-c <command>   Set command (on, off, timer, status)" << endl;
	cout << "	-r <number>    Set relay number (0-7)" << endl;
	cout << "	-d <number>    Set timer delay in seconds (1, 65536)" << endl;
	cout << endl;
	cout << "Examples : " << appName << " -c on -r 3" << endl;
	cout << "           " << appName << " -c timer -r 3 -d 3600" << endl;
	cout << endl;
}

string displayBinary(char data) {
	string result = "00000000";
	unsigned short mask = 0x80;

	int i = 0;
	while (mask) {
		if (data & mask)
			result[i] = '1';

		i++;
		mask >>= 1;
	}

	return result;
}

// **********************************************

int main(int argc, char** argv) {

	// ***** declare variables *****
	string cmd;
	int relay = -1;
	int delay = -1;

	int verbose = 0;

	// ***** decode options *****
	opterr = 0;

	static struct option long_options[] = {
		{ "verbose", no_argument, &verbose, 1 },
		{ "cmd", required_argument, 0, 'c' },
		{ "relay", required_argument, 0, 'r' },
		{ "delay", required_argument, 0, 'd' },
		{ "help", no_argument, 0, 'h' }, };

	int opt_index;
	int opt;
	while ((opt = getopt_long(argc, argv, "c:r:d:h", long_options, &opt_index))
			!= -1)
		switch (opt) {
		case 'c':
			cmd = optarg;
			break;

		case 'r':
			relay = atoi(optarg);
			break;

		case 'd':
			delay = atoi(optarg);
			break;

		case 'h':
			usage(argv[0]);
			return 0;

		case '?':
			if (optopt == 'c' || optopt == 'r' || optopt == 'd')
				cerr << "Option -" << (char) optopt << " requires an argument." << endl;
			else if (isprint(optopt))
				cerr << "Unknown option -" << (char) optopt << endl;
			else
				cerr << "Unknown option character '" << optopt << "'" << endl;

			usage(argv[0]);

			return 1;

		default:
			abort();
			break;
		}

#ifdef DEBUG
	cout << "options : cmd=" << cmd << ", relay=" << relay << ", delay=" << delay << endl;
#endif

	// ******************************

	K8090 k8090;

	int exit = 0;
	try {
		if (cmd == "on")
			if (relay == -1)
				k8090.setAllRelayOn();
			else
				k8090.setRelayOn(relay);

		else if (cmd == "off")
			if (relay == -1)
				k8090.setAllRelayOff();
			else
				k8090.setRelayOff(relay);

		else if (cmd == "timer")
			k8090.setTimerStart(relay, delay);

		else if (cmd == "status") {
			if (relay == -1) {
				exit = k8090.getAllRelayStatus();
				cout << displayBinary((short) exit) << endl;
			} else {
				exit = k8090.getRelayStatus(relay);
				cout << exit << endl;
			}
		} else {
			usage(argv[0]);

			throw UnknownCommandException(
					"Incorrect or empty command requested : '" + cmd + "'");
		}
	} catch (K8090Exception& e) {
		cerr << "K8090Exception = " << e.what() << endl;
		exit = -200;
	} catch (exception& e) {
		cerr << "Exception = " << e.what() << endl;
		exit = -100;
	} catch (...) {
		cerr << "Unexpected exception" << endl;
		exit = -1;
	}

	return exit;
}
