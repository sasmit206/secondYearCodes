
sasmit@Sasmits-MacBook-Air os_lab % grep "^[A-Z]" dummy.txt
The Quick Brown Fox Jumped Over The Fence

sasmit@Sasmits-MacBook-Air os_lab % grep "\.$" dummy.txt 
hey there.

sasmit@Sasmits-MacBook-Air os_lab % grep " \+" dummy.txt
The Quick Brown Fox Jumped Over The Fence
hey there.

sasmit@Sasmits-MacBook-Air os_lab % grep "[0-9]" dummy.txt
hey67

sasmit@Sasmits-MacBook-Air os_lab % grep "[0-9]" dummy.txt>dummy2.txt
sasmit@Sasmits-MacBook-Air os_lab % vi studentInformation.txt
sasmit@Sasmits-MacBook-Air os_lab % grep "IT" studentInformation.txt
1234:XYZ:ICT:IT:A:80:60:70
1236:PQR:CSE:IT:A:60:70:80
1237:LMN:ICT:IT:C:90:85:88
1240:JKL:CSE:IT:A:68:72:74
1241:MNO:ICT:IT:B:88:76:90
1243:VWX:ICT:IT:A:70:75:80
sasmit@Sasmits-MacBook-Air os_lab % sed "s:/:IT:/:Information Technology:/g" studentInformation.txt>ITStudents.txt
sed: 1: "s:/:IT:/:Information Te ...": bad flag in substitute command: '/'
sasmit@Sasmits-MacBook-Air os_lab % sed "s/:IT:/:Information Technology:/g" studentInformation.txt>ITStudents.txt 
sasmit@Sasmits-MacBook-Air os_lab % sed "s/:IT:/:Information Technology:/g" studentInformation.txt>ITStudents.txt
sasmit@Sasmits-MacBook-Air os_lab % sed "s/:IT:/:Information Technology:/g" studentInformation.txt>ITStudents.txt
sasmit@Sasmits-MacBook-Air os_lab % 
