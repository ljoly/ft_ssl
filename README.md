ft_ssl
=======

Overview
-------
The goal of this project is to recode part of the OpenSSL program, specifically the cryptographic hash functions MD5, SHA-224 and SHA-256

Usage
-------
```
ft_ssl [md5|sha224|sha256] [-pqr] [-s string] [files ...]
```

Flags
-----------------------------
+ -p<br/>
    	Echo STDIN to STDOUT and append the checksum to STDOUT<br/>
+ -q<br/>
    	Quiet mode<br/>
+ -r<br/>
    	Reverse the format of the output<br/>
+ -s<br/>
    	Print the sum of the given string<br/>
