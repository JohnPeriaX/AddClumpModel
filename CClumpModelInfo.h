//
// Created by JohnPeriaX on 05.17.2025.
//

#pragma once

#include "PedModelInfo.h"
#include "AtomicModelInfo.h"
#include "VehicleModelInfo.h"
#include "game/Core/Store.h"
#include "game/constants.h"

class CModelInfo {
public:
    static constexpr int32_t NUM_CLUMP_MODEL_INFOS = 1000; // จำนวนสูงสุดของโมเดล Clump
    static inline CStore<CClumpModelInfo, NUM_CLUMP_MODEL_INFOS> ms_clumpModelInfoStore; // คลังข้อมูลโมเดล Clump

    static CClumpModelInfo* AddClumpModel(int index); // เพิ่มโมเดล Clump

    // ฟังก์ชันสมาชิก
    static void injectHooks(); // ติดตั้งฮุคต่างๆ

};
