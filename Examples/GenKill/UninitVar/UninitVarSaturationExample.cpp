#include <iostream>
#include "../VarSet.hpp"
#include "../GenKillTransformer_T.hpp"
#include "wali/Common.hpp"
#include "wali/wpds/WPDS.hpp"
#include "wali/wpds/fwpds/FWPDS.hpp"
#include "wali/wfa/WFA.hpp"
#include "wali/wfa/Trans.hpp"

/*
Example program to be analyzed

int a, b, c, d;

void main() {
1:  a = 5;
2:  b = 6;
3:  c = 7;
}
*/

void print_output( const wali::wfa::Trans& goal ) {
    goal.weight()->print( std::cout );
    std::cout << std::endl << std::endl;
}

int main(int argc, char **argv)
{
    using std::cout;
    using std::endl;
    wali::wpds::fwpds::FWPDS pds;
    wali::wpds::WPDS readout;
    std::set< wali::Key > R;
    std::set< wali::Key > B;

#ifdef TRACE
    traceFile = stderr;
#endif
#ifdef REFTRACE
    refTraceFile = stderr;
#endif

    /* PDS States */
    wali::Key q = wali::getKey("q");

    /* Nodes for procedure main */

    wali::Key e_main = wali::getKey("e_main");B.insert(e_main);
    wali::Key n1 = wali::getKey("n1");B.insert(n1);
    wali::Key n2 = wali::getKey("n2");B.insert(n2);
    wali::Key n3 = wali::getKey("n3");B.insert(n3);
    wali::Key x_main = wali::getKey("x_main");B.insert(x_main);

    /* Transitions (edges) for procedure main */
    pds.add_rule( q,     e_main,    q,    n1,     GenKillTransformer_T< VarSet >::makeGenKillTransformer_T(VarSet::EmptySet(), mkVarSet("a","b","c","d")));
    pds.add_rule( q,     n1,        q,    n2,     GenKillTransformer_T< VarSet >::makeGenKillTransformer_T(mkVarSet("a"), VarSet::EmptySet()));
    // USUAL place for rules
    // pds.add_rule( q,     n2,        q,    n3,     GenKillTransformer_T< VarSet >::makeGenKillTransformer_T(mkVarSet("b"), VarSet::EmptySet()));
    pds.add_rule( q,     n3,        q,    x_main, GenKillTransformer_T< VarSet >::makeGenKillTransformer_T(mkVarSet("c"), VarSet::EmptySet()));

    /* PDS transitions for "consuming" (backwards) the call graph to enclosing procedure */
    /* (one set for each CFG node)                                                       */
    wali::Key accepting_state = wali::getKey("accepting_state");

    /* debug print wpds */
    pds.print( std::cout ) << "\n----------------------------------------\n";
    /* pre* o post* of <q, e_main> */
    printf("pre* o post* of <q, e_main>\n\n");
    wali::wfa::WFA ca1;
    ca1.addTrans( q, e_main, accepting_state, GenKillTransformer_T< VarSet >::id());
    ca1.addFinalState( accepting_state );
    ca1.setInitialState( q );
    ca1.print( std::cout << "before\n" ) << std::endl;
    wali::wfa::WFA ca3;
    pds.poststar(ca1,ca3);
    ca3.print( std::cout << "after\n" ) << std::endl;

    /* PDS transitions for "consuming" the language (n11 + n14 + n6)*  */
    // R.insert( n6 );
    // R.insert( n11 );
    // R.insert( n14 );
    // R.insert( e_main );
    std::cout << "\n\n--- Calling path_summary ---\n";
    //ca3.path_summary( R );
    ca3.path_summary();

    // // UNUSUAL place for rule (and perform processing after adding an additional rule)
    pds.add_rule( q,     n2,        q,    n3,     GenKillTransformer_T< VarSet >::makeGenKillTransformer_T(mkVarSet("b"), VarSet::EmptySet()));
    pds.poststar(ca1,ca3);
    ca3.path_summary();

#if 0
    std::cout << "--- Done path_summary ---\n";

    // for each b element of B, print (q,b,q') and its weight
    for(std::set< wali::Key >::iterator iter = B.begin();
            iter != B.end(); iter++ ) {
        wali::Key b = *iter;
        //wali::Key b = n18;
        wpds::CA< GenKillTransformer_T< VarSet > >::TransSetIterPair pair = ca3.match( q,b );
        wpds::CA< GenKillTransformer_T< VarSet > >::TransSetIter titer = pair.first;
        wpds::Semiring< GenKillTransformer_T< VarSet > >::SemiringElement V_b(s.zero());
        //std::cout << "BEGINNING " << key2str(b) << "---------------\n";
        for( ; titer != pair.second; titer++ ) {
            wpds::CA< GenKillTransformer_T< VarSet > >::catrans_t t( *titer );

            //std::cout << "extending:\n\t" << ca3.state_weight(t->to_state()) << "\n\t" << t->semiring_element() << std::endl;

            wpds::Semiring< GenKillTransformer_T< VarSet > >::SemiringElement tmp(
                    s.extend( ca3.state_weight(t->to_state()),t->semiring_element() ) );

            //std::cout << "combining:\n\t" << V_b << "\n\t" << tmp << std::endl;
            V_b = s.combine(V_b,tmp);
        }
                printkey(b, std::cout) << ": " << V_b << "\n\n";
        //std::cout << "ENDING " << key2str(b) << "---------------\n\n";
    }
#endif
#if 1
    //std::cout << "middle\n" << ca3 << std::endl;

    //ca1 = pds.prestar(ca1);
    //ca1.print( std::cout << "after\n" ) << std::endl;

    wali::wfa::Trans goal;
    if( ca3.find(q,e_main,accepting_state,goal) ) {    cout << "e_main: ";print_output(goal);}
    if( ca3.find(q,n1,accepting_state,goal) ) {    cout << "n1: ";print_output(goal);}
    if( ca3.find(q,n2,accepting_state,goal) ) {    cout << "n2: ";print_output(goal);}
    if( ca3.find(q,n3,accepting_state,goal) ) {    cout << "n3: ";print_output(goal);}
    if( ca3.find(q,x_main,accepting_state,goal) ) {    cout << "x_main: ";print_output(goal);}

#endif

    return 0;
} /** end of main **/
