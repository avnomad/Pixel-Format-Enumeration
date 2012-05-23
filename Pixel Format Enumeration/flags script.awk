{
	print "\tif(pfd.dwFlags & " $1 ")";
	print "\t\tcout << right << setw(indent+width1+width2) << ' ' << \"" $1 "\" << '\\n';";
}