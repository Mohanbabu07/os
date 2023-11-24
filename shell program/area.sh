pi=$(echo "scale=2; 22 / 7" | bc)
readonly pi
echo "Enter value for radius:"
read radius
area=$(echo "scale=2; $pi * $radius * $radius" | bc)
circum=$(echo "scale=2; 2 * $pi * $radius" | bc)
echo "Area: $area"
echo "Circumference: $circum"
