// Copyright 2008-2011 Zhang Yun Gui, rhcad@hotmail.com
// http://sourceforge.net/projects/x3c/

#ifndef _X3_UTILITY_TEXTUTIL_H
#define _X3_UTILITY_TEXTUTIL_H

#include <Ix_StringConvert.h>
#include <Ix_TextFileUtil.h>

class Cx_TextUtil
    : public Ix_StringConvert
    , public Ix_TextFileUtil
{
protected:
    Cx_TextUtil() {}
    virtual ~Cx_TextUtil() {}

private:
    // From Ix_TextFileUtil
    //
    virtual bool ReadTextFile(std::wstring& content, 
        const std::wstring& filename, 
        ULONG limitMB = 16, int codepage = 0);
    virtual bool SaveTextFile(const std::wstring& content, 
        const std::wstring& filename, 
        bool utf16 = true, int codepage = 0);
    virtual bool SaveTextFile(const std::string& content, 
        const std::wstring& filename, 
        bool utf16 = true, int codepage = 0);
    virtual bool IsUTF16File(const std::wstring& filename, bool& utf16);
    virtual bool IsUTF8File(const std::wstring& filename, bool& utf8);
    virtual bool UnicodeToAnsi(const std::wstring& filename, int codepage = 0);
    virtual bool AnsiToUnicode(const std::wstring& filename, int codepage = 0);
    virtual long GetLineCount(const std::wstring& text);
    virtual std::wstring GetLine(const std::wstring& text, 
        long line, const wchar_t** nextLine = NULL);
    virtual bool IsSpaceLine(const std::wstring& text);

    // From Ix_StringConvert
    //
    virtual bool TrimSpace(std::wstring& text, const wchar_t* targets);
    virtual bool TrimLeft(std::wstring& text, const wchar_t* targets);
    virtual bool TrimRight(std::wstring& text, const wchar_t* targets);
    virtual bool RemoveInvalidChars(std::wstring& text, const wchar_t* targets);
    virtual bool ReplaceAll(std::wstring& text, 
        const std::wstring& match, 
        const std::wstring& newtext);
    virtual bool ReplaceChar(std::wstring& text, 
        const std::wstring& match, 
        const std::wstring& chars);
    virtual bool ToDBC(std::wstring& text, bool punct = false);
    virtual std::string ToAnsi(const std::wstring& text, int codepage = 0);
    virtual std::wstring ToUnicode(const std::string& text, int codepage = 0);

private:
    DWORD GetHeadBytes(const std::wstring& wstrFileName, BYTE buf[5]);
    bool GetFileContent(std::wstring& content, BYTE* buf, long size, int codepage);
    bool ReadTextFile(BYTE head[5], std::wstring& content, 
        const std::wstring& wstrFileName, 
        ULONG nLenLimitMB, int codepage);
};

#endif // _X3_UTILITY_TEXTUTIL_H
