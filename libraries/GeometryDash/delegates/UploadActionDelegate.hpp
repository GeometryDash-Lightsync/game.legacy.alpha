#pragma once

#include <GDLib.h>

class UploadActionDelegate {
public:
    void uploadActionFinished(int p0, int p1);

    void uploadActionFailed(int p0, int p1);
};