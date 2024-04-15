find ./w2 f1.txt
find ./w2 -name *.txt
find ./w2 -empty
find ./w2 -uma 664
find . -type d
find ./ -type f -name "*.txt" -exec grep 'Akshay' {} \;
find . -type f -exec grep -l "Akshay" {}