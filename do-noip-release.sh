#!/bin/bash
cd ~
mkdir g-work
cd g-work
git clone https://github.com/ItsLucas/NOIP
cd noip
zip -r $1.zip $1/
mv $1.zip ~/Desktop
rm -rf ~/g-work
echo "Done"

