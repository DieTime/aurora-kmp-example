#ifndef KONAN_LIBSHARED_H
#define KONAN_LIBSHARED_H
#ifdef __cplusplus
extern "C" {
#endif
#ifdef __cplusplus
typedef bool            libshared_KBoolean;
#else
typedef _Bool           libshared_KBoolean;
#endif
typedef unsigned short     libshared_KChar;
typedef signed char        libshared_KByte;
typedef short              libshared_KShort;
typedef int                libshared_KInt;
typedef long long          libshared_KLong;
typedef unsigned char      libshared_KUByte;
typedef unsigned short     libshared_KUShort;
typedef unsigned int       libshared_KUInt;
typedef unsigned long long libshared_KULong;
typedef float              libshared_KFloat;
typedef double             libshared_KDouble;
typedef float __attribute__ ((__vector_size__ (16))) libshared_KVector128;
typedef void*              libshared_KNativePtr;
struct libshared_KType;
typedef struct libshared_KType libshared_KType;

typedef struct {
  libshared_KNativePtr pinned;
} libshared_kref_kotlin_Byte;
typedef struct {
  libshared_KNativePtr pinned;
} libshared_kref_kotlin_Short;
typedef struct {
  libshared_KNativePtr pinned;
} libshared_kref_kotlin_Int;
typedef struct {
  libshared_KNativePtr pinned;
} libshared_kref_kotlin_Long;
typedef struct {
  libshared_KNativePtr pinned;
} libshared_kref_kotlin_Float;
typedef struct {
  libshared_KNativePtr pinned;
} libshared_kref_kotlin_Double;
typedef struct {
  libshared_KNativePtr pinned;
} libshared_kref_kotlin_Char;
typedef struct {
  libshared_KNativePtr pinned;
} libshared_kref_kotlin_Boolean;
typedef struct {
  libshared_KNativePtr pinned;
} libshared_kref_kotlin_Unit;
typedef struct {
  libshared_KNativePtr pinned;
} libshared_kref_kotlin_UByte;
typedef struct {
  libshared_KNativePtr pinned;
} libshared_kref_kotlin_UShort;
typedef struct {
  libshared_KNativePtr pinned;
} libshared_kref_kotlin_UInt;
typedef struct {
  libshared_KNativePtr pinned;
} libshared_kref_kotlin_ULong;
typedef struct {
  libshared_KNativePtr pinned;
} libshared_kref_kotlin_collections_MutableList;
typedef struct {
  libshared_KNativePtr pinned;
} libshared_kref_kotlin_collections_List;
typedef struct {
  libshared_KNativePtr pinned;
} libshared_kref_org_example_aurorakmp_Platform;
typedef struct {
  libshared_KNativePtr pinned;
} libshared_kref_org_example_aurorakmp_AuroraPlatform;
typedef struct {
  libshared_KNativePtr pinned;
} libshared_kref_org_example_aurorakmp_Greeting;


typedef struct {
  /* Service functions. */
  void (*DisposeStablePointer)(libshared_KNativePtr ptr);
  void (*DisposeString)(const char* string);
  libshared_KBoolean (*IsInstance)(libshared_KNativePtr ref, const libshared_KType* type);
  libshared_kref_kotlin_Byte (*createNullableByte)(libshared_KByte);
  libshared_KByte (*getNonNullValueOfByte)(libshared_kref_kotlin_Byte);
  libshared_kref_kotlin_Short (*createNullableShort)(libshared_KShort);
  libshared_KShort (*getNonNullValueOfShort)(libshared_kref_kotlin_Short);
  libshared_kref_kotlin_Int (*createNullableInt)(libshared_KInt);
  libshared_KInt (*getNonNullValueOfInt)(libshared_kref_kotlin_Int);
  libshared_kref_kotlin_Long (*createNullableLong)(libshared_KLong);
  libshared_KLong (*getNonNullValueOfLong)(libshared_kref_kotlin_Long);
  libshared_kref_kotlin_Float (*createNullableFloat)(libshared_KFloat);
  libshared_KFloat (*getNonNullValueOfFloat)(libshared_kref_kotlin_Float);
  libshared_kref_kotlin_Double (*createNullableDouble)(libshared_KDouble);
  libshared_KDouble (*getNonNullValueOfDouble)(libshared_kref_kotlin_Double);
  libshared_kref_kotlin_Char (*createNullableChar)(libshared_KChar);
  libshared_KChar (*getNonNullValueOfChar)(libshared_kref_kotlin_Char);
  libshared_kref_kotlin_Boolean (*createNullableBoolean)(libshared_KBoolean);
  libshared_KBoolean (*getNonNullValueOfBoolean)(libshared_kref_kotlin_Boolean);
  libshared_kref_kotlin_Unit (*createNullableUnit)(void);
  libshared_kref_kotlin_UByte (*createNullableUByte)(libshared_KUByte);
  libshared_KUByte (*getNonNullValueOfUByte)(libshared_kref_kotlin_UByte);
  libshared_kref_kotlin_UShort (*createNullableUShort)(libshared_KUShort);
  libshared_KUShort (*getNonNullValueOfUShort)(libshared_kref_kotlin_UShort);
  libshared_kref_kotlin_UInt (*createNullableUInt)(libshared_KUInt);
  libshared_KUInt (*getNonNullValueOfUInt)(libshared_kref_kotlin_UInt);
  libshared_kref_kotlin_ULong (*createNullableULong)(libshared_KULong);
  libshared_KULong (*getNonNullValueOfULong)(libshared_kref_kotlin_ULong);

  /* User functions. */
  struct {
    struct {
      struct {
        struct {
          struct {
            struct {
              struct {
                void* (*listGetElementByIndex)(void* ptr, libshared_KInt index);
                libshared_KInt (*listGetSize)(void* ptr);
                void (*mutableListAddBoolean)(libshared_kref_kotlin_collections_MutableList l, libshared_KBoolean el);
                void (*mutableListAddByte)(libshared_kref_kotlin_collections_MutableList l, libshared_KByte el);
                void (*mutableListAddChar)(libshared_kref_kotlin_collections_MutableList l, libshared_KChar el);
                void (*mutableListAddClass)(libshared_kref_kotlin_collections_MutableList list, void* ptr);
                void (*mutableListAddDouble)(libshared_kref_kotlin_collections_MutableList l, libshared_KDouble el);
                void (*mutableListAddFloat)(libshared_kref_kotlin_collections_MutableList l, libshared_KFloat el);
                void (*mutableListAddInt)(libshared_kref_kotlin_collections_MutableList l, libshared_KInt el);
                void (*mutableListAddLong)(libshared_kref_kotlin_collections_MutableList l, libshared_KLong el);
                void (*mutableListAddShort)(libshared_kref_kotlin_collections_MutableList l, libshared_KShort el);
                void (*mutableListAddString)(libshared_kref_kotlin_collections_MutableList l, const char* el);
                void (*mutableListAddUByte)(libshared_kref_kotlin_collections_MutableList l, libshared_KUByte el);
                void (*mutableListAddUInt)(libshared_kref_kotlin_collections_MutableList l, libshared_KUInt el);
                void (*mutableListAddULong)(libshared_kref_kotlin_collections_MutableList l, libshared_KULong el);
                void (*mutableListAddUShort)(libshared_kref_kotlin_collections_MutableList l, libshared_KUShort el);
                void (*mutableListAddUnit)(libshared_kref_kotlin_collections_MutableList l);
                libshared_kref_kotlin_collections_MutableList (*mutableListCreateEmpty)();
                libshared_kref_kotlin_collections_List (*mutableListToList)(libshared_kref_kotlin_collections_MutableList mutableList);
              } generated;
            } qtbindings;
          } kmp;
        } auroraos;
      } ru;
      struct {
        struct {
          struct {
            struct {
              libshared_KType* (*_type)(void);
              libshared_kref_org_example_aurorakmp_AuroraPlatform (*AuroraPlatform)();
              const char* (*get_name)(libshared_kref_org_example_aurorakmp_AuroraPlatform thiz);
            } AuroraPlatform;
            struct {
              libshared_KType* (*_type)(void);
              libshared_kref_org_example_aurorakmp_Greeting (*Greeting)();
              const char* (*greet)(libshared_kref_org_example_aurorakmp_Greeting thiz);
            } Greeting;
            struct {
              libshared_KType* (*_type)(void);
              const char* (*get_name)(libshared_kref_org_example_aurorakmp_Platform thiz);
            } Platform;
            libshared_kref_org_example_aurorakmp_Platform (*getPlatform)();
          } aurorakmp;
        } example;
      } org;
    } root;
  } kotlin;
} libshared_ExportedSymbols;
extern libshared_ExportedSymbols* libshared_symbols(void);
#ifdef __cplusplus
}  /* extern "C" */
#endif
#endif  /* KONAN_LIBSHARED_H */
