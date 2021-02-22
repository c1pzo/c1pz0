C1pzo Core integration/staging tree
=====================================

![c1core.jpg](https://github.com/c1pzo/c1pzo/src/qt/res/c1core.jpg)



What is C1pzo?
----------------

C1pzo is an experimental digital currency that enables instant payments to
anyone, anywhere in the world. C1pzo uses peer-to-peer technology to operate
with no central authority: managing transactions and issuing money are carried
out collectively by the network. C1pzo Core is the name of open source
software which enables the use of this currency.

For more information, as well as an immediately usable, binary version of
the C1pzo Core software, see https://c1pzocore.org/en/download/, or read the
[original whitepaper](https://c1pzocore.org/c1pzo.pdf).

License
-------

C1pzo Core is released under the terms of the MIT license. See [COPYING](COPYING) for more
information or see https://opensource.org/licenses/MIT.

Development Process
-------------------

The `master` branch is regularly built (see `doc/build-*.md` for instructions) and tested, but it is not guaranteed to be
completely stable. [Tags](https://github.com/c1pzo/c1pzo/tags) are created
regularly from release branches to indicate new official, stable release versions of C1pzo Core.

The https://github.com/c1pzo-core/gui repository is used exclusively for the
development of the GUI. Its master branch is identical in all monotree
repositories. Release branches and tags do not exist, so please do not fork
that repository unless it is for development reasons.

The contribution workflow is described in [CONTRIBUTING.md](CONTRIBUTING.md)
and useful hints for developers can be found in [doc/developer-notes.md](doc/developer-notes.md).

Testing
-------

Testing and code review is the bottleneck for development; we get more pull
requests than we can review and test on short notice. Please be patient and help out by testing
other people's pull requests, and remember this is a security-critical project where any mistake might cost people
lots of money.

### Automated Testing

Developers are strongly encouraged to write [unit tests](src/test/README.md) for new code, and to
submit new unit tests for old code. Unit tests can be compiled and run
(assuming they weren't disabled in configure) with: `make check`. Further details on running
and extending unit tests can be found in [/src/test/README.md](/src/test/README.md).

There are also [regression and integration tests](/test), written
in Python, that are run automatically on the build server.
These tests can be run (if the [test dependencies](/test) are installed) with: `test/functional/test_runner.py`

The CI (Continuous Integration) systems make sure that every pull request is built for Windows, Linux, and macOS,
and that unit/sanity tests are run automatically.

### Manual Quality Assurance (QA) Testing

Changes should be tested by somebody other than the developer who wrote the
code. This is especially important for large or high-risk changes. It is useful
to add a test plan to the pull request description if testing the changes is
not straightforward.

Translations
------------

Changes to translations as well as new translations can be submitted to
[C1pzo Core's Transifex page](https://www.transifex.com/c1pzo/c1pzo/).

Translations are periodically pulled from Transifex and merged into the git repository. See the
[translation process](doc/translation_process.md) for details on how this works.

**Important**: We do not accept translation changes as GitHub pull requests because the next
pull from Transifex would automatically overwrite them again.

Translators should also subscribe to the [mailing list](https://groups.google.com/forum/#!forum/c1pzo-translators).
## c1pzo




# BUILD

## build dependencies for C1pzo-Core.

 `` sudo apt install -y git build-essential autoconf libtool pkg-config libdb++-dev libboost-all-dev libssl-dev libevent-dev
`` 

``wget http://download.oracle.com/berkeley-db/db-5.1.29.tar.gz
 ``
 
`` tar -zxvf db-5.1.29.tar.gz
``

``cd db-5.1.29
``

`` cd build_unix
``

`` ../dist/configure --enable-cxx --disable-shared --with-pic --prefix=$BDB_PREFIX
``

`` make install 
 ``
  
## Compile and install C1pzo-Core
   
``git clone https://github.com/c1pzo/c1pzo.git
 ``
 
 ``./autogen.sh 
 ``
 
``export CPATH=/usr/local/BerkeleyDB.5.1/include
``

`` export LIBRARY_PATH=/usr/local/BerkeleyDB.5.1/lib
``

``export LD_LIBRARY_PATH=/usr/local/BerkeleyDB.5.1/lib
 ``

`` ./configure`` `` --with-incompatible-bdb ``

 `` make``
   
  ``sudo make install
  ``
  
`` reboot
 ``
 # RUN

 ``./c1pzod
 ``

