#!/usr/bin/env python
# -*- coding: utf-8 -*-

def formatf(source, destination):
	r=open(source, "r");
	w=open(destination, "w");
	out="";
	
	while True:
		C=r.read(1);
		if not C:
			break;
		c=ord(C);
		if c==20:
			out=out+"Á";
		elif c==21:
			out=out+"É";
		elif c==22:
			out=out+"Í";
		elif c==23:
			out=out+"Ó";
		elif c==24:
			out=out+"Ö";
		elif c==25:
			out=out+"Ő";
		elif c==26:
			out=out+"Ú";
		elif c==27:
			out=out+"Ü";
		elif c==28:
			out=out+"Ű";
		elif c==35:
			out=out+"á";
		elif c==36:
			out=out+"é";
		elif c==37:
			out=out+"í";
		elif c==38:
			out=out+"ó";
		elif c==39:
			out=out+"ö";
		elif c==40:
			out=out+"ő";
		elif c==41:
			out=out+"ú";
		elif c==42:
			out=out+"ü";
		elif c==43:
			out=out+"ű";
		else:
			out=out+C;
			
	w.write(out);
	r.close();
	w.close();

formatf("valid_out_u.txt", "valid_out.txt");