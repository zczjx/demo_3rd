#!/bin/bash  

i:=0
filelist=`ls timg*`

echo $filelist

for file in $filelist  
do  
    echo $file 
    mv $file  $file.jpg

    let i=i+1
    echo $i
done  
