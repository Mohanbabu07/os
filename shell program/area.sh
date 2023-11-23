pi=`expr "scale=2; 22 / 7" | bc`
readonly pi
echo "enter value for radius"
read radius
area=`expr "scale=2; $pi * $radius * $radius" | bc`
circum=`expr "scale=2; 2* $pi * $radius" | bc`
echo "area: $area"
echo "circumference : $circum"
