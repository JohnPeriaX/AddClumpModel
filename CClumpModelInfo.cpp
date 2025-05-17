#include "ModelInfo.h"
#include "../vendor/armhook/patch.h"
#include "log.h"

// ฟังก์ชันเพิ่มโมเดล Clump
CClumpModelInfo* CModelInfo::AddClumpModel(int index)
{
    CClumpModelInfo& pInfo = ms_clumpModelInfoStore.AddItem();

    reinterpret_cast<void(__thiscall*)(CClumpModelInfo*)>(
            g_libGTASA + (VER_x32 ? 0x003860A4 + 1 : 0x45CB60)
    )(&pInfo);

    pInfo.vtable = reinterpret_cast<uintptr_t>(reinterpret_cast<void *>(
            g_libGTASA + (VER_x32 ? 0x00667524 : 0x82F0A8)
    ));

    reinterpret_cast<void(__thiscall*)(CClumpModelInfo*)>(
            *reinterpret_cast<uintptr_t*>(
                    reinterpret_cast<uintptr_t>(pInfo.vtable) +
                    (VER_x32 ? 0x1C : 0x1C * 2)
            )
    )(&pInfo);

    SetModelInfo(index, &pInfo);
    return &pInfo;
}

// ฟังก์ชันติดตั้ง Hook
void CModelInfo::injectHooks()
{
    CHook::Redirect(
            "_ZN10CModelInfo13AddClumpModelEi",
            &CModelInfo::AddClumpModel
    );
}