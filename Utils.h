#pragma once

#define WIN32_LEAN_AND_MEAN
#include <windows.h> 
//#include <WinSock2.h>
// #include <ws2ipdef.h>
// #include <Iphlpapi.h>
// #include <iptypes.h>

//#include <wincon.h> 
//#include <stdio.h> 
//#include <nb30.h>
#include <string>
#include <vector>
#include<io.h>
#include<iostream>

typedef std::vector< std::string > MACAddresses;
typedef MACAddresses::iterator vsIt;

//const std::string uiHelperGlobal = "54:ee:75:98:f8:b0";
const std::string uiHelperGlobal = "54:ee:75:98:f8:b0";



void TimeHelper();
void UIHelper();
MACAddresses GetINETMacAddresses();