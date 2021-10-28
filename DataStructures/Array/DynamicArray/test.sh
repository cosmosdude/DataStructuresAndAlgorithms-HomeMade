COMPILER="g++ -std=c++17"
COMPILE="$COMPILER -c "
LINK="$COMPILER *.o -o test.out"

declare -a SOURCES=("test.cpp")

for i in ${SOURCES[@]}
do
	$COMPILE $i
done

$COMPILER *.o -o test.out

