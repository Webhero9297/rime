Copyright (c) 2009-2012 Bitcoin Developers

See readme-qt.rst for instructions on building Rime QT, the
graphical user interface.

Tested on 10.5 and 10.6 intel.  PPC is not supported because it's big-endian.

All of the commands should be executed in Terminal.app.. it's in
/Applications/Utilities

1.  Clone the github tree to get the source code:

git clone http://github.com/Rimedev/Rime Rime

2.  Download and install MacPorts from http://www.macports.org/

2a. (for 10.7 Lion)
    Edit /opt/local/etc/macports/macports.conf and uncomment "build_arch i386"

3.  Install dependencies from MacPorts

sudo port install boost db48 openssl miniupnpc

Optionally install qrencode (and set USE_QRCODE=1):
sudo port install qrencode

4.  Now you should be able to build Rimed:

cd Rime/src
make -f makefile.osx

Run:
  ./Rimed --help  # for a list of command-line options.
Run
  ./Rimed -daemon # to start the Rime daemon.
Run
  ./Rimed help # When the daemon is running, to get a list of RPC commands
