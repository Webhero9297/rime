Rime [RIME] integration/staging tree
=====================================

![Rimecoin](https://raw.githubusercontent.com/CodingSultan/rimecoin/master/src/qt/res/images/splash.png)

What is the Rime [RIME] Blockchain?
---------------------------
// Omitted: A simple abstract about RIME.


Specifications
------------------
Rime uses
	libsecp256k1,
	libgmp,
	Boost1.63,
	OR Boost1.57,  
	Openssl1.02k,
	Berkeley DB 6.2.23,
	QT5.8 to compile

Port: 51395
RPC Port: 51394


BUILD LINUX
-----------
1) git clone https://github.com/CodingSultan/rimecoin

2) cd rimecoin/src

3) sudo make -f makefile.unix USE_UPNP=-           # Headless
