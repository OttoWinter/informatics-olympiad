//
//  main.cpp
//  BIT
//
//  Created by Otto Winter on 18/04/2017.
//  Copyright © 2017 Otto Winter. All rights reserved.
//

#include "BIT.h"
#include <stdio.h>

int main()
{
    int i, N, Q, qu, p, q, v, query_type;
    scanf("%d %d", &N, &Q);
    
    init(N);
    for(qu = 0; qu < Q; qu++)
    {
        scanf("%d", &query_type);
        if(query_type == 0)
        {
            scanf("%d %d", &i, &v);
            update(i, v);
        }
        else if(query_type == 1)
        {
            scanf("%d %d", &p, &q);
            printf("%lld\n", query(p, q));
        }
    }
    
    return 0;
}
