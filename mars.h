#ifndef MARS_H
#define MARS_H

typedef struct {

    int cn0;        /* satellite CNO*/
    double elev;    /* satellite elevation */
    double sdiff;   /* single diff */
    double ddiff;   /* dounle diff */

}snd_t;


typedef struct {
    int sat;        /* satellite number */
    snd_t *data;    /* satellite noise */
}snoise_t;


#endif // MARS_H
