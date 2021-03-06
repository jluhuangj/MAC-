
#include "Utils.h"
#include <WinSock2.h>
#include <IPHlpApi.h>
#pragma comment(lib,"Iphlpapi.lib")

#define  MALLOC(X) HeapAlloc(GetProcessHeap(),0,(x))
#define free(X) HeapFree(GetProcessHeap(),0,(x))

#define MACSESION 6

MACAddresses GetINETMacAddresses()
{
 	PIP_ADAPTER_ADDRESSES pAddresses = NULL;
	ULONG family = AF_INET;
	ULONG flags = GAA_FLAG_INCLUDE_PREFIX;
	ULONG outBufLen = sizeof(IP_ADAPTER_ADDRESSES);
	// Make an initial call to GetAdaptersAddresses to get the 
	// size needed into the outBufLen variable
	if (GetAdaptersAddresses(family, flags, NULL, pAddresses, &outBufLen) == ERROR_BUFFER_OVERFLOW)
	{
		pAddresses = static_cast<PIP_ADAPTER_ADDRESSES>(HeapAlloc(GetProcessHeap(), 0, outBufLen));
	}
	_ASSERT(pAddresses);

	// Make a second call to GetAdapters Addresses to get the

	// actual data we want

	DWORD dwRetVal = GetAdaptersAddresses(family, flags, NULL, pAddresses, &outBufLen);
 	MACAddresses vAddress;
	if (dwRetVal != ERROR_SUCCESS)
	{
		return vAddress;
	}
	PIP_ADAPTER_ADDRESSES pFirst = pAddresses;
	while (pAddresses)
	{
		BYTE* pa = pAddresses->PhysicalAddress;
		if (!pa || !pa[0])
		{
			break;
		}

		char bAddressBytes[MACSESION];
		int bAddressInt[MACSESION];
		memset(bAddressBytes, 0, MACSESION);
		size_t nAddressSize = pAddresses->PhysicalAddressLength;
		memcpy(bAddressBytes, pa, (nAddressSize < MACSESION ? nAddressSize : MACSESION));
		char CommarSeperatedAddress[MACSESION * 3] = { 0 };
		for (int i = 0; i < MACSESION; ++i)
		{
			bAddressInt[i] = bAddressBytes[i];
			bAddressInt[i] &= 0x000000ff; // avoid "ff" leading bytes when "char" is lager then 0x7f
		}
		sprintf(CommarSeperatedAddress, "%02x:%02x:%02x:%02x:%02x:%02x",
			bAddressInt[0],
			bAddressInt[1],
			bAddressInt[2],
			bAddressInt[3],
			bAddressInt[4],
			bAddressInt[5]); // Should use scl::FormatString inside 

		pAddresses = pAddresses->Next ? pAddresses->Next : NULL;
		vAddress.push_back(std::string(CommarSeperatedAddress));
	}
	HeapFree(GetProcessHeap(), 0, pFirst);
 	return vAddress;
 }


 void TimeHelper()
 {
	SYSTEMTIME st;
	GetLocalTime(&st);
	if(!(st.wYear==2018&&st.wMonth<5))
	{
		exit(0);
	}
 }

void UIHelper()
{
	BOOL watchVal=FALSE;
	MACAddresses macAdd = GetINETMacAddresses();
	for(int i=0;i<macAdd.size();i++)
	{
		if (macAdd[i] == uiHelperGlobal || macAdd[i] == uiHelperGlobal0 || macAdd[i] == uiHelperGlobal1)
		{
			watchVal=TRUE;
			break;
		}
	}
	if (!watchVal)
		exit(0);
}