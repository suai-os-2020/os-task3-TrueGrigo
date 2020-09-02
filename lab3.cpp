/*
ОС ЛР3
Вариант 19
Граф № 19
Асинхронные потоки dhikm
Синхронизированные потоки bcdf
*/

#include <iostream>
#include <windows.h>
#include "lab3.h"

#define THREADS_COUNT 13
// Количество букв для одного цикла потока
#define LETTERS_COUNT 3
// Номер графа
#define GRAPH_ID 19

DWORD ThreadID;
// Массив с идентификаторами ротоков
HANDLE thread[THREADS_COUNT];
// Мьютекс
HANDLE block;
// Семафоры
HANDLE smphr_b, smphr_c, smphr_d, smphr_f, smphr_section_done, smphr_next_section;

unsigned int lab3_thread_graph_id()
{
    return GRAPH_ID;
}

const char *lab3_unsynchronized_threads()
{
    return "dhikm";
}

const char *lab3_sequential_threads()
{
    return "bcdf";
}

DWORD WINAPI thread_a(LPVOID lpParam)
{
    UNREFERENCED_PARAMETER(lpParam);

    for (int i = 0; i < LETTERS_COUNT; ++i)
    {
        WaitForSingleObject(block, INFINITE);
        std::cout << "a" << std::flush;
        ReleaseMutex(block);
        computation();
    }
    return 0;
}

DWORD WINAPI thread_b(LPVOID lpParam)
{
    UNREFERENCED_PARAMETER(lpParam);

    for (int i = 0; i < LETTERS_COUNT; ++i)
    {
        WaitForSingleObject(smphr_b, INFINITE);
        WaitForSingleObject(block, INFINITE);
        std::cout << "b" << std::flush;
        ReleaseMutex(block);
        computation();
        ReleaseSemaphore(smphr_c, 1, NULL);
    }
    return 0;
}

DWORD WINAPI thread_c(LPVOID lpParam)
{
    UNREFERENCED_PARAMETER(lpParam);

    for (int i = 0; i < LETTERS_COUNT; ++i)
    {
        WaitForSingleObject(smphr_c, INFINITE);
        WaitForSingleObject(block, INFINITE);
        std::cout << "c" << std::flush;
        ReleaseMutex(block);
        computation();
        ReleaseSemaphore(smphr_d, 1, NULL);
    }
    return 0;
}

DWORD WINAPI thread_d(LPVOID lpParam)
{
    UNREFERENCED_PARAMETER(lpParam);

    for (int i = 0; i < LETTERS_COUNT; ++i)
    {
        WaitForSingleObject(smphr_d, INFINITE);
        std::cout << "d" << std::flush;
        ReleaseMutex(block);
        computation();
        ReleaseSemaphore(smphr_f, 1, NULL);
    }

    ReleaseSemaphore(smphr_section_done, 1, NULL);
    WaitForSingleObject(smphr_next_section, INFINITE);

    for (int i = 0; i < LETTERS_COUNT; ++i)
    {
        WaitForSingleObject(block, INFINITE);
        std::cout << "d" << std::flush;
        ReleaseMutex(block);
        computation();
    }

    ReleaseSemaphore(smphr_section_done, 1, NULL);
    WaitForSingleObject(smphr_next_section, INFINITE);

    for (int i = 0; i < LETTERS_COUNT; ++i)
    {
        WaitForSingleObject(block, INFINITE);
        std::cout << "d" << std::flush;
        ReleaseMutex(block);
        computation();
    }

    ReleaseSemaphore(smphr_section_done, 1, NULL);
    WaitForSingleObject(smphr_next_section, INFINITE);

    for (int i = 0; i < LETTERS_COUNT; ++i)
    {
        WaitForSingleObject(block, INFINITE);
        std::cout << "d" << std::flush;
        ReleaseMutex(block);
        computation();
    }
    return 0;
}

DWORD WINAPI thread_e(LPVOID lpParam)
{
    UNREFERENCED_PARAMETER(lpParam);

    for (int i = 0; i < LETTERS_COUNT; ++i)
    {
        WaitForSingleObject(block, INFINITE);
        std::cout << "e" << std::flush;
        ReleaseMutex(block);
        computation();
    }
    return 0;
}


DWORD WINAPI thread_f(LPVOID lpParam)
{
    UNREFERENCED_PARAMETER(lpParam);

    for (int i = 0; i < LETTERS_COUNT; ++i)
    {
        WaitForSingleObject(smphr_f, INFINITE);
        WaitForSingleObject(block, INFINITE);
        std::cout << "f" << std::flush;
        ReleaseMutex(block);
        computation();
        ReleaseSemaphore(smphr_b, 1, NULL);
    }

    ReleaseSemaphore(smphr_section_done, 1, NULL);
    WaitForSingleObject(smphr_next_section, INFINITE);

    for (int i = 0; i < LETTERS_COUNT; ++i)
    {
        WaitForSingleObject(block, INFINITE);
        std::cout << "f" << std::flush;
        ReleaseMutex(block);
        computation();
    }
    return 0;
}

DWORD WINAPI thread_g(LPVOID lpParam)
{
    UNREFERENCED_PARAMETER(lpParam);

    for (int i = 0; i < LETTERS_COUNT; ++i)
    {
        WaitForSingleObject(block, INFINITE);
        std::cout << "g" << std::flush;
        ReleaseMutex(block);
        computation();
    }
    return 0;
}

DWORD WINAPI thread_h(LPVOID lpParam)
{
    UNREFERENCED_PARAMETER(lpParam);

    for (int i = 0; i < LETTERS_COUNT; ++i)
    {
        WaitForSingleObject(block, INFINITE);
        std::cout << "h" << std::flush;
        ReleaseMutex(block);
        computation();
    }
    return 0;
}

DWORD WINAPI thread_i(LPVOID lpParam)
{
    UNREFERENCED_PARAMETER(lpParam);

    for (int i = 0; i < LETTERS_COUNT; ++i)
    {
        WaitForSingleObject(block, INFINITE);
        std::cout << "i" << std::flush;
        ReleaseMutex(block);
        computation();
    }

    ReleaseSemaphore(smphr_section_done, 1, NULL);
    WaitForSingleObject(smphr_next_section, INFINITE);

    for (int i = 0; i < LETTERS_COUNT; ++i)
    {
        WaitForSingleObject(block, INFINITE);
        std::cout << "i" << std::flush;
        ReleaseMutex(block);
        computation();
    }
    return 0;
}

DWORD WINAPI thread_k(LPVOID lpParam)
{
    UNREFERENCED_PARAMETER(lpParam);

    for (int i = 0; i < LETTERS_COUNT; ++i)
    {
        WaitForSingleObject(block, INFINITE);
        std::cout << "k" << std::flush;
        ReleaseMutex(block);
        computation();
    }

    ReleaseSemaphore(smphr_section_done, 1, NULL);
    WaitForSingleObject(smphr_next_section, INFINITE);

    for (int i = 0; i < LETTERS_COUNT; ++i)
    {
        WaitForSingleObject(block, INFINITE);
        std::cout << "k" << std::flush;
        ReleaseMutex(block);
        computation();
    }

    ReleaseSemaphore(smphr_section_done, 1, NULL);
    WaitForSingleObject(smphr_next_section, INFINITE);

    for (int i = 0; i < LETTERS_COUNT; ++i)
    {
        WaitForSingleObject(block, INFINITE);
        std::cout << "k" << std::flush;
        ReleaseMutex(block);
        computation();
    }
    return 0;
}

DWORD WINAPI thread_m(LPVOID lpParam)
{
    UNREFERENCED_PARAMETER(lpParam);

    for (int i = 0; i < LETTERS_COUNT; ++i)
    {
        WaitForSingleObject(block, INFINITE);
        std::cout << "m" << std::flush;
        ReleaseMutex(block);
        computation();
    }

    ReleaseSemaphore(smphr_section_done, 1, NULL);
    WaitForSingleObject(smphr_next_section, INFINITE);

    for (int i = 0; i < LETTERS_COUNT; ++i)
    {
        WaitForSingleObject(block, INFINITE);
        std::cout << "m" << std::flush;
        ReleaseMutex(block);
        computation();
    }
    return 0;
}

DWORD WINAPI thread_n(LPVOID lpParam)
{
    UNREFERENCED_PARAMETER(lpParam);
    for (int i = 0; i < LETTERS_COUNT; ++i)
    {
        WaitForSingleObject(block, INFINITE);
        std::cout << "n" << std::flush;
        ReleaseMutex(block);
        computation();
    }
    return 0;
}

DWORD WINAPI thread_p(LPVOID lpParam)
{
    UNREFERENCED_PARAMETER(lpParam);

    for (int i = 0; i < LETTERS_COUNT; ++i)
    {
        WaitForSingleObject(block, INFINITE);
        std::cout << "p" << std::flush;
        ReleaseMutex(block);
        computation();
    }
    return 0;
}

void initialization()
{
    // Инициализируем мьютекс
    block = CreateMutex(NULL, FALSE, NULL);
    if (block == NULL)
        std::cerr << "Mutex init failed" << std::endl;

    // Инициализируем семафоры
    smphr_b = CreateSemaphore(NULL, 1, 1, NULL);
    smphr_c = CreateSemaphore(NULL, 0, 1, NULL);
    smphr_d = CreateSemaphore(NULL, 0, 1, NULL);
    smphr_f = CreateSemaphore(NULL, 0, 1, NULL);
    smphr_section_done = CreateSemaphore(NULL, 0, 3, NULL);
    smphr_next_section = CreateSemaphore(NULL, 0, 3, NULL);
}

void run_graph()
{
    /* 1 */

    // Старт А
    thread[0] = CreateThread(NULL, 0, thread_a, NULL, 0, &ThreadID);
    if (thread[0] == NULL)
        std::cerr << "Can't create thread A. Error: " << GetLastError() << std::endl;
    // ожидание А
    WaitForSingleObject(thread[0], INFINITE);

    /* 2 */

    // Старт B, C, D, F
    thread[1] = CreateThread(NULL, 0, thread_b, NULL, 0, &ThreadID);
    if (thread[1] == NULL)
        std::cerr << "Can't create thread B. Error: " << GetLastError() << std::endl;

    thread[2] = CreateThread(NULL, 0, thread_c, NULL, 0, &ThreadID);
    if (thread[2] == NULL)
        std::cerr << "Can't create thread C. Error: " << GetLastError() << std::endl;

    thread[3] = CreateThread(NULL, 0, thread_d, NULL, 0, &ThreadID);
    if (thread[3] == NULL)
        std::cerr << "Can't create thread D. Error: " << GetLastError() << std::endl;

    thread[5] = CreateThread(NULL, 0, thread_f, NULL, 0, &ThreadID);
    if (thread[5] == NULL)
        std::cerr << "Can't create thread F. Error: " << GetLastError() << std::endl;
    // Ожидание B, C
    WaitForSingleObject(thread[1], INFINITE);
    WaitForSingleObject(thread[2], INFINITE);
    // Ожидание D, F
    WaitForSingleObject(smphr_section_done, INFINITE);
    WaitForSingleObject(smphr_section_done, INFINITE);

    /* 3 */

    // Продолжение D,F
    ReleaseSemaphore(smphr_next_section, 2, NULL);

    // Старт E, G, I, K
    thread[4] = CreateThread(NULL, 0, thread_e, NULL, 0, &ThreadID);
    if (thread[4] == NULL)
        std::cerr << "Can't create thread E. Error: " << GetLastError() << std::endl;

    thread[6] = CreateThread(NULL, 0, thread_g, NULL, 0, &ThreadID);
    if (thread[6] == NULL)
        std::cerr << "Can't create thread G. Error: " << GetLastError() << std::endl;

    thread[8] = CreateThread(NULL, 0, thread_i, NULL, 0, &ThreadID);
    if (thread[8] == NULL)
        std::cerr << "Can't create thread I. Error: " << GetLastError() << std::endl;

    thread[9] = CreateThread(NULL, 0, thread_k, NULL, 0, &ThreadID);
    if (thread[9] == NULL)
        std::cerr << "Can't create thread K. Error: " << GetLastError() << std::endl;

    // Ожидание F, E, G
    WaitForSingleObject(thread[4], INFINITE);
    WaitForSingleObject(thread[5], INFINITE);
    WaitForSingleObject(thread[6], INFINITE);
    // Ожидание D, K, I
    WaitForSingleObject(smphr_section_done, INFINITE);
    WaitForSingleObject(smphr_section_done, INFINITE);
    WaitForSingleObject(smphr_section_done, INFINITE);

    /* 4 */

    // Продолжение D, K, M
    ReleaseSemaphore(smphr_next_section, 3, NULL);

    // Старт H, M
    thread[7] = CreateThread(NULL, 0, thread_h, NULL, 0, &ThreadID);
    if (thread[7] == NULL)
        std::cerr << "Can't create thread H. Error: " << GetLastError() << std::endl;
    thread[10] = CreateThread(NULL, 0, thread_m, NULL, 0, &ThreadID);
    if (thread[10] == NULL)
        std::cerr << "Can't create thread M. Error: " << GetLastError() << std::endl;

    // Ожидание H, I
    WaitForSingleObject(thread[8], INFINITE);
    WaitForSingleObject(thread[7], INFINITE);

    // Ожидание D, K, M
    WaitForSingleObject(smphr_section_done, INFINITE);
    WaitForSingleObject(smphr_section_done, INFINITE);
    WaitForSingleObject(smphr_section_done, INFINITE);

    /* 5 */

    // Продолжение D, K, M
    ReleaseSemaphore(smphr_next_section, 3, NULL);

    // Старт N
    thread[11] = CreateThread(NULL, 0, thread_n, NULL, 0, &ThreadID);
    if (thread[11] == NULL)
        std::cerr << "Can't create thread N. Error: " << GetLastError() << std::endl;

    // Ожидание D, K, M, N
    WaitForSingleObject(thread[3], INFINITE);
    WaitForSingleObject(thread[9], INFINITE);
    WaitForSingleObject(thread[10], INFINITE);
    WaitForSingleObject(thread[11], INFINITE);

    /* 6 */

    // Старт Р
    thread[12] = CreateThread(NULL, 0, thread_p, NULL, 0, &ThreadID);
    if (thread[12] == NULL)
        std::cerr << "Can't create thread P. Error: " << GetLastError() << std::endl;

    // Ожидание Р
    WaitForSingleObject(thread[12], INFINITE);

    std::cout << std::endl;
}

void res_free()
{
    CloseHandle(block);
    CloseHandle(smphr_section_done);
    CloseHandle(smphr_next_section);
    CloseHandle(smphr_b);
    CloseHandle(smphr_c);
    CloseHandle(smphr_d);
    CloseHandle(smphr_f);
    for (int i = 0; i < THREADS_COUNT; ++i)
        CloseHandle(thread[i]);
}

int lab3_init()
{
    initialization();
    run_graph();
    res_free();
    return 0;
}
