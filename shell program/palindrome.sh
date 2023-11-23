echo "Enter a string"
read n
c=$(echo "$n" | tr -d ' ' | tr '[:upper:]' '[:lower:]')
reverse=$(echo "$c" | rev)
if [ "$c" = "$reverse" ];
then
  echo "$n is a palindrome"
else
  echo "$n is not a palindrome"
fi


