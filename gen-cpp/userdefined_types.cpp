/**
 * Autogenerated by Thrift Compiler (0.9.2)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "userdefined_types.h"

#include <algorithm>
#include <ostream>

#include <thrift/TToString.h>

namespace userdefined {


ArgGetDefaultPrinterW::~ArgGetDefaultPrinterW() throw() {
}


void ArgGetDefaultPrinterW::__set_ret(const bool val) {
  this->ret = val;
}

void ArgGetDefaultPrinterW::__set_pszBuffer(const std::string& val) {
  this->pszBuffer = val;
}

void ArgGetDefaultPrinterW::__set_pcchBuffer(const int32_t val) {
  this->pcchBuffer = val;
}

const char* ArgGetDefaultPrinterW::ascii_fingerprint = "F130B12EADB6306680A7C9A72370EAE1";
const uint8_t ArgGetDefaultPrinterW::binary_fingerprint[16] = {0xF1,0x30,0xB1,0x2E,0xAD,0xB6,0x30,0x66,0x80,0xA7,0xC9,0xA7,0x23,0x70,0xEA,0xE1};

uint32_t ArgGetDefaultPrinterW::read(::apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool(this->ret);
          this->__isset.ret = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readBinary(this->pszBuffer);
          this->__isset.pszBuffer = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->pcchBuffer);
          this->__isset.pcchBuffer = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t ArgGetDefaultPrinterW::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  oprot->incrementRecursionDepth();
  xfer += oprot->writeStructBegin("ArgGetDefaultPrinterW");

  xfer += oprot->writeFieldBegin("ret", ::apache::thrift::protocol::T_BOOL, 1);
  xfer += oprot->writeBool(this->ret);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("pszBuffer", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeBinary(this->pszBuffer);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("pcchBuffer", ::apache::thrift::protocol::T_I32, 3);
  xfer += oprot->writeI32(this->pcchBuffer);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  oprot->decrementRecursionDepth();
  return xfer;
}

void swap(ArgGetDefaultPrinterW &a, ArgGetDefaultPrinterW &b) {
  using ::std::swap;
  swap(a.ret, b.ret);
  swap(a.pszBuffer, b.pszBuffer);
  swap(a.pcchBuffer, b.pcchBuffer);
  swap(a.__isset, b.__isset);
}

ArgGetDefaultPrinterW::ArgGetDefaultPrinterW(const ArgGetDefaultPrinterW& other0) {
  ret = other0.ret;
  pszBuffer = other0.pszBuffer;
  pcchBuffer = other0.pcchBuffer;
  __isset = other0.__isset;
}
ArgGetDefaultPrinterW& ArgGetDefaultPrinterW::operator=(const ArgGetDefaultPrinterW& other1) {
  ret = other1.ret;
  pszBuffer = other1.pszBuffer;
  pcchBuffer = other1.pcchBuffer;
  __isset = other1.__isset;
  return *this;
}
std::ostream& operator<<(std::ostream& out, const ArgGetDefaultPrinterW& obj) {
  using apache::thrift::to_string;
  out << "ArgGetDefaultPrinterW(";
  out << "ret=" << to_string(obj.ret);
  out << ", " << "pszBuffer=" << to_string(obj.pszBuffer);
  out << ", " << "pcchBuffer=" << to_string(obj.pcchBuffer);
  out << ")";
  return out;
}


ArgEnumPrintersW::~ArgEnumPrintersW() throw() {
}


void ArgEnumPrintersW::__set_ret(const bool val) {
  this->ret = val;
}

void ArgEnumPrintersW::__set_Flags(const int32_t val) {
  this->Flags = val;
}

void ArgEnumPrintersW::__set_Name(const std::string& val) {
  this->Name = val;
}

void ArgEnumPrintersW::__set_Level(const int32_t val) {
  this->Level = val;
}

void ArgEnumPrintersW::__set_pPrinterEnum(const std::string& val) {
  this->pPrinterEnum = val;
}

void ArgEnumPrintersW::__set_cbBuf(const int32_t val) {
  this->cbBuf = val;
}

void ArgEnumPrintersW::__set_pcbNeeded(const int32_t val) {
  this->pcbNeeded = val;
}

void ArgEnumPrintersW::__set_pcReturned(const int32_t val) {
  this->pcReturned = val;
}

void ArgEnumPrintersW::__set_int32PrinterEnum(const std::map<std::string, int32_t> & val) {
  this->int32PrinterEnum = val;
}

const char* ArgEnumPrintersW::ascii_fingerprint = "DE518725CC5D9695526E35BF6A80A175";
const uint8_t ArgEnumPrintersW::binary_fingerprint[16] = {0xDE,0x51,0x87,0x25,0xCC,0x5D,0x96,0x95,0x52,0x6E,0x35,0xBF,0x6A,0x80,0xA1,0x75};

uint32_t ArgEnumPrintersW::read(::apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool(this->ret);
          this->__isset.ret = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->Flags);
          this->__isset.Flags = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readBinary(this->Name);
          this->__isset.Name = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->Level);
          this->__isset.Level = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readBinary(this->pPrinterEnum);
          this->__isset.pPrinterEnum = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 6:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->cbBuf);
          this->__isset.cbBuf = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 7:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->pcbNeeded);
          this->__isset.pcbNeeded = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 8:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->pcReturned);
          this->__isset.pcReturned = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 10:
        if (ftype == ::apache::thrift::protocol::T_MAP) {
          {
            this->int32PrinterEnum.clear();
            uint32_t _size2;
            ::apache::thrift::protocol::TType _ktype3;
            ::apache::thrift::protocol::TType _vtype4;
            xfer += iprot->readMapBegin(_ktype3, _vtype4, _size2);
            uint32_t _i6;
            for (_i6 = 0; _i6 < _size2; ++_i6)
            {
              std::string _key7;
              xfer += iprot->readString(_key7);
              int32_t& _val8 = this->int32PrinterEnum[_key7];
              xfer += iprot->readI32(_val8);
            }
            xfer += iprot->readMapEnd();
          }
          this->__isset.int32PrinterEnum = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t ArgEnumPrintersW::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  oprot->incrementRecursionDepth();
  xfer += oprot->writeStructBegin("ArgEnumPrintersW");

  xfer += oprot->writeFieldBegin("ret", ::apache::thrift::protocol::T_BOOL, 1);
  xfer += oprot->writeBool(this->ret);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("Flags", ::apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32(this->Flags);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("Name", ::apache::thrift::protocol::T_STRING, 3);
  xfer += oprot->writeBinary(this->Name);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("Level", ::apache::thrift::protocol::T_I32, 4);
  xfer += oprot->writeI32(this->Level);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("pPrinterEnum", ::apache::thrift::protocol::T_STRING, 5);
  xfer += oprot->writeBinary(this->pPrinterEnum);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("cbBuf", ::apache::thrift::protocol::T_I32, 6);
  xfer += oprot->writeI32(this->cbBuf);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("pcbNeeded", ::apache::thrift::protocol::T_I32, 7);
  xfer += oprot->writeI32(this->pcbNeeded);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("pcReturned", ::apache::thrift::protocol::T_I32, 8);
  xfer += oprot->writeI32(this->pcReturned);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("int32PrinterEnum", ::apache::thrift::protocol::T_MAP, 10);
  {
    xfer += oprot->writeMapBegin(::apache::thrift::protocol::T_STRING, ::apache::thrift::protocol::T_I32, static_cast<uint32_t>(this->int32PrinterEnum.size()));
    std::map<std::string, int32_t> ::const_iterator _iter9;
    for (_iter9 = this->int32PrinterEnum.begin(); _iter9 != this->int32PrinterEnum.end(); ++_iter9)
    {
      xfer += oprot->writeString(_iter9->first);
      xfer += oprot->writeI32(_iter9->second);
    }
    xfer += oprot->writeMapEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  oprot->decrementRecursionDepth();
  return xfer;
}

void swap(ArgEnumPrintersW &a, ArgEnumPrintersW &b) {
  using ::std::swap;
  swap(a.ret, b.ret);
  swap(a.Flags, b.Flags);
  swap(a.Name, b.Name);
  swap(a.Level, b.Level);
  swap(a.pPrinterEnum, b.pPrinterEnum);
  swap(a.cbBuf, b.cbBuf);
  swap(a.pcbNeeded, b.pcbNeeded);
  swap(a.pcReturned, b.pcReturned);
  swap(a.int32PrinterEnum, b.int32PrinterEnum);
  swap(a.__isset, b.__isset);
}

ArgEnumPrintersW::ArgEnumPrintersW(const ArgEnumPrintersW& other10) {
  ret = other10.ret;
  Flags = other10.Flags;
  Name = other10.Name;
  Level = other10.Level;
  pPrinterEnum = other10.pPrinterEnum;
  cbBuf = other10.cbBuf;
  pcbNeeded = other10.pcbNeeded;
  pcReturned = other10.pcReturned;
  int32PrinterEnum = other10.int32PrinterEnum;
  __isset = other10.__isset;
}
ArgEnumPrintersW& ArgEnumPrintersW::operator=(const ArgEnumPrintersW& other11) {
  ret = other11.ret;
  Flags = other11.Flags;
  Name = other11.Name;
  Level = other11.Level;
  pPrinterEnum = other11.pPrinterEnum;
  cbBuf = other11.cbBuf;
  pcbNeeded = other11.pcbNeeded;
  pcReturned = other11.pcReturned;
  int32PrinterEnum = other11.int32PrinterEnum;
  __isset = other11.__isset;
  return *this;
}
std::ostream& operator<<(std::ostream& out, const ArgEnumPrintersW& obj) {
  using apache::thrift::to_string;
  out << "ArgEnumPrintersW(";
  out << "ret=" << to_string(obj.ret);
  out << ", " << "Flags=" << to_string(obj.Flags);
  out << ", " << "Name=" << to_string(obj.Name);
  out << ", " << "Level=" << to_string(obj.Level);
  out << ", " << "pPrinterEnum=" << to_string(obj.pPrinterEnum);
  out << ", " << "cbBuf=" << to_string(obj.cbBuf);
  out << ", " << "pcbNeeded=" << to_string(obj.pcbNeeded);
  out << ", " << "pcReturned=" << to_string(obj.pcReturned);
  out << ", " << "int32PrinterEnum=" << to_string(obj.int32PrinterEnum);
  out << ")";
  return out;
}

} // namespace
