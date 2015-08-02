#ifndef __USER_DEF_SERVER_H
#define __USER_DEF_SERVER_H

#include <Windows.h>
#include <iostream> 
#include <fstream>
#include <vector>
#include "userdefined_types.h"

using namespace userdefined;

#define THRIFT_ZERO_SIZE_STRING_TO_NULL(STR) (STR.size()>0?STR.c_str():NULL)
#define THRIFT_A_TO_STRING(VAL) (std::string((LPSTR)(VAL)))                                                                 // string to binary
#define THRIFT_W_TO_STRING(VAL) (std::string((LPCSTR)(VAL), ((VAL)?wcslen((LPCWSTR)VAL)*sizeof(WCHAR)+sizeof(WCHAR):0)))    // wstring to binary
#define THRIFT_B_TO_STRING(POI, LEN) (std::string((LPSTR)(POI), (((LPSTR)POI)!=NULL ? LEN : 0)))                            // buffer to binary
#define THRIFT_SAFE_GET(MAP, NAME, DEFAULT) ( MAP.find(NAME)!=MAP.end() ? MAP.at(NAME) : DEFAULT )
#define THIRFT_NULL_STRING(VAL) (VAL.size()>0 ? VAL.c_str() : NULL)
#define RP_GET_OFFSET(BUFFER, POINT) (BUFFER==NULL||POINT==NULL ? -1 : (DWORD)((PUCHAR)(POINT)-(PUCHAR)BUFFER))


class ApiForwardHandler : virtual public ApiForwardIf {
public:
    ApiForwardHandler() {

        fpOpenPrinterA = NULL;
        fpOpenPrinterW = NULL;
        fpStartPagePrinter = NULL;
        fpStartDocPrinterW = NULL;
        fpWritePrinter = NULL;
        fpEndPagePrinter = NULL;
        fpEndDocPrinter = NULL;
        fpClosePrinter = NULL;

        fpCloseSpoolFileHandle = NULL;
        fpCommitSpoolData = NULL;
        fpDocumentEvent = NULL;
        fpDocumentPropertiesW = NULL;
        fpEnumFormsW = NULL;
        fpEnumPrintersW = NULL;
        fpFindClosePrinterChangeNotification = NULL;
        fpFindFirstPrinterChangeNotification = NULL;
        fpFindNextPrinterChangeNotification = NULL;
        fpFreePrinterNotifyInfo = NULL;
        fpGetDefaultPrinterW = NULL;
        fpGetPrinterDataW = NULL;
        fpGetPrinterDataExW = NULL;
        fpGetPrinterW = NULL;
        fpGetSpoolFileHandle = NULL;
        fpIsValidDevmodeW = NULL;
        fpOpenPrinter2W = NULL;
        fpOpenPrinter2A = NULL;

        fpOpenUsbPort = NULL;
        fpCloseUsbPort = NULL;
        fpWriteUSB = NULL;
        fpReadUSB = NULL;
        fpPrintBitmap = NULL;
        fpPrint1DBarcode = NULL;
        fpPrintPDF417 = NULL;
        fpPrintQRCode = NULL;
    
        _hwinspool = LoadLibraryA("winspool.drv");
        if (_hwinspool==NULL) {
            printf("LoadLibraryA('winspool.drv') failed.\n");
        }
        else {
            fpOpenPrinterA = (BOOL (WINAPI *)(LPSTR , LPHANDLE , LPPRINTER_DEFAULTSA))GetProcAddress(_hwinspool, "OpenPrinterA");
            fpOpenPrinterW = (BOOL (WINAPI *)(LPWSTR , LPHANDLE , LPPRINTER_DEFAULTSW))GetProcAddress(_hwinspool, "OpenPrinterW");
            fpStartPagePrinter = (BOOL (WINAPI *)(HANDLE))GetProcAddress(_hwinspool, "StartPagePrinter");
            fpStartDocPrinterW = (DWORD (WINAPI *)(HANDLE, DWORD , LPBYTE))GetProcAddress(_hwinspool, "StartDocPrinterW");
            fpWritePrinter = (BOOL (WINAPI *)(HANDLE, LPVOID, DWORD, LPDWORD))GetProcAddress(_hwinspool, "WritePrinter");
            fpEndPagePrinter = (BOOL (WINAPI *)(HANDLE hPrinter))GetProcAddress(_hwinspool, "EndPagePrinter");
            fpEndDocPrinter = (BOOL (WINAPI *)(HANDLE hPrinter))GetProcAddress(_hwinspool, "EndDocPrinter");
            fpClosePrinter = (BOOL (WINAPI *)(HANDLE hPrinter))GetProcAddress(_hwinspool, "ClosePrinter");


            fpCloseSpoolFileHandle = (BOOL (WINAPI *)(HANDLE hPrinter, HANDLE hSpoolFile))GetProcAddress(_hwinspool, "CloseSpoolFileHandle");;
            fpCommitSpoolData = (HANDLE (WINAPI *)(HANDLE hPrinter, HANDLE hSpoolFile, DWORD cbCommit))GetProcAddress(_hwinspool, "CommitSpoolData");
            fpDocumentEvent = (HRESULT (WINAPI *)(HANDLE hPrinter, HDC hdc, INT iEsc, ULONG cbIn, PVOID pvIn, ULONG cbOut, PVOID pvOut))GetProcAddress(_hwinspool, "DocumentEvent");
            fpDocumentPropertiesW = (LONG (WINAPI *)(HWND hWnd, HANDLE hPrinter, LPWSTR pDeviceName, PDEVMODEW pDevModeOutput, PDEVMODEW pDevModeInput, DWORD fMode))GetProcAddress(_hwinspool, "DocumentPropertiesW");
            fpEnumFormsW = (BOOL (WINAPI *)(HANDLE hPrinter, DWORD Level, LPBYTE  pForm, DWORD cbBuf, LPDWORD pcbNeeded, LPDWORD pcReturned))GetProcAddress(_hwinspool, "EnumFormsW");
            fpEnumPrintersW = (BOOL (WINAPI *)(DWORD Flags, LPWSTR Name,DWORD Level, LPBYTE pPrinterEnum, DWORD cbBuf, LPDWORD pcbNeeded, LPDWORD pcReturned))GetProcAddress(_hwinspool, "EnumPrintersW");
            fpFindClosePrinterChangeNotification = (BOOL (WINAPI *)(HANDLE hChange))GetProcAddress(_hwinspool, "FindClosePrinterChangeNotification");
            fpFindFirstPrinterChangeNotification = (HANDLE (WINAPI *)(HANDLE hPrinter, DWORD fdwFilter, DWORD fdwOptions, LPVOID pPrinterNotifyOptions))GetProcAddress(_hwinspool, "FindFirstPrinterChangeNotification");
            fpFindNextPrinterChangeNotification = (BOOL (WINAPI *)(HANDLE hChange,PDWORD pdwChange,LPVOID pPrinterNotifyOptions,LPVOID *ppPrinterNotifyInfo))GetProcAddress(_hwinspool, "FindNextPrinterChangeNotification");
            fpFreePrinterNotifyInfo = (BOOL (WINAPI *)(PPRINTER_NOTIFY_INFO pPrinterNotifyInfo))GetProcAddress(_hwinspool, "FreePrinterNotifyInfo");
            fpGetDefaultPrinterW = (BOOL (WINAPI *)(LPWSTR pszBuffer, LPDWORD pcchBuffer))GetProcAddress(_hwinspool, "GetDefaultPrinterW");
            fpGetPrinterDataW = (DWORD (WINAPI *)(HANDLE hPrinter, LPWSTR  pValueName, LPDWORD pType, LPBYTE pData, DWORD nSize, LPDWORD pcbNeeded))GetProcAddress(_hwinspool, "GetPrinterDataW");
            fpGetPrinterDataExW = (DWORD (WINAPI *)(HANDLE hPrinter,LPCWSTR pKeyName, LPCWSTR pValueName,LPDWORD pType, LPBYTE  pData, DWORD nSize, LPDWORD pcbNeeded))GetProcAddress(_hwinspool, "GetPrinterDataExW");
            fpGetPrinterW = (BOOL (WINAPI *)(HANDLE hPrinter, DWORD Level, LPBYTE pPrinter, DWORD cbBuf, LPDWORD pcbNeeded))GetProcAddress(_hwinspool, "GetPrinterW");
            fpGetSpoolFileHandle = (HANDLE (WINAPI *)(HANDLE hPrinter))GetProcAddress(_hwinspool, "GetSpoolFileHandle");
            fpIsValidDevmodeW = (BOOL (WINAPI *)(PDEVMODEW pDevmode, size_t DevmodeSize))GetProcAddress(_hwinspool, "IsValidDevmodeW");
            fpOpenPrinter2W = (BOOL (WINAPI *)(LPCWSTR pPrinterName, LPHANDLE phPrinter, LPPRINTER_DEFAULTSW pDefault, /*PPRINTER_OPTIONS*/ PVOID pOptions))GetProcAddress(_hwinspool, "OpenPrinter2W");
            fpOpenPrinter2A = (BOOL (WINAPI *)(LPCSTR pPrinterName, LPHANDLE phPrinter, LPPRINTER_DEFAULTSA pDefault, /*PPRINTER_OPTIONS*/ PVOID pOptions))GetProcAddress(_hwinspool, "OpenPrinter2A");
        }

        // Not a spooler, special codes for samsung printers
        _hbxlpdir = LoadLibraryA("BXLPDIR.DLL");
        if (_hbxlpdir==NULL) {
            printf("LoadLibraryA('BXLPDIR.DLL') failed.\n");
        }
        else {
            fpOpenUsbPort = (int (WINAPI *)(int))GetProcAddress(_hbxlpdir, "OpenUsbPort");
            fpCloseUsbPort = (int (WINAPI *)())GetProcAddress(_hbxlpdir, "CloseUsbPort");
            fpWriteUSB = (int (WINAPI *)(const char *,int))GetProcAddress(_hbxlpdir, "WriteUSB");
            fpReadUSB = (int (WINAPI *)(const char *, int))GetProcAddress(_hbxlpdir, "ReadUSB");
            fpPrintBitmap = (int (WINAPI *)(const char *))GetProcAddress(_hbxlpdir, "PrintBitmap");
            fpPrint1DBarcode = (int (WINAPI *)(int,int,int,int,const char *)) GetProcAddress(_hbxlpdir, "Print1DBarcode");
            fpPrintPDF417 = (int (WINAPI *)(int,int,int,int,int,int,const char *))GetProcAddress(_hbxlpdir, "PrintPDF417");
            fpPrintQRCode = (int (WINAPI *)(int,int,int,const char *))GetProcAddress(_hbxlpdir, "PrintQRCode");
        }
    }

    ~ApiForwardHandler() {
        if (_hbxlpdir) FreeLibrary(_hbxlpdir);
        if (_hwinspool) FreeLibrary(_hwinspool);
    }

public:
    void OpenPrinterA(std::map<std::string, int64_t> & _return, const std::string& pPrinterName,
                        const bool pDefaultExist, const std::string& pDatatype,
                        const std::string& pDevMode, const int32_t DesiredAccess) {
        // Your implementation goes here
        printf("OpenPrinterA\n");

        _return["return"] = false;
        if (fpOpenPrinterA==NULL) return;

        HANDLE localPrinter;
        PRINTER_DEFAULTSA localDefault; 
        LPPRINTER_DEFAULTSA pLocalDefault; 
        int64_t localPrinter64 = 0L;

        if (pDefaultExist) {
            localDefault.pDatatype = (LPSTR) THRIFT_ZERO_SIZE_STRING_TO_NULL(pDatatype);
            localDefault.pDevMode = (LPDEVMODEA) THRIFT_ZERO_SIZE_STRING_TO_NULL(pDevMode);
            localDefault.DesiredAccess = DesiredAccess;
            pLocalDefault = &localDefault;
        }
        else {
            pLocalDefault = NULL;
        }

        BOOL ret = fpOpenPrinterA((LPSTR)THRIFT_ZERO_SIZE_STRING_TO_NULL(pPrinterName), &localPrinter, pLocalDefault);
        if (!ret) return;

        localPrinter64 = (int64_t) localPrinter;
        _return["return"] = true;
        _return["phPrinter"] = localPrinter64;

        printf("OpenPrinterA('%s', %x)\n", pPrinterName.c_str(), localPrinter);
        return;
    }

    void OpenPrinterW(std::map<std::string, int64_t> & _return, const std::string& pPrinterName,
                        const bool pDefaultExist, const std::string& pDatatype,
                        const std::string& pDevMode, const int32_t DesiredAccess) {        // Your implementation goes here
        printf("OpenPrinterW\n");

        _return["return"] = false;
        if (fpOpenPrinterW==NULL) return;

        HANDLE localPrinter;
        PRINTER_DEFAULTSW localDefault; 
        LPPRINTER_DEFAULTSW pLocalDefault; 
        int64_t localPrinter64 = 0L;

        if (pDefaultExist) {
            localDefault.pDatatype = (LPWSTR) THRIFT_ZERO_SIZE_STRING_TO_NULL(pDatatype);
            localDefault.pDevMode = (LPDEVMODEW) THRIFT_ZERO_SIZE_STRING_TO_NULL(pDevMode);
            localDefault.DesiredAccess = DesiredAccess;
            pLocalDefault = &localDefault;
        }
        else {
            pLocalDefault = NULL;
        }

        BOOL ret = fpOpenPrinterW( (LPWSTR)THRIFT_ZERO_SIZE_STRING_TO_NULL(pPrinterName), &localPrinter, pLocalDefault);
        if (!ret) return;

        localPrinter64 = (int64_t) localPrinter;
        _return["return"] = true;
        _return["phPrinter"] = localPrinter64;

        printf("localPrinter=%x\n", localPrinter);
        return;
    }

    bool StartPagePrinter(const int64_t hPrinter) {
        printf("StartPagePrinter\n");
        if (fpStartPagePrinter==NULL) return false;
        return fpStartPagePrinter((HANDLE)hPrinter);
    }

    int32_t StartDocPrinterW(const int64_t hPrinter, const int32_t Level, const std::string& pDocName, const std::string& pOutputFile, const std::string& pDatatype) {
        printf("StartDocPrinter\n");
        if (fpStartDocPrinterW==NULL) return 0;
        DOC_INFO_1W doc;
        doc.pDocName = pDocName.size()>0 ? (LPWSTR) pDocName.c_str(): NULL;
        doc.pOutputFile = pOutputFile.size()>0 ? (LPWSTR) pOutputFile.c_str(): NULL;
        doc.pDatatype = pDatatype.size()>0 ? (LPWSTR) pDatatype.c_str(): NULL;
        return fpStartDocPrinterW((HANDLE)hPrinter, Level, (LPBYTE)&doc);
    }


    void WritePrinter(std::map<std::string, int32_t> & _return, const int64_t hPrinter, const std::string& pBuf, const int32_t cbBuf) {
        printf("WritePrinter\n");
        _return["return"] = false;
        if (fpOpenPrinterW==NULL) return;

        DWORD localWrittten;
        bool ret = fpWritePrinter((HANDLE)hPrinter, (LPVOID)pBuf.c_str(), cbBuf, &localWrittten);
        if (!ret) return;

        _return["return"] = true;
        _return["pcWritten"] = localWrittten;
        return;
    }

    bool EndPagePrinter(const int64_t hPrinter) {
        printf("EndPagePrinter\n");
        if (fpEndPagePrinter==NULL) return false;
        return fpEndPagePrinter((HANDLE)hPrinter);
    }

    bool EndDocPrinter(const int64_t hPrinter) {
        printf("EndDocPrinter\n");
        if (fpEndDocPrinter==NULL) return false;
        return fpEndDocPrinter((HANDLE)hPrinter);
    }

    bool ClosePrinter(const int64_t hPrinter) {
        printf("ClosePrinter\n");
        if (fpClosePrinter==NULL) return false;
        return fpClosePrinter((HANDLE)hPrinter);
    }


    bool CloseSpoolFileHandle(const int64_t hPrinter, const int64_t hSpoolFile) {
        printf("CloseSpoolFileHandle\n");
        if (fpCloseSpoolFileHandle==NULL) return false;

        return fpCloseSpoolFileHandle((HANDLE)hPrinter, (HANDLE)hSpoolFile) ;
  } 

  int64_t CommitSpoolData(const int64_t hPrinter, const int64_t hSpoolFile, const int32_t cbCommit) {
        printf("CommitSpoolData\n");
        if (fpCommitSpoolData==NULL) return false;

        int64_t ret = 0L;
        ret = (int64_t)fpCommitSpoolData((HANDLE)hPrinter, (HANDLE)hSpoolFile, cbCommit);
        return ret;
    }

    void DocumentEvent(std::map<std::string, std::string> & _return, const int64_t hPrinter, const int64_t hdc, const int32_t iEsc, const int32_t cbIn, const std::string& pvIn, const int32_t cbOut, const std::string& pvOut) {
        printf("DocumentEvent\n");
        if (fpDocumentEvent==NULL) return;

        return;
    }

    void DocumentPropertiesW(ArgDocumentPropertiesW& _return, const ArgDocumentPropertiesW& arg) {
        printf("DocumentPropertiesW\n");
        _return.ret = (LONG)-1;
        _return.lasterror = GetLastError();
        if (fpDocumentPropertiesW==NULL) return;

        std::shared_ptr<std::vector<char>> localpDevModeOutput(new std::vector<char>());
        localpDevModeOutput->reserve(arg.pDevModeOutput.size());

        LONG ret = fpDocumentPropertiesW(GetDesktopWindow(),
                        (HANDLE)arg.hPrinter,
                        (LPWSTR)THIRFT_NULL_STRING(arg.pDeviceName),
                        (PDEVMODEW)(arg.pDevModeOutput.size()>0?reinterpret_cast<LPBYTE>(localpDevModeOutput->data()):NULL),
                        (PDEVMODEW)THIRFT_NULL_STRING(arg.pDevModeInput),
                        arg.fMode
                        );

        _return.ret = ret;
        _return.lasterror = GetLastError();

        _return.pDevModeOutput = THRIFT_B_TO_STRING((arg.pDevModeOutput.size()>0?reinterpret_cast<LPBYTE>(localpDevModeOutput->data()):NULL), arg.pDevModeOutput.size());
        return ;
    }

    void EnumFormsW(std::map<std::string, std::string> & _return, const int64_t hPrinter, const int32_t Level, const int32_t cbBuf) {
        printf("EnumFormsW\n");
        if (fpEnumFormsW==NULL) return;

        return;
    }

    void EnumPrintersW(ArgEnumPrintersW& _return, const ArgEnumPrintersW& arg) {
        printf("EnumPrintersW\n");

        _return.ret = false;
        if (fpEnumPrintersW==NULL) return;

        DWORD localpcbNeeded = 0;
        DWORD localpcReturned = 0;
        std::shared_ptr<std::vector<char>> localBuffer(new std::vector<char>());
        localBuffer->reserve(arg.cbBuf);

        BOOL ret = fpEnumPrintersW(arg.Flags,
                        (LPWSTR)THIRFT_NULL_STRING(arg.Name),
                        arg.Level,
                        (arg.cbBuf>0?reinterpret_cast<LPBYTE>(localBuffer->data()):NULL),
                        arg.cbBuf,
                        &localpcbNeeded,
                        &localpcReturned
                        );
        _return.pPrinterEnum = THRIFT_B_TO_STRING((arg.cbBuf>0?reinterpret_cast<LPBYTE>(localBuffer->data()):NULL), arg.cbBuf);
        _return.pcbNeeded = localpcbNeeded;
        _return.pcReturned = localpcReturned;
        _return.ret = ret;

        if (ret && localpcReturned>0) {
            switch(arg.Level){
            case 1:
                {
                LPPRINTER_INFO_1 info = (LPPRINTER_INFO_1) localBuffer->data();
                _return.int32PrinterEnum["pDescription"] = RP_GET_OFFSET(info, info->pDescription);
                _return.int32PrinterEnum["pName"] = RP_GET_OFFSET(info, info->pName);
                _return.int32PrinterEnum["pComment"] = RP_GET_OFFSET(info, info->pComment);
                break;
                }
            case 2:
                {
                LPPRINTER_INFO_2 info = (LPPRINTER_INFO_2) localBuffer->data();
                _return.int32PrinterEnum["pServerName"] = RP_GET_OFFSET(info, info->pServerName);
                _return.int32PrinterEnum["pPrinterName"] = RP_GET_OFFSET(info, info->pPrinterName);
                _return.int32PrinterEnum["pShareName"] = RP_GET_OFFSET(info, info->pShareName);
                _return.int32PrinterEnum["pPortName"] = RP_GET_OFFSET(info, info->pPortName);
                _return.int32PrinterEnum["pDriverName"] = RP_GET_OFFSET(info, info->pDriverName);
                _return.int32PrinterEnum["pComment"] = RP_GET_OFFSET(info, info->pComment);
                _return.int32PrinterEnum["pLocation"] = RP_GET_OFFSET(info, info->pLocation);
                _return.int32PrinterEnum["pDevMode"] = RP_GET_OFFSET(info, info->pDevMode, info->pDevMode->dmSize);
                _return.int32PrinterEnum["pSepFile"] = RP_GET_OFFSET(info, info->pSepFile);
                _return.int32PrinterEnum["pPrintProcessor"] = RP_GET_OFFSET(info, info->pPrintProcessor);
                _return.int32PrinterEnum["pParameters"] = RP_GET_OFFSET(info, info->pParameters);
                break;
                }
            case 4:
                {
                LPPRINTER_INFO_4 info = (LPPRINTER_INFO_4) localBuffer->data();
                _return.int32PrinterEnum["pPrinterName"] = RP_GET_OFFSET(info, info->pPrinterName);
                _return.int32PrinterEnum["pServerName"] = RP_GET_OFFSET(info, info->pServerName);
                break;
                }
            case 5:
                {
                LPPRINTER_INFO_5 info = (LPPRINTER_INFO_5) localBuffer->data();
                _return.int32PrinterEnum["pPrinterName"] = RP_GET_OFFSET(info, info->pPrinterName);
                _return.int32PrinterEnum["pPortName"] = RP_GET_OFFSET(info, info->pPortName);
                break;
                }
            default:
                _return.ret = false;
            }
        }

        return;
    }

    bool FindClosePrinterChangeNotification(const int64_t hChange) {
        printf("FindClosePrinterChangeNotification\n");
        if (fpFindClosePrinterChangeNotification==NULL) return false;

        return false;
    }

    int64_t FindFirstPrinterChangeNotification(const int64_t hPrinter, const int32_t fdwFilter, const int32_t fdwOptions, const std::string& pPrinterNotifyOptions) {
        printf("FindFirstPrinterChangeNotification\n");
        if (fpFindFirstPrinterChangeNotification==NULL) return 0;

        return 0;
    }

    void FindNextPrinterChangeNotification(std::map<std::string, std::string> & _return, const int64_t hChange, const std::string& pPrinterNotifyOptions) {
        printf("FindNextPrinterChangeNotification\n");
        if (fpFindNextPrinterChangeNotification==NULL) return;

        return;
    }

    bool FreePrinterNotifyInfo(const std::string& pPrinterNotifyInfo) {
        printf("FreePrinterNotifyInfo\n");
        if (fpFreePrinterNotifyInfo==NULL) return false;

        return false;
    }

    void GetDefaultPrinterW(ArgGetDefaultPrinterW& _return, const ArgGetDefaultPrinterW& arg) {
         printf("GetDefaultPrinterW\n");
         _return.ret = false;

        if (fpGetDefaultPrinterW==NULL) return;

        DWORD local_cchBuffer = arg.pcchBuffer;
        std::shared_ptr<std::vector<char>> localBuffer(new std::vector<char>());
        localBuffer->reserve(local_cchBuffer);

        BOOL ret = fpGetDefaultPrinterW(reinterpret_cast<LPWSTR>(localBuffer->data()), &local_cchBuffer);
        _return.pcchBuffer = local_cchBuffer;
        _return.ret = ret;
       
        if (ret) {
            _return.pszBuffer = std::string(reinterpret_cast<LPSTR>(localBuffer->data()), local_cchBuffer);
        }

        return;
    }

    void GetPrinterDataW(std::map<std::string, std::string> & _return, const int64_t hPrinter, const std::string& pValueName, const int32_t nSize) {
        printf("GetPrinterDataW\n");
        if (fpGetPrinterDataW==NULL) return;

        return;
    }

    void GetPrinterDataExW(std::map<std::string, std::string> & _return, const int64_t hPrinter, const std::string& pKeyName, const std::string& pValueName, const int32_t nSize) {
        printf("GetPrinterDataExW\n");
        if (fpGetPrinterDataExW==NULL) return;

        return;
    }

    void GetPrinterW(ArgGetPrinterW& _return, const ArgGetPrinterW& arg) {
        printf("GetPrinterW\n");
        _return.ret = FALSE;
        _return.lasterror = GetLastError();

        if (fpGetPrinterW==NULL) return;

        DWORD localpcbNeeded = 0;
        std::shared_ptr<std::vector<char>> localBuffer(new std::vector<char>());
        localBuffer->reserve(arg.cbBuf);

        BOOL ret = fpGetPrinterW((HANDLE)arg.hPrinter,
                        arg.Level,
                        (arg.cbBuf>0?reinterpret_cast<LPBYTE>(localBuffer->data()):NULL),
                        arg.cbBuf,
                        &localpcbNeeded
                        );

        _return.pcbNeeded = localpcbNeeded;
        _return.ret = ret;

        if (ret) {
            _return.pPrinter = THRIFT_B_TO_STRING((arg.cbBuf>0?reinterpret_cast<LPBYTE>(localBuffer->data()):NULL), arg.cbBuf);

            switch(arg.Level){
            case 2:
                {
                 PPRINTER_INFO_2 info = (PPRINTER_INFO_2) localBuffer->data();
                _return.int32Args["pServerName"] = RP_GET_OFFSET(info, info->pServerName);
                _return.int32Args["pPrinterName"] = RP_GET_OFFSET(info, info->pPrinterName);
                _return.int32Args["pShareName"] = RP_GET_OFFSET(info, info->pShareName);
                _return.int32Args["pPortName"] = RP_GET_OFFSET(info, info->pPortName);
                _return.int32Args["pDriverName"] = RP_GET_OFFSET(info, info->pDriverName);
                _return.int32Args["pComment"] = RP_GET_OFFSET(info, info->pComment);
                _return.int32Args["pLocation"] = RP_GET_OFFSET(info, info->pLocation);
                _return.int32Args["pDevMode"] = RP_GET_OFFSET(info, info->pDevMode);
                _return.int32Args["pSepFile"] = RP_GET_OFFSET(info, info->pSepFile);
                _return.int32Args["pPrintProcessor"] = RP_GET_OFFSET(info, info->pPrintProcessor);
                _return.int32Args["pDatatype"] = RP_GET_OFFSET(info, info->pDatatype);
                _return.int32Args["pParameters"] = RP_GET_OFFSET(info, info->pParameters);
                break;
                }
            default:
                _return.ret = FALSE;
            }
        }

        _return.lasterror = GetLastError();
        return;
    }

    int64_t GetSpoolFileHandle(const int64_t hPrinter) {
        printf("GetSpoolFileHandle\n");
        if (fpGetSpoolFileHandle==NULL) return NULL;

        return NULL;
    }

    bool IsValidDevmodeW(const std::string& pDevmode, const int32_t DevmodeSize) {
        printf("IsValidDevmodeW\n");
        if (fpIsValidDevmodeW==NULL) return false;

        return false;
    }

    void OpenPrinter2W(std::map<std::string, int64_t> & _return, const std::string& pPrinterName, const bool pDefaultExist, const std::string& pDatatype, const std::string& pDevMode, const int32_t DesiredAccess, const std::string& pOptions) {
        printf("OpenPrinter2W\n");

        _return["return"] = false;
        if (fpOpenPrinter2W==NULL) return;

        HANDLE localPrinter;
        PRINTER_DEFAULTSW localDefault; 
        LPPRINTER_DEFAULTSW pLocalDefault; 
        int64_t localPrinter64 = 0L;

        if (pDefaultExist) {
            localDefault.pDatatype = (LPWSTR) pDatatype.c_str();
            localDefault.pDevMode = (LPDEVMODEW) pDevMode.c_str();
            localDefault.DesiredAccess = DesiredAccess;
            pLocalDefault = &localDefault;
        }
        else {
            pLocalDefault = NULL;
        }

        BOOL ret = fpOpenPrinter2W((LPWSTR)pPrinterName.c_str(), &localPrinter, pLocalDefault, NULL);
        if (!ret) return;

        localPrinter64 = (int64_t) localPrinter;
        _return["return"] = true;
        _return["phPrinter"] = localPrinter64;

        printf("localPrinter=%x\n", localPrinter);
        return;
    }

    void OpenPrinter2A(std::map<std::string, int64_t> & _return, const std::string& pPrinterName, const bool pDefaultExist, const std::string& pDatatype, const std::string& pDevMode, const int32_t DesiredAccess, const std::string& pOptions) {
        printf("OpenPrinter2A\n");
        return;
    }

    




    //
    // Not a spooler, special code for samsung printers
    //

    int32_t OpenUsbPort(const int32_t dwModel) {
        printf("OpenUsbPort\n");
        if (fpOpenUsbPort==NULL) return 0;
        return fpOpenUsbPort(dwModel);
    }

    int32_t CloseUsbPort() {
        printf("CloseUsbPort\n");
        if (fpCloseUsbPort==NULL) return 0;
        return fpCloseUsbPort();
    }

    int32_t WriteUSB(const std::string& pBuffer, const int32_t nNumberOfBytesToWrite) {
        printf("WriteUSB\n");
        if (fpWriteUSB==NULL) return 0;
        return fpWriteUSB(pBuffer.c_str(), nNumberOfBytesToWrite);
    }

    int32_t ReadUSB(const std::string& pBuffer, const int32_t nNumberOfByteToRead) {
        printf("ReadUSB\n");
        if (fpReadUSB==NULL) return 0;
        return fpReadUSB(pBuffer.c_str(), nNumberOfByteToRead);
    }

    int32_t PrintBitmap(const std::string& pbmpDir, const std::string& data) {
        printf("PrintBitmap\n");
        if (fpPrintBitmap==NULL) return 0;

        int32_t ret = 0;
        if (data.size()==0) {
            ret = 0;
        }
        else {
            std::string temp_path;
            if (!getTempPath(temp_path)) return ret;

            if (!write_to_file(std::string(temp_path), data)) return ret;
            ret = fpPrintBitmap(temp_path.c_str());
            DeleteFileA(temp_path.c_str());
        }

        return ret;
    }

    int32_t Print1DBarcode(const int32_t nCodeType, const int32_t nWidth, const int32_t nHeight, const int32_t nHRI, const std::string& pBuffer) {
        printf("Print1DBarcode\n");
        if (fpPrint1DBarcode==NULL) return 0;
        return fpPrint1DBarcode(nCodeType, nWidth, nHeight, nHRI, pBuffer.c_str());
    }

    int32_t PrintPDF417(const int32_t nColumns, const int32_t nRows, const int32_t nWidth, const int32_t nHeight,
                        const int32_t nECLevel, const int32_t nModule, const std::string& pBuffer, const std::string& data) {

        printf("PrintPDF417\n");
        if (fpPrintPDF417==NULL) return 0;

        int32_t ret = 0;
        if (data.size()==0) {
            ret = 0;
        }
        else {
            std::string temp_path;
            if (!getTempPath(temp_path)) return ret;

            if (!write_to_file(std::string(temp_path), data)) return ret;
            ret = fpPrintPDF417(nColumns, nRows, nWidth, nHeight, nECLevel, nModule, temp_path.c_str());
            DeleteFileA(temp_path.c_str());
        }

        return ret;
    }

    int32_t PrintQRCode(const int32_t nModule, const int32_t nSize, const int32_t nECLevel, const std::string& pBuffer) {
        printf("PrintQRCode\n");
        if (fpPrintQRCode==NULL) return 0;
        return fpPrintQRCode(nModule, nSize, nECLevel, pBuffer.c_str());
    }

private:
    HMODULE _hbxlpdir;
    HMODULE _hwinspool;
    int (WINAPI *fpOpenUsbPort)(int);
    int (WINAPI *fpCloseUsbPort)();
    int (WINAPI *fpWriteUSB)(const char*, int);
    int (WINAPI *fpReadUSB)(const char*, int);
    int (WINAPI *fpPrintBitmap)(const char*);
    int (WINAPI *fpPrint1DBarcode)(int,int,int,int,const char*);
    int (WINAPI *fpPrintPDF417)(int,int,int,int,int,int,const char*);
    int (WINAPI *fpPrintQRCode)(int,int,int,const char*);

    BOOL (WINAPI *fpOpenPrinterA)(LPSTR pPrinterName, LPHANDLE phPrinter, LPPRINTER_DEFAULTSA pDefault);
    BOOL (WINAPI *fpOpenPrinterW)(LPWSTR pPrinterName, LPHANDLE phPrinter, LPPRINTER_DEFAULTSW pDefault);
    BOOL (WINAPI *fpStartPagePrinter)(HANDLE hPrinter);
    DWORD (WINAPI *fpStartDocPrinterW)(HANDLE hPrinter, DWORD  Level, LPBYTE pDocInfo);
    BOOL (WINAPI *fpWritePrinter)(HANDLE hPrinter, LPVOID pBuf, DWORD cbBuf, LPDWORD pcWritten);
    BOOL (WINAPI *fpEndPagePrinter)(HANDLE hPrinter);
    BOOL (WINAPI *fpEndDocPrinter)(HANDLE hPrinter);
    BOOL (WINAPI *fpClosePrinter)(HANDLE hPrinter);

    BOOL (WINAPI *fpCloseSpoolFileHandle)(HANDLE hPrinter, HANDLE hSpoolFile);
    HANDLE (WINAPI *fpCommitSpoolData)(HANDLE hPrinter, HANDLE hSpoolFile, DWORD cbCommit);
    HRESULT (WINAPI *fpDocumentEvent)(HANDLE hPrinter, HDC hdc, INT iEsc, ULONG cbIn, PVOID pvIn, ULONG cbOut, PVOID pvOut);
    LONG (WINAPI *fpDocumentPropertiesW)(HWND hWnd, HANDLE hPrinter, LPWSTR pDeviceName, PDEVMODEW pDevModeOutput, PDEVMODEW pDevModeInput, DWORD fMode);
    BOOL (WINAPI *fpEnumFormsW)(HANDLE hPrinter, DWORD Level, LPBYTE  pForm, DWORD cbBuf, LPDWORD pcbNeeded, LPDWORD pcReturned);
    BOOL (WINAPI *fpEnumPrintersW)(DWORD Flags, LPWSTR Name,DWORD Level, LPBYTE pPrinterEnum, DWORD cbBuf, LPDWORD pcbNeeded, LPDWORD pcReturned);
    BOOL (WINAPI *fpFindClosePrinterChangeNotification)(HANDLE hChange);
    HANDLE (WINAPI *fpFindFirstPrinterChangeNotification)(HANDLE hPrinter, DWORD fdwFilter, DWORD fdwOptions, LPVOID pPrinterNotifyOptions);
    BOOL (WINAPI *fpFindNextPrinterChangeNotification)(HANDLE hChange,PDWORD pdwChange,LPVOID pPrinterNotifyOptions,LPVOID *ppPrinterNotifyInfo);
    BOOL (WINAPI *fpFreePrinterNotifyInfo)(PPRINTER_NOTIFY_INFO pPrinterNotifyInfo);
    BOOL (WINAPI *fpGetDefaultPrinterW)(LPWSTR pszBuffer, LPDWORD pcchBuffer);
    DWORD (WINAPI *fpGetPrinterDataW)(HANDLE hPrinter, LPWSTR  pValueName, LPDWORD pType, LPBYTE pData, DWORD nSize, LPDWORD pcbNeeded);
    DWORD (WINAPI *fpGetPrinterDataExW)(HANDLE hPrinter,LPCWSTR pKeyName, LPCWSTR pValueName,LPDWORD pType, LPBYTE  pData, DWORD nSize, LPDWORD pcbNeeded);
    BOOL (WINAPI *fpGetPrinterW)(HANDLE hPrinter, DWORD Level, LPBYTE pPrinter, DWORD cbBuf, LPDWORD pcbNeeded);
    HANDLE (WINAPI *fpGetSpoolFileHandle)(HANDLE hPrinter);
    BOOL (WINAPI *fpIsValidDevmodeW)(PDEVMODEW pDevmode, size_t DevmodeSize);
    BOOL (WINAPI *fpOpenPrinter2W)(LPCWSTR pPrinterName, LPHANDLE phPrinter, LPPRINTER_DEFAULTSW pDefault, /*PPRINTER_OPTIONS*/ PVOID pOptions);
    BOOL (WINAPI *fpOpenPrinter2A)(LPCSTR pPrinterName, LPHANDLE phPrinter, LPPRINTER_DEFAULTSA pDefault, /*PPRINTER_OPTIONS*/ PVOID pOptions);


    bool getTempPath(std::string& path) {
        BOOL fSuccess  = FALSE;
        DWORD dwRetVal = 0;
        UINT uRetVal   = 0;
        
        CHAR szTempFileName[MAX_PATH];  
        CHAR lpTempPathBuffer[MAX_PATH];
    
        //  Gets the temp path env string (no guarantee it's a valid path).
        dwRetVal = GetTempPathA(MAX_PATH,          // length of the buffer
                           lpTempPathBuffer); // buffer for path 
        if (dwRetVal > MAX_PATH || (dwRetVal == 0))
        {
            return false;
        }

        //  Generates a temporary file name. 
        uRetVal = GetTempFileNameA(lpTempPathBuffer, // directory for tmp files
                                  "apifwrd",     // temp file name prefix 
                                  0,                // create unique name 
                                  szTempFileName);  // buffer for name 
        if (uRetVal == 0)
        {
            return false;
        }

        path = std::string(szTempFileName);
        return true;
    }

    bool write_to_file(std::string& file_path, const std::string& binary_data) {
        try{
            std::ofstream outfile;
            outfile.open(file_path, std::ios::binary | std::ios::out);
            if (!outfile.is_open()) return false;

            outfile.write(binary_data.c_str(), binary_data.size()); // sizeof can take a type
            outfile.close();
        }
        catch(std::ofstream::failure e) {
            DeleteFileA(file_path.c_str());
            return false;
        }

        return true;
    }

};


#endif //__USER_DEF_SERVER_H