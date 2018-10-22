ft_ssl
=======

Overview
-------
The goal of this project is to recode part of the OpenSSL program, specifically the cryptographic hash functions MD5, SHA-224, SHA-256, SHA-384 and SHA-512

Usage
-------
```
ft_ssl [md5|sha224|sha256|sha384|sha512] [-pqr] [-s string] [files ...]
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
