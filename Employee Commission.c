#include <stdio.h>


main() {
	int N_insc, TV_cor, TV_pb,i;
	double sal_fixo, sal_bruto=0,sal_liquido=0,comissaoTVcor=0,comissaoTVpb=0, comissao_final, INSS=0.08,IR=0.05,novo_sal,des_INSS,des_IR;
	
	do{
	printf("\nNumero de inscricao: "); scanf("%d",&N_insc);
	printf("Salario Fixo: "); scanf("%lf",&sal_fixo);
	printf("Quantidade de TVs A Cores Vendidos: "); scanf("%d",&TV_cor);
	printf("Quantidade de TVs Preto/branco Vendidas: "); scanf("%d",&TV_pb);

	
	if(TV_cor>=10)
		comissaoTVcor=100;
	else
		comissaoTVcor=50;
		
	if(TV_pb>=20)
		comissaoTVpb=40;
	else
		comissaoTVpb=20;

	
	comissao_final = (comissaoTVcor*TV_cor)+(comissaoTVpb*TV_pb);
	sal_bruto = sal_fixo + comissao_final;
	
	des_INSS = (sal_fixo-(sal_fixo*INSS));
	des_IR =  des_INSS-(des_INSS*IR);
		
	if(sal_bruto>=3000)
		sal_liquido = (des_IR-des_INSS) + comissao_final;                 
	else
		sal_liquido= des_INSS + comissao_final;
		
	
	printf("\nNumero de Inscricao: %d",N_insc);
	printf("\nSalario Bruto: %.2lf",sal_bruto);
	printf("\nSalario Liquido: %.2lf\n",sal_liquido);
	i++;
	
	} while (i<20);
	system ("pause");
}
