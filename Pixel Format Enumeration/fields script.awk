#	Copyright (C) 2011-2012 Vaptistis Anogeianakis <nomad@cornercase.gr>
#
#	This file is part of Pixel Format Enumeration.
#
#	Pixel Format Enumeration is free software: you can redistribute it and/or modify
#	it under the terms of the GNU General Public License as published by
#	the Free Software Foundation, either version 3 of the License, or
#	(at your option) any later version.
#
#	Pixel Format Enumeration is distributed in the hope that it will be useful,
#	but WITHOUT ANY WARRANTY; without even the implied warranty of
#	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#	GNU General Public License for more details.
#
#	You should have received a copy of the GNU General Public License
#	along with Pixel Format Enumeration.  If not, see <http://www.gnu.org/licenses/>.

{
	if($0 !~ /^\/\/|\/\*| \*/ && $0 != "")
	{
		print "cout << left << setw(indent) << ' ' << setw(width1) << \"" $2 \
				"\" << right << setw(width2) << (unsigned int)pfd." $2 " << '\\n';";
	}
	else
		print;
}