//
// Created by nini on 2/15/17.
//

#ifndef ABACKER_NINI_STRCUTMGR_H
#define ABACKER_NINI_STRCUTMGR_H

#include <iostream>
#include <vector>

#define FEATURE_CONST_STRING        0
#define FEATURE_CUT_BY_CHAR         1
#define FEATURE_CUT_BY_CHARS        1
#define FEATURE_CUT_BY_STRING       0
#define FEATURE_CUT_BY_STRINGS      0

class StrCutMgr {
public:

    enum CUT_TYPE {
        CHAR, CHARS, STRING, STRINGS
    };

    StrCutMgr() : _Str(NULL), _Now(NULL), _Parts(0), _PNow(0) {
    }

#if (FEATURE_CUT_BY_CHAR)

    StrCutMgr(char *_Str, const char _C = ' ', CUT_TYPE _CT = CHAR) : _Str(_Str), _Now(NULL), _Parts(_CutStr(_Str, _C)),
                                                                      _PNow(0) {
    }

#endif

    StrCutMgr(char *_Str, const char *_C, CUT_TYPE _CT = CHARS) : _Str(_Str), _Now(NULL),
                                                                  _Parts(_CutStr(_Str, _C, _CT)),
                                                                  _PNow(0) {
        if (_CT == CHARS) {

        }
#if (FEATURE_CUT_BY_STRING)
        else if (_CT == STRING || _CT == STRINGS) {

        }
#endif
    }


#if (FEATURE_CUT_BY_STRINGS)
    StrCutMgr(char *_Str, const char **_C, unsigned int _Count , CUT_TYPE _CT = STRINGS) {}
#endif

#if (FEATURE_CONST_STRING)
    StrCutMgr(const char *_Str) {}

    StrCutMgr(const char *_Str, const char _C) {}

    StrCutMgr(const char *_Str, const char *_C) {}

    StrCutMgr(const char *_Str, const char **_C, unsigned int _Count) {}
#endif

    char *First() {
        _Now = _Str;
        if (_Parts > 0) {
            for (; _Now == '\0'; ++_Now) {
            }
        }
        return _Now;
    }

    bool hasNext() const {
        return _PNow < _Parts - 1;
    }

    char *Next() {
        bool _Cut = false;
        for (++_Now;; ++_Now) {
            if (*_Now == '\0')_Cut = true;
            else if (_Cut) {
                break;
            }
        }

        ++_PNow;

        return _Now;
    }

#if (FEATURE_CONST_STRING)
    ~StrCutMgr() {
        if (_New && _Str)delete[] _Str;
    }
#endif

    static unsigned int _CutStr(char *_Str, const char _C) {
        unsigned int _Count = 0;

        bool _Cut = false;
        for (char *_Ptr = _Str; *_Ptr != '\0'; ++_Ptr) {
            if (*_Ptr == _C) {
                *_Ptr = '\0';
                if (_Cut) {
                    ++_Count;
                    _Cut = false;
                }
            } else _Cut = true;
        }
        if (_Cut)++_Count;

        return _Count;
    }

    static unsigned int _CutStr(char *_Str, const char *_C, CUT_TYPE _CT = CHARS) {
        unsigned int _Count = 0;
        if (_CT == CHARS) {
            std::vector<const char *> _HashTable[128];

            for (const char *_Ptr = _C; *_Ptr; ++_Ptr) {
                _HashTable[(unsigned int)(*_Ptr) % 128].push_back(_Ptr);
            }

            bool _Cut = false, _Flag;
            for (char *_Ptr = _Str; *_Ptr != '\0'; ++_Ptr) {
                _Flag = false;
                for (std::vector<const char *>::iterator _Iter = _HashTable[(unsigned int)(*_Ptr) % 128].begin();
                     _Iter != _HashTable[(unsigned int)(*_Ptr) % 128].end(); ++_Iter) {
                    if (**_Iter && *_Ptr == *(*_Iter)) {
                        _Flag = true;
                        break;
                    }
                }

                if (_Flag) {
                    *_Ptr = '\0';
                    if (_Cut) {
                        ++_Count;
                        _Cut = false;
                    }
                } else _Cut = true;
            }
            if (_Cut)++_Count;

        } else if (_CT == STRING || _CT == STRINGS) {

        }

        return _Count;
    }

private:
    char *_Str;
    char *_Now;
    unsigned int _Parts;
    unsigned int _PNow;

#if (FEATURE_CONST_STRING)
    bool _New;
#endif
};

#endif //ABACKER_NINI_STRCUTMGR_H
