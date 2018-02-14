name=$1
bisonfile=$name.ypp
compiledbison=$name.tab.cpp
flexfile=$name.l
cflex=lex.yy.c
cppflex=lex.yy.cpp

bison -d $bisonfile
flex $flexfile
cp $cflex $cppflex

g++ $cppflex $compiledbison Cparse.cpp Call.cpp -fpermissive -std=c++11 -g -o $name
