include Irvine32.inc

.data
    Arr dword 3, 4, 1, 8, 2, 5
    len dword 6
.code
main proc

    push len
    push offset Arr
    call findTotal

    call writeDec
    exit
main endp

findTotal proc
    push ebp
    mov ebp, esp
    push esi
    push ecx
    push eax

    mov esi, [ebp + 8]    ; esi = pointer to array (arr)
    mov ecx, [ebp + 12]   ; ecx = length (len)
    xor eax, eax          ; total = 0

sum_loop:
    add eax, DWORD PTR [esi]        ; total += *esi
    add esi, 4            ; move to next dword (int)
    loop sum_loop

done:
    pop eax
    pop ecx
    pop esi
    pop ebp
    ret 8                 ; clean up 2 arguments (arr, len)

findTotal endp
end main