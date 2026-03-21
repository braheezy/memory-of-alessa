#include "common.h"

typedef struct DS_Object_Info
{
    // total size: 0x10
    u_int Offset;       // offset 0x0, size 0x4
    u_int DataNode_num; // offset 0x4, size 0x4
    u_short Type;       // offset 0x8, size 0x2
    u_short ID;         // offset 0xA, size 0x2
    u_short Attribute;  // offset 0xC, size 0x2
    u_short Permission; // offset 0xE, size 0x2
} DS_Object_Info;

typedef struct DS_Record
{
    // total size: 0x8
    float Time;               // offset 0x0, size 0x4
    u_char Actuater_LV;       // offset 0x4, size 0x1
    u_char Complement_Enable; // offset 0x5, size 0x1
    u_char Reserved[2];       // offset 0x6, size 0x2
} DS_Record;

typedef struct Record_Info
{
    // total size: 0x8
    struct DS_Object_Info *pObject; // offset 0x0, size 0x4
    void *pAddress;                 // offset 0x4, size 0x4
} Record_Info;

typedef struct EntryRecord
{
    // total size: 0x24
    u_short Enable;        // offset 0x0, size 0x2
    u_short Controller_ID; // offset 0x2, size 0x2
    u_int Handle;          // offset 0x4, size 0x4
    u_int Group_Handle;    // offset 0x8, size 0x4
    u_int Condition;       // offset 0xC, size 0x4
    float unk_10;
    float Time_Count;        // offset 0x14, size 0x4
    float Time_Max;          // offset 0x18, size 0x4
    float Ratio;             // offset 0x1C, size 0x4
    struct Record_Info Info; // offset 0x20, size 0x8
} EntryRecord;

typedef struct Sequencer_Data
{
    // total size: 0x10
    float ActuaterLV[4]; // offset 0x0, size 0x10
} Sequencer_Data;

typedef struct MysterySequenceData
{
    int unk[513];
    Sequencer_Data data;
} MysterySequenceData;

extern int Node_Current_Search(struct Record_Info *pInfo /* r2 */, float Time /* r29+0x10 */);
extern int Node_Next_Search(struct Record_Info *pInfo /* r2 */, float Time /* r29 */);
extern float Sequence_Different_Time_Get(MysterySequenceData *unk);

extern void TotalActuaterLV_Keeper(u_int ControllerID /* r2 */, u_int ActuaterType /* r2 */,
                                   float ActuaterLV /* r29 */);
void Sequencer_Type_Hispeed(MysterySequenceData *unk, EntryRecord *pER);

typedef struct BC00Data
{
    char unk[0x7EC];
} BC00Data;

typedef struct QQQ
{
    int unk0;
    int unk4;
    BC00Data bc00;
    float unk7F4[4];
    int unk804;
    int unk808;
    int unk80C;
    int unk810;
} QQQ;

typedef struct CAX0Data
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
} CAX0Data;

void func_0013B520();
void func_0013BAE0(void *, float);
void func_0013C900(void *);
int func_0013C340(void *arg0, int *sp50, void *arg2);
void func_0013CA30(void *arg0, int arg1, int arg2, float arg3);
void func_0013BC00(BC00Data *);
void func_0013CA90(CAX0Data *arg0);
float shGetDT();

typedef struct CA30Entry
{
    unsigned int unk0;
    unsigned int unk4;
    float unk8;
} CA30Entry;

int func_0013CAA0(void *arg0, CA30Entry *arg1);
extern CA30Entry D_0046D1C0;
