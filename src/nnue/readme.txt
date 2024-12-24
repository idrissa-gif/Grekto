This NNUE probing code is written by Daniel Shawul
and was downloaded from https://github.com/dshawul/nnue-probe

Minor changes I made to build it with GreKo:

- Renamed Posision struct to NNUEPosition to fix collision of names
- Removed DLLExport and _CDECL function modifiers for static link
- Turned off duplicated _CRT_SECURE_NO_WARNINGS definition in misc.h
- modified int32_t tmp[outDims] declaration for MSVC build without intrinsics