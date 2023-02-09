#!/usr/bin/env bash

for commit_count in {2..100}
do
	let linenum="10+$commit_count"
	module load tex
	sed -i "$linenum i adding one line." foo.tex
	pdflatex foo.tex 
	
	git add -u
	git commit -m "Add a line to Tex file."
done
