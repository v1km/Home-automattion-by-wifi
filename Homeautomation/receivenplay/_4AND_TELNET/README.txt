Step 1
first type AT
IF REPLY RECEIVED IS OK THEN PROCEED THE FOLLOWING STEPS:
1) AT+CWMODE=1
2)AT+CWJAP= �MARTIAN�,�bhulgaya123�
3)AT+CIFSR
4)AT+CIPMUX=1 
5)AT+CIPSERVER=1,80
6)TO SEND DATA:
AT+CIPSEND=0,5
7)TO RECEIVE DATA:
OPEN MOBILE TELNET APP
GOTO SETTINGS
TYPE THE IP AND PORT
SEND THE DATA
 