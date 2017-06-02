(* ::Package:: *)

(* ::Text:: *)
(*(**)
(*Microscope automation - Mathematica controller*)
(**)
(*Copyright (C) 2017 Anton Zyapkov, Kaloyan Genkov, Maya Zhekova*)
(**)
(*This program is free software:you can redistribute it and/or modify*)
(*it under the terms of the GNU General Public License as published by*)
(*the Free Software Foundation,either version 3 of the License,or*)
(*(at your option) any later version.*)
(**)
(*This program is distributed in the hope that it will be useful,but WITHOUT ANY WARRANTY;without even the implied warranty of*)
(*MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.*)
(**)
(*You should have received a copy of the GNU General Public License*)
(*along with this program.If not,see<http://www.gnu.org/licenses/>.*)
(**)*)


(* ::Input:: *)
(*com=DeviceOpen["Serial",{"COM7","BaudRate"->9600}]*)


(* ::Input:: *)
(*SetDirectory[NotebookDirectory[]]*)


(* ::Input:: *)
(*Move[mottor_,dir_,steps_]:=Module[{a},*)
(*DeviceWrite[com,ToString[mottor]<>"\n"];*)
(*Pause[0.2]*)
(*DeviceWrite[com,ToString[dir]<>"\n"];*)
(*Pause[0.2]*)
(*DeviceWrite[com,ToString[steps]<>"\n"];*)
(*Pause[0.2]*)
(*DeviceReadBuffer[com];*)
(*]*)


(* ::Input:: *)
(*(*DeviceClose[com]*)*)


(* ::Text:: *)
(*BUTTONS*)


(* ::Input:: *)
(*steps=16;*)
(*{{{},Button["Up",Move[2,1,steps]],{}},{Button["Left",Move[1,1,steps]],{},Button["Right",Move[1,2,steps]]},{{},Button["Down",Move[2,2,steps]],{}}}//TableForm*)


(* ::Input:: *)
(*Dynamic[CurrentImage[]]*)


(* ::Input:: *)
(*out=0;*)
(*For[i=1,i<=20,i++, *)
(*For[j=1,j<=20,j++,*)
(*out=out+1;*)
(*Export["img"<>ToString[out]<>".tif",CurrentImage[]];*)
(*Move[1,Mod[i,2]+1,20];*)
(*Pause[0.5];*)
(*];Move[2,1,20];*)
(*Pause[0.5];]*)


(* ::Input:: *)
(*CurrentImage[]*)
