#!/bin/bash 
echo 'Checking Soprano RDF library'
pkg-config --modversion --libs soprano > sop.txt
SOP=`cat sop.txt | grep '\.'`
SV=2.4.2
if [ "$SOP" != "$SV" ]
then
  echo 'You need to install Soprano RDF library in version 2.4.2'
  exit 1
fi
echo 'Check Soprano RDF library - OK'
rm sop.txt
echo 'Checking Qt library'
pkg-config --modversion --libs soprano > qt.txt
QT=`cat qt.txt | grep '\.'`
QV=4.6.2
if [ "$QT" == "$QV" ]
then
    echo 'You need to install Qt in version 4.6.2'
    exit 1
fi
echo 'Check Qt library - OK'
rm qt.txt
echo 'Building Thesauri Designer'
qmake
make
if [ $? -eq 0 ] ; then
    echo 'Thesauri Designer successfully build'
fi
