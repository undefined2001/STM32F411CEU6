# STM32F411CEU6
This is a repository to  keep all the data of STM32 BlackPill
####To Configure GPIO We Have to Do Following Steps
```
1. Setting The MODER Regsiter to set the mode of the GPIO Pin
2. Then we have to configure the __OTYPER__ Register to set output type. (It only works when pin Mode is OUTPUT)
3. Then we have to configure OSPEEDR to set the GPIO Speed. (It also works in Output Mode)
4. Then we have to configure the PUPDR Register to set pull up and pull down by default it configure as floating mode
5. 

```
</div>