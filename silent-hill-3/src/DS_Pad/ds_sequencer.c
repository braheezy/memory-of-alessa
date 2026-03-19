
#include "common.h"
#include "DS_Pad/ds_sequencer.h"

INCLUDE_ASM("asm/nonmatchings/DS_Pad/ds_sequencer", func_0013B520);

void Sequencer_Type_Hispeed(MysterySequenceData *unk, EntryRecord *pER)
{
    DS_Record *pDSR;
    Record_Info *pInfo;

    int Node;
    int Node_Next;
    u_int now_act_lv_i;

    float time;
    float section_0;
    float section_1;

    pInfo = &pER->Info;
    time = pER->Time_Count;

    Node = Node_Current_Search(pInfo, time);
    Node_Next = Node_Next_Search(pInfo, time);

    if ((Node != -1) && (Node_Next != -1))
    {
        pDSR = (DS_Record *)pInfo->pAddress + Node;
        now_act_lv_i = 0;

        if (pDSR->Complement_Enable != 0)
        {
            now_act_lv_i = pDSR->Actuater_LV ? 1 : 0;
        }
        else
        {
            section_0 = pDSR->Time;
            section_1 = section_0 + Sequence_Different_Time_Get(unk);

            if ((section_0 <= time) && (time < section_1))
            {
                now_act_lv_i = pDSR->Actuater_LV ? 1 : 0;
            }
        }

        now_act_lv_i *= pER->Ratio > 0.0f ? 1 : 0;
        unk->data.ActuaterLV[0] += now_act_lv_i;
    }
}

INCLUDE_ASM("asm/nonmatchings/DS_Pad/ds_sequencer", func_0013B840);

INCLUDE_ASM("asm/nonmatchings/DS_Pad/ds_sequencer", func_0013B900);

INCLUDE_ASM("asm/nonmatchings/DS_Pad/ds_sequencer", func_0013BA30);

void func_0013BAC0(QQQ *arg0, unsigned int arg1, float fparg0) { arg0->unk7F4[arg1] = fparg0; }

INCLUDE_ASM("asm/nonmatchings/DS_Pad/ds_sequencer", Sequence_Different_Time_Get);

INCLUDE_ASM("asm/nonmatchings/DS_Pad/ds_sequencer", func_0013BAE0);

INCLUDE_ASM("asm/nonmatchings/DS_Pad/ds_sequencer", func_0013BAF0);

INCLUDE_ASM("asm/nonmatchings/DS_Pad/ds_sequencer", func_0013BB20);

INCLUDE_ASM("asm/nonmatchings/DS_Pad/ds_sequencer", func_0013BB30);

INCLUDE_ASM("asm/nonmatchings/DS_Pad/ds_sequencer", func_0013BB40);

INCLUDE_ASM("asm/nonmatchings/DS_Pad/ds_sequencer", func_0013BB50);

INCLUDE_ASM("asm/nonmatchings/DS_Pad/ds_sequencer", func_0013BB90);

INCLUDE_ASM("asm/nonmatchings/DS_Pad/ds_sequencer", func_0013BBD0);

INCLUDE_ASM("asm/nonmatchings/DS_Pad/ds_sequencer", func_0013BBE0);

INCLUDE_ASM("asm/nonmatchings/DS_Pad/ds_sequencer", func_0013BBF0);

INCLUDE_ASM("asm/nonmatchings/DS_Pad/ds_sequencer", func_0013BC00);

INCLUDE_ASM("asm/nonmatchings/DS_Pad/ds_sequencer", func_0013C110);

INCLUDE_ASM("asm/nonmatchings/DS_Pad/ds_sequencer", func_0013C190);

INCLUDE_ASM("asm/nonmatchings/DS_Pad/ds_sequencer", func_0013C210);

INCLUDE_ASM("asm/nonmatchings/DS_Pad/ds_sequencer", func_0013C250);

INCLUDE_ASM("asm/nonmatchings/DS_Pad/ds_sequencer", func_0013C2A0);

INCLUDE_ASM("asm/nonmatchings/DS_Pad/ds_sequencer", func_0013C2F0);

typedef struct C330Data
{
    int unk0;
    int unk4;
    int unk8;
} C330Data;

int func_0013C330(C330Data *arg0) { return 0x14 - arg0->unk8; }

// https://decomp.me/scratch/BWTJg
INCLUDE_ASM("asm/nonmatchings/DS_Pad/ds_sequencer", func_0013C340);

// https://decomp.me/scratch/rTbji
INCLUDE_ASM("asm/nonmatchings/DS_Pad/ds_sequencer", func_0013C5F0);

typedef struct C6B0Data
{
    char pad0[0x10];
    int unk10;
    int unk14;
} C6B0Data;

int func_0013C6B0(C6B0Data *arg0)
{
    int ret;

    ret = 0;
    if (arg0 == 0)
    {
        ret++;
    }
    if (arg0->unk10 != 1)
    {
        ret++;
    }
    if (arg0->unk14 == 0)
    {
        ret++;
    }
    return ret;
}

// https://decomp.me/scratch/p0Zob
INCLUDE_ASM("asm/nonmatchings/DS_Pad/ds_sequencer", func_0013C6F0);

// https://decomp.me/scratch/2Jx5G
INCLUDE_ASM("asm/nonmatchings/DS_Pad/ds_sequencer", func_0013C790);

static int Node_Next_Search(Record_Info *pInfo, float Time)
{
    u_int node_num = pInfo->pObject->DataNode_num;
    DS_Record *pDSR = pInfo->pAddress;

    int result = -1;
    u_int i;
    for (i = 0; i < node_num; i++, pDSR++)
    {
        if (Time < pDSR->Time)
        {
            result = i;
            break;
        }
    }

    return result;
}

static int Node_Current_Search(Record_Info *pInfo /* r2 */, float Time /* r29+0x10 */)
{
    signed int result = -1;                         // r7
    signed int num = Node_Next_Search(pInfo, Time); // r2

    if (num > 0)
    {
        result = num - 1;
    }

    return result;
}

typedef struct C8C0Node
{
    float threshold;       /* 0x0 */
    int unk4;              /* 0x4 */
    int value;             /* 0x8 */
    struct C8C0Node *next; /* 0xC */
} C8C0Node;

typedef struct C8C0Data
{
    int unk0;
    C8C0Node *head; /* 0x4 */
} C8C0Data;

int func_0013C8C0(C8C0Data *arg0, float fparg0)
{
    C8C0Node *node;
    int ret;

    ret = 0;
    node = arg0->head;
    if (node != 0)
    {
        do
        {
            if (fparg0 < node->threshold)
            {
                ret = node->value;
                break;
            }
            node = node->next;
        } while (node != 0);
    }
    return ret;
}
// https://decomp.me/scratch/GwV5L
INCLUDE_ASM("asm/nonmatchings/DS_Pad/ds_sequencer", func_0013C900);

void func_0013CA30(void *arg0, int arg1, int arg2, float arg3)
{
    CA30Entry sp10;

    sp10 = D_0046D1C0;
    sp10.unk0 = arg1;
    sp10.unk4 = arg2;
    sp10.unk8 = arg3;
    func_0013CAA0(arg0, &sp10);
}

void func_0013CA80(CAX0Data *arg0)
{
    arg0->unkC = 100;
    func_0013CA90(arg0);
}

void func_0013CA90(CAX0Data *arg0)
{
    arg0->unk4 = 0;
    arg0->unk0 = 0;
    arg0->unk8 = 0;
}

// https://decomp.me/scratch/tu9lr
INCLUDE_ASM("asm/nonmatchings/DS_Pad/ds_sequencer", func_0013CAA0);

// https://decomp.me/scratch/4SytZ
INCLUDE_ASM("asm/nonmatchings/DS_Pad/ds_sequencer", func_0013CB20);

int func_0013CBA0(void *arg0, void *arg1)
{
    int ret;
    int tmp_count0;
    void *tmp_ptr;
    int count;
    int tmp_count1;
    int sp50[64];

    count = *(int *)((char *)arg1 + 0x14);
    ret = func_0013C340(tmp_ptr, sp50, arg1);
    if (ret != 0)
    {
        tmp_count1 = (tmp_count0 = count);
        count--;
        if (tmp_count1 != 0)
        {
            do
            {
                func_0013CA30((char *)arg0 + 0x334, *(int *)((char *)sp50 + (count * 4)), 5, 0.0f);
            } while (count-- != 0);
        }
    }
    return ret;
}

void func_0013CC30(QQQ *arg0) { func_0013BC00(&arg0->bc00); }

// https://decomp.me/scratch/cwkGv
INCLUDE_ASM("asm/nonmatchings/DS_Pad/ds_sequencer", func_0013CC40);

void func_0013CCC0(QQQ *arg0)
{
    func_0013BAE0(arg0, shGetDT());
    arg0->unk804 = 0;
    arg0->unk808 = 0;
    arg0->unk80C = 0;
    arg0->unk810 = 0;
    func_0013B520();
    func_0013C900(arg0);
}
