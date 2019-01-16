CD := cd
RM := rm -r
CP := cp -r
MKDIR := mkdir -p
MAKE := make

# All Target
all:
	($(CD) libk8090/Release/ && $(MAKE) all)
	($(CD) k8090cmd/Release/ && $(MAKE) all)

	$(MKDIR) binaries/usr/lib/
	$(MKDIR) binaries/usr/bin/
	$(CP) libk8090/Release/libk8090.so binaries/usr/lib/
	$(CP) k8090cmd/Release/k8090cmd binaries/usr/bin/

install:
	$(CP) binaries/usr/lib/libk8090.so /usr/lib/
	$(CP) binaries/usr/bin/k8090cmd /usr/bin/
	chmod 4755 /usr/bin/k8090cmd

uninstall:
	$(RM) /usr/lib/libk8090.so
	$(RM) /usr/bin/k8090cmd

clean:
	($(CD) libk8090/Release/ && $(MAKE) clean)
	($(CD) k8090cmd/Release/ && $(MAKE) clean)

