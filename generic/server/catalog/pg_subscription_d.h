/*-------------------------------------------------------------------------
 *
 * pg_subscription_d.h
 *    Macro definitions for pg_subscription
 *
 * Portions Copyright (c) 1996-2023, PostgreSQL Global Development Group
 * Portions Copyright (c) 1994, Regents of the University of California
 *
 * NOTES
 *  ******************************
 *  *** DO NOT EDIT THIS FILE! ***
 *  ******************************
 *
 *  It has been GENERATED by src/backend/catalog/genbki.pl
 *
 *-------------------------------------------------------------------------
 */
#ifndef PG_SUBSCRIPTION_D_H
#define PG_SUBSCRIPTION_D_H

#define SubscriptionRelationId 6100
#define SubscriptionRelation_Rowtype_Id 6101
#define PgSubscriptionToastTable 4183
#define PgSubscriptionToastIndex 4184
#define SubscriptionObjectIndexId 6114
#define SubscriptionNameIndexId 6115

#define Anum_pg_subscription_oid 1
#define Anum_pg_subscription_subdbid 2
#define Anum_pg_subscription_subskiplsn 3
#define Anum_pg_subscription_subname 4
#define Anum_pg_subscription_subowner 5
#define Anum_pg_subscription_subenabled 6
#define Anum_pg_subscription_subbinary 7
#define Anum_pg_subscription_substream 8
#define Anum_pg_subscription_subtwophasestate 9
#define Anum_pg_subscription_subdisableonerr 10
#define Anum_pg_subscription_subpasswordrequired 11
#define Anum_pg_subscription_subrunasowner 12
#define Anum_pg_subscription_subconninfo 13
#define Anum_pg_subscription_subslotname 14
#define Anum_pg_subscription_subsynccommit 15
#define Anum_pg_subscription_subpublications 16
#define Anum_pg_subscription_suborigin 17

#define Natts_pg_subscription 17


#endif							/* PG_SUBSCRIPTION_D_H */
