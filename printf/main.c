/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emetras- <emetras-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 11:52:32 by emetras-          #+#    #+#             */
/*   Updated: 2022/09/10 13:30:00 by emetras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/ft_printf.h" //put your header pwd here
#include <stdio.h>
#include <limits.h>

void main(void)
{
    char *str = "word";

                //Single test
    printf("________________________\n\n");
    printf("percentage  test - %%\n\n");
    printf("\nOriginal return = %d\n", printf   ("Original print  = %%"));
    printf("\nmy       return = %d\n", ft_printf("My print        = %%"));
    printf("\n________________________\n\n");
    
    printf("Caracter  test - c\n\n");
    printf("\nOriginal return = %d\n", printf   ("Original print  = %c", 68));
    printf("\nmy       return = %d\n", ft_printf("My print        = %c", 68));
    printf("\n________________________\n\n");

    printf("String test - s\n\n");
    printf("\nOriginal return = %d\n", printf   ("Original print  = %s", "teste de 36 letras"));
    printf("\nmy       return = %d\n", ft_printf("My print        = %s", "teste de 36 letras"));
    printf("\n________________________\n\n");

    printf("Empty String test - s\n\n");
    printf("\nOriginal return = %d\n", printf   ("Original print  = %s", ""));
    printf("\nmy       return = %d\n", ft_printf("My print        = %s", ""));
    printf("\n________________________\n\n");

    printf("Decimal test - d\n\n");
    printf("\nOriginal return = %d\n", printf   ("Original print  = %d", 0));
    //Original function return error when tries to print "-2147483648" and "2147483648"
    // format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘long int’ = "-2147483648" and "2147483648"
    printf("\nmy       return = %d \n", ft_printf("My print        = %d", 0));
    printf("\n________________________\n\n");
    
    printf("Unsigned int test - u\n\n");
    printf("\nOriginal return = %d\n", printf   ("Original print  = %u", -245687));
    printf("\nmy       return = %d\n", ft_printf("My print        = %u", -245687));
    printf("\n________________________\n\n");

    printf("MULTI TEST - u\n\n");
    printf("\nOriginal return = %d\n", printf   ("Original print  = %u, %s, %%, %c", -245687, "string", 's'));
    printf("\nmy       return = %d\n", ft_printf("My print        = %u, %s, %%, %c", -245687, "string", 's'));
    printf("\n________________________\n\n");

    printf("Test Hex - x\n\n");
    printf("\nOriginal return = %d\n", printf   ("Original print  = %x, %x, %x", 256, 15, 0));
    printf("\nmy       return = %d\n", ft_printf("My print        = %x, %x, %x", 256, 15, 0));
    printf("\n________________________\n\n");

    printf("Test Hex - X\n\n");
    printf("\nOriginal return = %d\n", printf   ("Original print  = %X, %X, %X", 256, 15, 0));
    printf("\nmy       return = %d\n", ft_printf("My print        = %X, %X, %X", 256, 15, 0));
    printf("\n________________________\n\n");

    printf("Test Hex - x\n\n");
    printf("\nOriginal return = %d\n", printf   ("Original print  = %x, %x, %x", -256, -15, -0));
    printf("\nmy       return = %d\n", ft_printf("My print        = %x, %x, %x", -256, -15, -0));
    printf("\n________________________\n\n");

    printf("multi test  - x\n\n");
    printf("\nOriginal return = %d\n", printf   ("Original print  = %%%x, %x, %x", 245620145, -15, -0));
    printf("\nmy       return = %d\n", ft_printf("My print        = %%%x, %x, %x", 245620145, -15, -0));
    printf("\n________________________\n\n");

    printf("Pointer test - p\n\n");
    printf("\nOriginal return = %d\n", printf   ("Original print  = %p, %p, %p", &str, (char *)0, (char *)-256));
    printf("\nmy       return = %d\n", ft_printf("My print        = %p, %p, %p", &str, (char *)0, (char *)-256));
    printf("\n________________________\n\n");

    printf("Rodrigo test - INT_MIN\n\n");
    printf("\nOriginal return = %d\n", printf   ("Original print  = %p, %x, %X, %d, %i, %u", INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN));
    printf("\nmy       return = %d\n", ft_printf("My print        = %p, %x, %X, %d, %i, %u", INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN));
    printf("\n________________________\n\n");

    printf("Rodrigo test - INT_MAX\n\n");
    printf("\nOriginal return = %d\n", printf   ("Original print  = %p, %x, %X, %d, %i, %u", INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX));
    printf("\nmy       return = %d\n", ft_printf("My print        = %p, %x, %X, %d, %i, %u", INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX));
    printf("\n________________________\n\n");

    printf("Rodrigo test - U-INT_MAX\n\n");
    printf("\nOriginal return = %d\n", printf   ("Original print  = %p, %x, %X, %d, %i, %u", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX));
    printf("\nmy       return = %d\n", ft_printf("My print        = %p, %x, %X, %d, %i, %u", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX));
    printf("\n________________________\n\n");

    printf("Rodrigo test - LONG_MAX\n\n");
    printf("\nOriginal return = %d\n", printf   ("Original print  = %p, %x, %X, %d, %i, %u", LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX));
    printf("\nmy       return = %d\n", ft_printf("My print        = %p, %x, %X, %d, %i, %u", LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX));
    printf("\n________________________\n\n");

    printf("Rodrigo test - LONG_MIN\n\n");
    printf("\nOriginal return = %d\n", printf   ("Original print  = %p, %x, %X, %d, %i, %u", LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN));
    printf("\nmy       return = %d\n", ft_printf("My print        = %p, %x, %X, %d, %i, %u", LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN));
    printf("\n________________________\n\n");

    printf("Rodrigo test - ULONG_MAX\n\n");
    printf("\nOriginal return = %d\n", printf   ("Original print  = %p, %x, %X, %d, %i, %u", ULONG_MAX, ULONG_MAX, ULONG_MAX, ULONG_MAX, ULONG_MAX, ULONG_MAX));
    printf("\nmy       return = %d\n", ft_printf("My print        = %p, %x, %X, %d, %i, %u", ULONG_MAX, ULONG_MAX, ULONG_MAX, ULONG_MAX, ULONG_MAX, ULONG_MAX));
    printf("\n________________________\n\n");

}
