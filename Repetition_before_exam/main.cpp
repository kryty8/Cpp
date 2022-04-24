#include<iostream>
using namespace std;

class Samochod{

    private:
        int wiek, cena, predkosc;
    public:
        Samochod *left ,*right, *next;

    Samochod()
    {
        wiek = rand()%21;
        predkosc = rand()% 151+150;
        cena = rand()% 35+65;
        left = NULL;
        right = NULL;
        next = NULL;
    }

    void wstaw_l(Samochod *nowy)
    {
        if(!next)
        {
            next = nowy;
        }
        else
        {
            if(nowy->wiek > next->wiek)
            {
                next->wstaw_l(nowy);
            }
            else
            {
                nowy->next = next;
                next = nowy;
            }
        }
    }

    void wyswietl_l()
    {
        cout << "W: " << wiek << "C: " << cena << "P: " << predkosc << endl;
        if(next)
        {
            next->wyswietl_l();
        }
    }

    int return_wiek()
    {
        return wiek;
    }

    int return_predkosc()
    {
        return predkosc;
    }

    int return_cena()
    {
        return cena;
    }

    void wstaw_d(Samochod *n)
    {
        if(cena > n->cena)
        {
            if(left) left->wstaw_d(n);
            else left=n;
        }
        else
        {
            if(right) right->wstaw_d(n);
            else right = n;
        }
    }

    void wyswietl_d()
    {
        if(left) left->wyswietl_d();
        cout << " W: " << wiek << " C: " << cena << " P: " << predkosc << endl;
        if(right) right->wyswietl_d();
    }

    int ile_l(int i=0)
    {
        i++;
        if(next)
        i+=next->ile_l(); //i=i+next->ile_l();
        return i;
    }

    //int ile_l(int i=1)
    //{
        //i++;
       // if(next)
       // i+=next->ile_l(++i);
   //}

   int ile_w_p(int p, int i=0)
   {
       if(predkosc > p)i++;
       if(next) i = next->ile_w_p(p,i);
       return i;
   }

   int suma_c_l()
   {
       int c = cena;
       if(next) c+=next->suma_c_l(); //c = c + next->suma_c_l();
       return c;
   }

   double srednia_cena()
   {
       int c = suma_c_l();
       int l = ile_l();
       return 1.0*((1.0 *c)/(1.0*l)); //1.0 to konwesrsja na doubla
   }

   int ile_d(int i=1)//samego siebie
   {
       if(left) i = left->ile_d(++i); //o i 1 wiekszego
       if(right) i = right->ile_d(++i);
       return i;
   }

    //int ile_d(int i=1)//samego siebie
  //{
      // if(left) i += left->ile_d(); //o i 1 wiekszego
     //  if(right) i += right->ile_d();
     //  return i;
  // }

    int najd() //najdrozszy bo ten parametr
    {
        if(right) return right->najd();
        else
        return cena;
    }

    int najm(int w=1000) //od wieku teraz szukamy
    {
        if(wiek < w) w = wiek; //pierwszy obiekt?
        if(left) w = left->najm(w);
        if(right) w = right -> najm(w);
        return w;
    }

    int ile_d_d(int c, int i=0)
    {
        if(cena > c)
        {
            i++;
            if(left) i = left->ile_d_d(c,i);
            if(right) i = right -> ile_d(++i);
        }
        else
        {
            if(right) i = right -> ile_d_d(c,i);
        }
        return i;
    }

    int suma_c_d()
    {
        int c = cena;
        if(left) c += left -> suma_c_d();
        if(right) c+= right -> suma_c_d();
        return c;
    }

    int wys()
    {
        if(!left and !right) return 0;
        else
        {
            int l = 0;
            int p = 0;
            if(left) l = left->wys();
            if(right) p = right ->wys();
            if(l>p) return l+1;
            else return p+1;
        }
    }
};

int main()
{
    Samochod *rl = new Samochod();

    for(int i=0; i<10;i++)
    {
        Samochod *nowy = new Samochod();
        if(nowy ->return_wiek() > rl->return_wiek())
        {
            rl->wstaw_l(nowy);
        }
        else
        {
            nowy->next = rl;
            rl = nowy;
        }
    }

    cout << "LIsta" << endl;
    rl->wyswietl_l();

    cout << "LE " << rl->ile_l() << endl;
    cout << "LE D 220 " << rl->ile_w_p(220) << endl;
    cout << "SC " << rl->suma_c_l() << endl;
    cout << "SC L " << rl->srednia_cena() << endl;

    Samochod *rd = NULL; //nie wiemy jaki bedzie korzen zeby bylo wieksze niz 65

    if(rl -> return_cena() > 65) //gdy pierwszy element spelnia warunek przeniseienia
    {
        rd = rl;
        rl = rl->next;
        rd->next = NULL;
        //jest to wyluskanie pierwszego elementu

        while(rl and rl->return_cena() >65)
        {
            Samochod *p = rl;
            rl = rl->next;
            p->next = NULL;
            rd->wstaw_d(p);
        }
        if(rl)
        {
            Samochod *ite = rl;
            while(ite->next)
            {
                if(ite->next-> return_cena() >65)
                {
                    Samochod *p = ite->next;
                    ite -> next = p->next;
                    p->next = NULL;
                    rd->wstaw_d(p);
                }
                else
                {
                    ite = ite->next;
                }
            }
        }
    }
    else
    {
        Samochod *ite = rl;
        while(!rd and ite->next)
        {
            if(ite -> next->return_cena() > 65)
            {
                rd = ite->next;
                ite -> next = rd -> next;
                rd -> next = NULL;
            }
            else
            {
                ite = ite -> next;
            }
        } //pierwszy element i szukamy dalej liste
        while(ite->next)
        {
            if(ite->next-> return_cena() > 65)
            {
                Samochod *p = ite->next;
                ite -> next = p->next;
                p->next = NULL;
                rd->wstaw_d(p);
            }
            else
            {
                ite = ite->next;
            }
        }
    }

    cout << endl;
    cout << "Lista" << endl;
    if(rl)rl->wyswietl_l();
    cout <<endl;
    cout << "Drzewo" << endl;
    if(rd)rd->wyswietl_d();
    cout << endl;
    cout << rd->ile_d() << endl;
    cout << endl;

    cout << "ND " << rd->najd() << endl;
    cout << "NM " << rd->najm() << endl;
    cout << "LD " << rd->ile_d_d(90) << endl;
    cout << "SC " << rd->suma_c_d() << endl;
    cout << " W " << rd->wys() << endl;

    return 0;
}
