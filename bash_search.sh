
addsep=' '
foo=$1
file=$2
fileNew=$file'New'
echo $foo
echo $file
echo $fileNew


# search google for $foo and store in $filn
wget --user-agent=Mozilla/5.0 -O $file -e robots=off "http://www.google.com/search?hl=en&q=$foo"
printf "\n\nwget done\n\n"

# replace 'banana ' with 'newline banana' .. creating a new file $filn->$filN

nfoo=
sed -n 's/\"'"$foo$addsep"'/\n\"'"$foo$addsep"'/gpw '$fileNew'' $file

#works without addsep
#sed -n 's/\"'$foo' /\n\"'$foo' /gpw '$fileNew'' $file

printf "\n\nreplace done\n\n"

# now grep $foo
more $fileNew | grep -Po '(?<=\"'"$foo$addsep"').*(?=\")' | tee $fileNew

# works without addsep
# more $fileNew | grep -Po '(?<=\"'$foo' ).*(?=\")'
printf "\n\ngrep done\n\n"

