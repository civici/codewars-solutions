// https://www.codewars.com/kata/525f50e3b73515a6db000b83

char *create_phone_number(char phnum[15], const unsigned char nums[10])
{
    sprintf(phnum, "(xxx) xxx-xxxx");
    int numCounter = 0;
    for (int i = 0; phnum[i] != '\0'; i++)
    {
        if (phnum[i] == 'x')
        {
            phnum[i] = nums[numCounter] + '0';
            numCounter++;
        }
    }
    return phnum;
}