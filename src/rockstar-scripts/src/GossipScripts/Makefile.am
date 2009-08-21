INCLUDES = -I$(top_srcdir)/src/ascent-logonserver \
   -I$(top_srcdir)/src/ascent-realmserver -I$(top_srcdir)/src/ascent-shared -I$(top_srcdir)/src/ascent-voicechat \
   -I$(top_srcdir)/src/ascent-world -I$(srcdir) -I$(srcdir)/../../../../dep/include \
   -I$(srcdir)/../../../../dep/src -I$(srcdir)/../../../../src

AM_CXXFLAGS = -DSCRIPTLIB

lib_LTLIBRARIES = libSunGossipScripts.la

libSunGossipScripts_la_SOURCES = \
Gossip_Innkeepers.cpp \
GuardGossip.cpp \
TrainerGossip.cpp \
Gossip_Mulgore.cpp \
Gossip_Shattrath.cpp \
Gossip_Tanaris.cpp \
Gossip_Stormwind.cpp \
Gossip_Moonglade.cpp \
Gossip_Battlemaster.cpp \
Setup.cpp
