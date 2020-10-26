/*
===========================================================================

Copyright (C) 2017 waYne (CAM)

===========================================================================
*/
#ifndef ELYSIUM_COMMUNICATION_PROTOCOL_INTERNETLAYER_INTERNETPROTOCOLNUMBER
#define ELYSIUM_COMMUNICATION_PROTOCOL_INTERNETLAYER_INTERNETPROTOCOLNUMBER

#ifdef _MSC_VER
#pragma once
#endif

#ifndef ELYSIUM_CORE_INTEGER
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/Integer.hpp"
#endif

namespace Elysium::Communication::Protocol::InternetLayer
{
#if defined(_WIN32) || defined(_WIN64) || defined(_WINDOWS)
	enum class InternetProtocolNumber : Elysium::Core::uint8_t
#elif defined(__ANDROID__)
	enum class InternetProtocolNumber
#else
#error "undefined os"
#endif
	{
		// IPv6 Hop-by-Hop Option
		HopOpt = 0,

		// Internet Control Message Protocol
		Icmp = 1,

		// Internet Group Management Protocol
		Igmp = 2,

		// Gateway-to-Gateway Protocol
		Ggp = 3,

		// IP in IP (encapsulation) 
		IPinIP = 4,

		// Internet Stream Protocol
		St = 5,

		// Transmission Control Protocol
		Tcp = 6,

		// Core-based trees
		Cbt = 7,

		// Exterior Gateway Protocol
		Egp = 8,

		// Interior Gateway Protocol (any private interior gateway (used by Cisco for their IGRP))
		Igp = 9,

		// BBN RCC Monitoring 
		BbnRccMon = 10,

		// Network Voice Protocol
		Nvp2 = 11,

		// Xerox PUP
		Pup = 12,

		// ARGUS
		Argus = 13,

		// EMCON
		Emcon = 14,

		// Cross Net Debugger
		Xnet = 15,

		// Chaos
		Chaos = 16,

		// User Datagram Protocol
		Udp = 17,

		// Multiplexing
		Mux = 18,

		// DCN Measurement Subsystems
		DcnMeas = 19,

		// Host Monitoring Protocol
		Hmp = 20,

		// Packet Radio Measurement
		Prm = 21,

		// XEROX NS IDP
		XnsIdp = 22,

		// Trunk-1
		Trunk1 = 23,

		// Trunk-2
		Trunk2 = 24,

		// Leaf-1
		Leaf1 = 25,

		// Leaf-2
		Leaf2 = 26,

		// Reliable Data Protocol
		Rdp = 27,

		// Internet Reliable Transaction Protocol
		Irtp = 28,

		// ISO Transport Protocol Class 4
		IsoTp4 = 29,

		// Bulk Data Transfer Protocol
		NetBlt = 30,

		// MFE Network Services Protocol
		MfeNsp = 31,
		
		// MERIT Internodal Protocol
		MeritInp = 32,

		// Datagram Congestion Control Protocol 
		Dccp = 33,

		// Third Party Connect Protocol
		Tpc = 34,

		// Inter-Domain Policy Routing Protocol
		Idpr = 35,

		// Xpress Transport Protocol
		Xtp = 36,

		// Datagram Delivery Protocol
		Ddp = 37,

		// IDPR Control Message Transport Protocol
		IdprCmtp = 38,

		// TP++ Transport Protocol
		Tppp = 39,

		// IL Transport Protocol
		Il = 40,

		// IPv6 Encapsulation
		IPv6 = 41,

		// Source Demand Routing Protocol
		Sdrp = 42,

		// Routing Header for IPv6
		IPv6Route = 43,

		// Fragment Header for IPv6
		IPv6Frag = 44,

		// Inter-Domain Routing Protocol
		Idrp = 45,

		// Resource Reservation Protocol
		Rsvp = 46,

		// Generic Routing Encapsulation
		Gres = 47,

		// Dynamic Source Routing Protocol 
		Dsr = 48,

		// Burroughs Network Architecture
		Bna = 49,

		// Encapsulating Security Payload
		Esp = 50,

		// Authentication Header
		Ah = 51,

		// Integrated Net Layer Security Protocol
		Inlsp = 52,

		// SwIPe
		SwIPe = 53,

		// NBMA Address Resolution Protocol
		Narp = 54,

		// IP Mobility (Min Encap)
		Mobile = 55,

		// Transport Layer Security Protocol (using Kryptonet key management)
		Tlsp = 56,

		// Simple Key-Management for Internet Protocol
		Skip = 57,

		// ICMP for IPv6
		IPv6Icmp = 58,

		// No Next Header for IPv6
		IPv6NoNext = 59,

		// Destination Options for IPv6
		IPv6Opts = 60,

		// CFTP
		Cftp = 62,

		// SATNET and Backroom EXPAK
		SatExpak = 64,

		// Kryptolan
		Kryptolan = 65,

		// MIT Remote Virtual Disk Protocol
		Rvd = 66,

		// Internet Pluribus Packet Core
		Ippc = 67,

		// SATNET Monitoring
		SatnetMonitoring = 69,

		// VISA Protocol
		Visa = 70,

		// Internet Packet Core Utility
		Ipcu = 71,

		// Computer Protocol Network Executive
		Cpnx = 72,

		// Computer Protocol Heart Beat
		Cphb = 73,

		// Wang Span Network
		Wsn = 74,

		// Packet Video Protocol
		Pvp = 75,

		// Backroom SATNET Monitoring
		BrSatMon = 76,

		// SUN ND PROTOCOL-Temporary
		SunNd = 77,

		// WIDEBAND Monitoring
		WbMon = 78,

		// WIDEBAND EXPAK
		WbExpak = 79,

		// International Organization for Standardization Internet Protocol
		IsoIp = 80,

		// Versatile Message Transaction Protocol
		Vmtp = 81,

		// Secure Versatile Message Transaction Protocol
		SecureVmtp = 82,

		// VINES
		Vines = 83,

		// TTP
		Ttp = 84,

		// Internet Protocol Traffic Manager
		Iptm = 84,

		// NSFNET-IGP
		NsfnetIgp = 85,

		// Dissimilar Gateway Protocol
		Dgp = 86,

		// TCF
		Tcf = 87,

		// EIGRP
		Eigrp = 88,

		// Open Shortest Path First
		Ospf = 89,

		// Sprite RPC Protocol
		SpritePrc = 90,

		// Locus Address Resolution Protocol
		Larp = 91,

		// Multicast Transport Protocol
		Mtp = 92,

		// AX.25
		Ax25 = 93,

		// KA9Q NOS compatible IP over IP tunneling
		Os = 94,

		// Mobile Internetworking Control Protocol
		Micp = 95,

		// Semaphore Communications Sec. Pro
		SccSp = 96,

		// Ethernet-within-IP Encapsulation
		Etherip = 97,

		// Encapsulation Header
		Encap = 98,

		// GMTP
		Gmtp = 100,

		// Ipsilon Flow Management Protocol
		Ifmp = 101,

		// PNNI over IP
		Pnni = 102,

		// Protocol Independent Multicast
		Pimt = 103,

		// IBM's ARIS (Aggregate Route IP Switching) Protocol
		Aris = 104,

		// Space Communications Protocol Standards
		Scps = 105,

		// QNX
		Qnx = 106,

		// Active Networks
		AN = 107,

		// IP Payload Compression Protocol
		IPComp = 108,

		// Sitara Networks Protocol
		Snp = 109,

		// Compaq Peer Protocol
		CompaqPeer = 110,

		// IPX in IP
		IpxInIp = 111,

		// Virtual Router Redundancy Protocol, Common Address Redundancy Protocol (not IANA assigned)
		Vrrp = 112,

		// PGM Reliable Transport Protocol
		Pgm = 113,

		// Layer Two Tunneling Protocol Version 3
		L2tp = 115,

		// D-II Data Exchange (DDX)
		Ddx = 116,

		// Interactive Agent Transfer Protocol
		Iatp = 117,

		// Schedule Transfer Protocol
		Stp = 118,

		// SpectraLink Radio Protocol
		Srp = 119,

		// Universal Transport Interface Protocol
		Uti = 120,

		// Simple Message Protocol
		Smp = 121,

		// Simple Multicast Protocol
		Sm = 122,

		// Performance Transparency Protocol
		Ptp = 123,

		// Intermediate System to Intermediate System (IS-IS) Protocol over IPv4
		ISISoverIPv4 = 124,

		// Flexible Intra-AS Routing Environment 
		Fire = 125,

		// Combat Radio Transport Protocol
		Crtp = 126,

		// Combat Radio User Datagram
		Crudp = 127,

		// Service-Specific Connection-Oriented Protocol in a Multilink and Connectionless Environment 
		Sscopmce = 128,

		// 
		Iplt = 129,

		// Secure Packet Shield
		Sps = 130,

		// Private IP Encapsulation within IP
		Pipe = 131,

		// Stream Control Transmission Protocol
		Sctp = 132,

		// Fibre Channel
		Fc = 133,

		// Reservation Protocol (RSVP) End-to-End Ignore
		RsvpE2eIgnore = 134,

		// Mobility Extension Header for IPv6
		MobilityHeader = 135,

		// Lightweight User Datagram Protocol
		UdpLite = 136,

		// Multiprotocol Label Switching Encapsulated in IP
		MplsInIP = 137,

		// MANET Protocols
		Manet = 138,

		// Host Identity Protocol
		Hip = 139,

		// Site Multihoming by IPv6 Intermediation
		Shim6 = 140,

		// Wrapped Encapsulating Security Payload
		Wesp = 131,

		// Robust Header Compression
		Rohc = 142,

		// IPv6 Segment Routing (TEMPORARY - registered 2020-01-31, expires 2021-01-31)
		Ethernet = 143,

		// Any host internal protocol
		Unnamed61 = 61,

		// Any local network
		Unnamed63 = 63,

		// Any distributed file system 
		Unnamed68 = 68,

		// Any private encryption scheme
		Unnamed99 = 99,

		// Any 0-hop protocol
		Unnamed114 = 114,
		/*
		// Unassigned
		Unassigned = 144 - 252,

		// Use for experimentation and testing 
		Experimental = 253 - 254,
		*/
		// Reserved
		Reserved = 255
	};
}
#endif
