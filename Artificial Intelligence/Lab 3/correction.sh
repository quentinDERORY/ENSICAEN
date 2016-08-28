#!/bin/sh

echo $#
if [ $# -lt 1 ]
then
    echo "Usage: %0 g1"
    exit 1
fi

for i in ../$1/*.py
do

cp $i search.py
name=`basename $i`
echo
echo
echo
echo
echo

echo $name
read a

echo "##################################################################"
echo "Exercise 1: (x points)"
python pacman.py -p MinimaxAgent -l minimaxClassic -a depth=4 -k 1 -c --timeout=10  -q
python pacman.py -p MinimaxAgent -l smallClassic -a depth=3 -k 1 -c --timeout=10  -q
python pacman.py -p MinimaxAgent -l trappedClassic -a depth=3 -k 1 -c --timeout=10  -q

echo
echo "##################################################################"
echo "Exercise 2: (x points): "
python pacman.py -p MinimaxAgent -l minimaxClassic -a depth=4  -c --timeout=10 -q

echo
echo "##################################################################"
echo "Exercise 3: (x points): "
python pacman.py -p AlphaBetaAgent -a depth=3 -l smallClassic  -c --timeout=10 -q

echo
echo "##################################################################"
echo "Exercise 4 (x points)"
python pacman.py -p AlphaBetaAgent -l trappedClassic -a depth=3 -q -n 10  -c --timeout=10 -q

echo
echo "##################################################################"
echo "Exercise 5 (2 points)"
python pacman.py -l smallClassic -p AlphaBetaAgent -a evalFn=better  -c --timeout=10 -q

mv $i ../done/$1/$name
done