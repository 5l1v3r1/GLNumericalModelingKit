#include <stdio.h>
#include <stdlib.h>
#include <netcdf.h>



void
check_err(const int stat, const int line, const char *file) {
    if (stat != NC_NOERR) {
        (void)fprintf(stderr,"line %d of %s: %s\n", line, file, nc_strerror(stat));
        fflush(stderr);
        exit(1);
    }
}

int
main() {/* create ref_camrun.nc */

    int  stat;  /* return status */
    int  ncid;  /* netCDF id */

    /* dimension ids */
    int lat_dim;
    int lon_dim;
    int slat_dim;
    int slon_dim;
    int lev_dim;
    int ilev_dim;
    int isccp_prs_dim;
    int isccp_tau_dim;
    int isccp_prstau_dim;
    int time_dim;
    int tbnd_dim;
    int chars_dim;

    /* dimension lengths */
    size_t lat_len = 96;
    size_t lon_len = 144;
    size_t slat_len = 95;
    size_t slon_len = 144;
    size_t lev_len = 30;
    size_t ilev_len = 31;
    size_t isccp_prs_len = 7;
    size_t isccp_tau_len = 7;
    size_t isccp_prstau_len = 49;
    size_t time_len = NC_UNLIMITED;
    size_t tbnd_len = 2;
    size_t chars_len = 8;

    /* variable ids */
    int P0_id;
    int lat_id;
    int lon_id;
    int slat_id;
    int slon_id;
    int w_stag_id;
    int lev_id;
    int ilev_id;
    int isccp_prs_id;
    int isccp_tau_id;
    int isccp_prstau_id;
    int time_id;
    int time_bnds_id;
    int date_written_id;
    int time_written_id;
    int ntrm_id;
    int ntrn_id;
    int ntrk_id;
    int ndbase_id;
    int nsbase_id;
    int nbdate_id;
    int nbsec_id;
    int mdt_id;
    int nlon_id;
    int wnummax_id;
    int hyai_id;
    int hybi_id;
    int hyam_id;
    int hybm_id;
    int gw_id;
    int ndcur_id;
    int nscur_id;
    int date_id;
    int co2vmr_id;
    int ch4vmr_id;
    int n2ovmr_id;
    int f11vmr_id;
    int f12vmr_id;
    int sol_tsi_id;
    int datesec_id;
    int nsteph_id;
    int ABSORB_id;
    int AEROD_v_id;
    int AODABS_id;
    int AODDUST1_id;
    int AODDUST2_id;
    int AODDUST3_id;
    int AODMODE1_id;
    int AODMODE2_id;
    int AODMODE3_id;
    int AODVIS_id;
    int AQSO4_H2O2_id;
    int AQSO4_O3_id;
    int AQ_DMS_id;
    int AQ_H2O2_id;
    int AQ_H2SO4_id;
    int AQ_SO2_id;
    int AQ_SOAG_id;
    int AQ_bc_a1_id;
    int AQ_dst_a1_id;
    int AQ_dst_a3_id;
    int AQ_ncl_a1_id;
    int AQ_ncl_a2_id;
    int AQ_ncl_a3_id;
    int AQ_num_a1_id;
    int AQ_num_a2_id;
    int AQ_num_a3_id;
    int AQ_pom_a1_id;
    int AQ_so4_a1_id;
    int AQ_so4_a2_id;
    int AQ_so4_a3_id;
    int AQ_soa_a1_id;
    int AQ_soa_a2_id;
    int BPROD_id;
    int BURDEN1_id;
    int BURDEN2_id;
    int BURDEN3_id;
    int CCN1_id;
    int CCN2_id;
    int CCN3_id;
    int CCN4_id;
    int CCN5_id;
    int CCN6_id;
    int CLDHGH_id;
    int CLDICE_id;
    int CLDLIQ_id;
    int CLDLOW_id;
    int CLDMED_id;
    int CLDTOT_id;
    int CLOUD_id;
    int CMFDQ_id;
    int CMFDQR_id;
    int CMFDT_id;
    int CMFMC_id;
    int CMFMCDZM_id;
    int CONCLD_id;
    int DCQ_id;
    int DMS_id;
    int DSTODXC_id;
    int DSTSFDRY_id;
    int DSTSFMBL_id;
    int DSTSFWET_id;
    int DTCOND_id;
    int DTV_id;
    int EXTINCT_id;
    int FICE_id;
    int FLDS_id;
    int FLNS_id;
    int FLNSC_id;
    int FLNT_id;
    int FLNTC_id;
    int FLUT_id;
    int FLUTC_id;
    int FREQSH_id;
    int FREQZM_id;
    int FSDS_id;
    int FSDSC_id;
    int FSNS_id;
    int FSNSC_id;
    int FSNT_id;
    int FSNTC_id;
    int FSNTOA_id;
    int FSNTOAC_id;
    int FSUTOA_id;
    int GS_DMS_id;
    int GS_H2O2_id;
    int GS_H2SO4_id;
    int GS_SO2_id;
    int GS_SOAG_id;
    int GS_bc_a1_id;
    int GS_dst_a1_id;
    int GS_dst_a3_id;
    int GS_ncl_a1_id;
    int GS_ncl_a2_id;
    int GS_ncl_a3_id;
    int GS_num_a1_id;
    int GS_num_a2_id;
    int GS_num_a3_id;
    int GS_pom_a1_id;
    int GS_so4_a1_id;
    int GS_so4_a2_id;
    int GS_so4_a3_id;
    int GS_soa_a1_id;
    int GS_soa_a2_id;
    int H2O2_id;
    int H2SO4_id;
    int H2SO4_sfgaex1_id;
    int H2SO4_sfnnuc1_id;
    int ICEFRAC_id;
    int ICIMR_id;
    int ICWMR_id;
    int KVH_id;
    int KVM_id;
    int LANDFRAC_id;
    int LCLOUD_id;
    int LHFLX_id;
    int LND_MBL_id;
    int LWCF_id;
    int NDROPCOL_id;
    int NDROPMIX_id;
    int NDROPSNK_id;
    int NDROPSRC_id;
    int NUMICE_id;
    int NUMLIQ_id;
    int OCNFRAC_id;
    int ODV_bc_a1_id;
    int ODV_dst_a1_id;
    int ODV_dst_a3_id;
    int ODV_ncl_a1_id;
    int ODV_ncl_a3_id;
    int ODV_pom_a1_id;
    int ODV_so4_a1_id;
    int ODV_soa_a1_id;
    int OMEGA_id;
    int OMEGAT_id;
    int ORO_id;
    int PBLH_id;
    int PCONVB_id;
    int PCONVT_id;
    int PHIS_id;
    int PRECC_id;
    int PRECCDZM_id;
    int PRECL_id;
    int PRECSC_id;
    int PRECSH_id;
    int PRECSL_id;
    int PRECT_id;
    int PS_id;
    int PSL_id;
    int Q_id;
    int QC_id;
    int QFLX_id;
    int QREFHT_id;
    int QRL_id;
    int QRS_id;
    int QT_id;
    int QTFLX_id;
    int RAM1_id;
    int RELHUM_id;
    int RHREFHT_id;
    int SFCLDICE_id;
    int SFCLDLIQ_id;
    int SFI_id;
    int SFNUMICE_id;
    int SFNUMLIQ_id;
    int SHFLX_id;
    int SL_id;
    int SLFLX_id;
    int SLV_id;
    int SNOWHICE_id;
    int SNOWHLND_id;
    int SO2_id;
    int SO2_CLXF_id;
    int SO2_XFRC_id;
    int SOAG_id;
    int SOAG_sfgaex1_id;
    int SOLIN_id;
    int SPROD_id;
    int SRFRAD_id;
    int SSAVIS_id;
    int SSTODXC_id;
    int SSTSFDRY_id;
    int SSTSFMBL_id;
    int SSTSFWET_id;
    int SWCF_id;
    int T_id;
    int TAUTMSX_id;
    int TAUTMSY_id;
    int TAUX_id;
    int TAUY_id;
    int TGCLDCWP_id;
    int TGCLDIWP_id;
    int TGCLDLWP_id;
    int TKE_id;
    int TMQ_id;
    int TREFHT_id;
    int TREFMNAV_id;
    int TREFMXAV_id;
    int TROP_FD_id;
    int TROP_P_id;
    int TROP_PD_id;
    int TROP_T_id;
    int TROP_Z_id;
    int TS_id;
    int TSMN_id;
    int TSMX_id;
    int U_id;
    int UFLX_id;
    int US_id;
    int UU_id;
    int V_id;
    int VD01_id;
    int VFLX_id;
    int VQ_id;
    int VS_id;
    int VT_id;
    int VU_id;
    int VV_id;
    int WGUSTD_id;
    int WTKE_id;
    int XPH_LWC_id;
    int Z3_id;
    int airFV_id;
    int bc_a1_id;
    int bc_a1DDF_id;
    int bc_a1GVF_id;
    int bc_a1SFSBC_id;
    int bc_a1SFSBS_id;
    int bc_a1SFSIC_id;
    int bc_a1SFSIS_id;
    int bc_a1SFWET_id;
    int bc_a1TBF_id;
    int bc_a1_CLXF_id;
    int bc_a1_XFRC_id;
    int bc_c1_id;
    int bc_c1DDF_id;
    int bc_c1GVF_id;
    int bc_c1SFSBC_id;
    int bc_c1SFSBS_id;
    int bc_c1SFSIC_id;
    int bc_c1SFSIS_id;
    int bc_c1SFWET_id;
    int bc_c1TBF_id;
    int chem_trop_id;
    int chem_trop_tropop_id;
    int dgnd_a01_id;
    int dgnd_a02_id;
    int dgnd_a03_id;
    int dgnw_a01_id;
    int dgnw_a02_id;
    int dgnw_a03_id;
    int dst_a1_id;
    int dst_a1DDF_id;
    int dst_a1GVF_id;
    int dst_a1SF_id;
    int dst_a1SFSBC_id;
    int dst_a1SFSBS_id;
    int dst_a1SFSIC_id;
    int dst_a1SFSIS_id;
    int dst_a1SFWET_id;
    int dst_a1TBF_id;
    int dst_a3_id;
    int dst_a3DDF_id;
    int dst_a3GVF_id;
    int dst_a3SF_id;
    int dst_a3SFSBC_id;
    int dst_a3SFSBS_id;
    int dst_a3SFSIC_id;
    int dst_a3SFSIS_id;
    int dst_a3SFWET_id;
    int dst_a3TBF_id;
    int dst_c1_id;
    int dst_c1DDF_id;
    int dst_c1GVF_id;
    int dst_c1SFSBC_id;
    int dst_c1SFSBS_id;
    int dst_c1SFSIC_id;
    int dst_c1SFSIS_id;
    int dst_c1SFWET_id;
    int dst_c1TBF_id;
    int dst_c3_id;
    int dst_c3DDF_id;
    int dst_c3GVF_id;
    int dst_c3SFSBC_id;
    int dst_c3SFSBS_id;
    int dst_c3SFSIC_id;
    int dst_c3SFSIS_id;
    int dst_c3SFWET_id;
    int dst_c3TBF_id;
    int ncl_a1_id;
    int ncl_a1DDF_id;
    int ncl_a1GVF_id;
    int ncl_a1SF_id;
    int ncl_a1SFSBC_id;
    int ncl_a1SFSBS_id;
    int ncl_a1SFSIC_id;
    int ncl_a1SFSIS_id;
    int ncl_a1SFWET_id;
    int ncl_a1TBF_id;
    int ncl_a1_sfcoag1_id;
    int ncl_a1_sfcsiz3_id;
    int ncl_a1_sfcsiz4_id;
    int ncl_a1_sfgaex2_id;
    int ncl_a2_id;
    int ncl_a2DDF_id;
    int ncl_a2GVF_id;
    int ncl_a2SF_id;
    int ncl_a2SFSBC_id;
    int ncl_a2SFSBS_id;
    int ncl_a2SFSIC_id;
    int ncl_a2SFSIS_id;
    int ncl_a2SFWET_id;
    int ncl_a2TBF_id;
    int ncl_a2_sfcoag1_id;
    int ncl_a2_sfcsiz3_id;
    int ncl_a2_sfcsiz4_id;
    int ncl_a2_sfgaex2_id;
    int ncl_a3_id;
    int ncl_a3DDF_id;
    int ncl_a3GVF_id;
    int ncl_a3SF_id;
    int ncl_a3SFSBC_id;
    int ncl_a3SFSBS_id;
    int ncl_a3SFSIC_id;
    int ncl_a3SFSIS_id;
    int ncl_a3SFWET_id;
    int ncl_a3TBF_id;
    int ncl_c1_id;
    int ncl_c1DDF_id;
    int ncl_c1GVF_id;
    int ncl_c1SFSBC_id;
    int ncl_c1SFSBS_id;
    int ncl_c1SFSIC_id;
    int ncl_c1SFSIS_id;
    int ncl_c1SFWET_id;
    int ncl_c1TBF_id;
    int ncl_c1_sfcsiz3_id;
    int ncl_c1_sfcsiz4_id;
    int ncl_c1_sfgaex2_id;
    int ncl_c2_id;
    int ncl_c2DDF_id;
    int ncl_c2GVF_id;
    int ncl_c2SFSBC_id;
    int ncl_c2SFSBS_id;
    int ncl_c2SFSIC_id;
    int ncl_c2SFSIS_id;
    int ncl_c2SFWET_id;
    int ncl_c2TBF_id;
    int ncl_c2_sfcsiz3_id;
    int ncl_c2_sfcsiz4_id;
    int ncl_c2_sfgaex2_id;
    int ncl_c3_id;
    int ncl_c3DDF_id;
    int ncl_c3GVF_id;
    int ncl_c3SFSBC_id;
    int ncl_c3SFSBS_id;
    int ncl_c3SFSIC_id;
    int ncl_c3SFSIS_id;
    int ncl_c3SFWET_id;
    int ncl_c3TBF_id;
    int num_a1_id;
    int num_a1DDF_id;
    int num_a1GVF_id;
    int num_a1SFSBC_id;
    int num_a1SFSBS_id;
    int num_a1SFSIC_id;
    int num_a1SFSIS_id;
    int num_a1SFWET_id;
    int num_a1TBF_id;
    int num_a1_CLXF_id;
    int num_a1_XFRC_id;
    int num_a1_sfcoag1_id;
    int num_a1_sfcsiz1_id;
    int num_a1_sfcsiz2_id;
    int num_a1_sfcsiz3_id;
    int num_a1_sfcsiz4_id;
    int num_a1_sfgaex2_id;
    int num_a2_id;
    int num_a2DDF_id;
    int num_a2GVF_id;
    int num_a2SFSBC_id;
    int num_a2SFSBS_id;
    int num_a2SFSIC_id;
    int num_a2SFSIS_id;
    int num_a2SFWET_id;
    int num_a2TBF_id;
    int num_a2_CLXF_id;
    int num_a2_XFRC_id;
    int num_a2_sfcoag1_id;
    int num_a2_sfcsiz1_id;
    int num_a2_sfcsiz2_id;
    int num_a2_sfcsiz3_id;
    int num_a2_sfcsiz4_id;
    int num_a2_sfgaex2_id;
    int num_a2_sfnnuc1_id;
    int num_a3_id;
    int num_a3DDF_id;
    int num_a3GVF_id;
    int num_a3SFSBC_id;
    int num_a3SFSBS_id;
    int num_a3SFSIC_id;
    int num_a3SFSIS_id;
    int num_a3SFWET_id;
    int num_a3TBF_id;
    int num_a3_sfcsiz1_id;
    int num_a3_sfcsiz2_id;
    int num_c1_id;
    int num_c1DDF_id;
    int num_c1GVF_id;
    int num_c1SFSBC_id;
    int num_c1SFSBS_id;
    int num_c1SFSIC_id;
    int num_c1SFSIS_id;
    int num_c1SFWET_id;
    int num_c1TBF_id;
    int num_c1_sfcsiz1_id;
    int num_c1_sfcsiz2_id;
    int num_c1_sfcsiz3_id;
    int num_c1_sfcsiz4_id;
    int num_c1_sfgaex2_id;
    int num_c2_id;
    int num_c2DDF_id;
    int num_c2GVF_id;
    int num_c2SFSBC_id;
    int num_c2SFSBS_id;
    int num_c2SFSIC_id;
    int num_c2SFSIS_id;
    int num_c2SFWET_id;
    int num_c2TBF_id;
    int num_c2_sfcsiz1_id;
    int num_c2_sfcsiz2_id;
    int num_c2_sfcsiz3_id;
    int num_c2_sfcsiz4_id;
    int num_c2_sfgaex2_id;
    int num_c3_id;
    int num_c3DDF_id;
    int num_c3GVF_id;
    int num_c3SFSBC_id;
    int num_c3SFSBS_id;
    int num_c3SFSIC_id;
    int num_c3SFSIS_id;
    int num_c3SFWET_id;
    int num_c3TBF_id;
    int num_c3_sfcsiz1_id;
    int num_c3_sfcsiz2_id;
    int pom_a1_id;
    int pom_a1DDF_id;
    int pom_a1GVF_id;
    int pom_a1SFSBC_id;
    int pom_a1SFSBS_id;
    int pom_a1SFSIC_id;
    int pom_a1SFSIS_id;
    int pom_a1SFWET_id;
    int pom_a1TBF_id;
    int pom_a1_CLXF_id;
    int pom_a1_XFRC_id;
    int pom_c1_id;
    int pom_c1DDF_id;
    int pom_c1GVF_id;
    int pom_c1SFSBC_id;
    int pom_c1SFSBS_id;
    int pom_c1SFSIC_id;
    int pom_c1SFSIS_id;
    int pom_c1SFWET_id;
    int pom_c1TBF_id;
    int so4_a1_id;
    int so4_a1DDF_id;
    int so4_a1GVF_id;
    int so4_a1SFSBC_id;
    int so4_a1SFSBS_id;
    int so4_a1SFSIC_id;
    int so4_a1SFSIS_id;
    int so4_a1SFWET_id;
    int so4_a1TBF_id;
    int so4_a1_CLXF_id;
    int so4_a1_XFRC_id;
    int so4_a1_sfcoag1_id;
    int so4_a1_sfcsiz3_id;
    int so4_a1_sfcsiz4_id;
    int so4_a1_sfgaex1_id;
    int so4_a1_sfgaex2_id;
    int so4_a2_id;
    int so4_a2DDF_id;
    int so4_a2GVF_id;
    int so4_a2SFSBC_id;
    int so4_a2SFSBS_id;
    int so4_a2SFSIC_id;
    int so4_a2SFSIS_id;
    int so4_a2SFWET_id;
    int so4_a2TBF_id;
    int so4_a2_CLXF_id;
    int so4_a2_XFRC_id;
    int so4_a2_sfcoag1_id;
    int so4_a2_sfcsiz3_id;
    int so4_a2_sfcsiz4_id;
    int so4_a2_sfgaex1_id;
    int so4_a2_sfgaex2_id;
    int so4_a2_sfnnuc1_id;
    int so4_a3_id;
    int so4_a3DDF_id;
    int so4_a3GVF_id;
    int so4_a3SFSBC_id;
    int so4_a3SFSBS_id;
    int so4_a3SFSIC_id;
    int so4_a3SFSIS_id;
    int so4_a3SFWET_id;
    int so4_a3TBF_id;
    int so4_a3_sfgaex1_id;
    int so4_c1_id;
    int so4_c1AQH2SO4_id;
    int so4_c1AQSO4_id;
    int so4_c1DDF_id;
    int so4_c1GVF_id;
    int so4_c1SFSBC_id;
    int so4_c1SFSBS_id;
    int so4_c1SFSIC_id;
    int so4_c1SFSIS_id;
    int so4_c1SFWET_id;
    int so4_c1TBF_id;
    int so4_c1_sfcsiz3_id;
    int so4_c1_sfcsiz4_id;
    int so4_c1_sfgaex2_id;
    int so4_c2_id;
    int so4_c2AQH2SO4_id;
    int so4_c2AQSO4_id;
    int so4_c2DDF_id;
    int so4_c2GVF_id;
    int so4_c2SFSBC_id;
    int so4_c2SFSBS_id;
    int so4_c2SFSIC_id;
    int so4_c2SFSIS_id;
    int so4_c2SFWET_id;
    int so4_c2TBF_id;
    int so4_c2_sfcsiz3_id;
    int so4_c2_sfcsiz4_id;
    int so4_c2_sfgaex2_id;
    int so4_c3_id;
    int so4_c3AQH2SO4_id;
    int so4_c3AQSO4_id;
    int so4_c3DDF_id;
    int so4_c3GVF_id;
    int so4_c3SFSBC_id;
    int so4_c3SFSBS_id;
    int so4_c3SFSIC_id;
    int so4_c3SFSIS_id;
    int so4_c3SFWET_id;
    int so4_c3TBF_id;
    int soa_a1_id;
    int soa_a1DDF_id;
    int soa_a1GVF_id;
    int soa_a1SFSBC_id;
    int soa_a1SFSBS_id;
    int soa_a1SFSIC_id;
    int soa_a1SFSIS_id;
    int soa_a1SFWET_id;
    int soa_a1TBF_id;
    int soa_a1_sfcoag1_id;
    int soa_a1_sfcsiz3_id;
    int soa_a1_sfcsiz4_id;
    int soa_a1_sfgaex1_id;
    int soa_a1_sfgaex2_id;
    int soa_a2_id;
    int soa_a2DDF_id;
    int soa_a2GVF_id;
    int soa_a2SFSBC_id;
    int soa_a2SFSBS_id;
    int soa_a2SFSIC_id;
    int soa_a2SFSIS_id;
    int soa_a2SFWET_id;
    int soa_a2TBF_id;
    int soa_a2_sfcoag1_id;
    int soa_a2_sfcsiz3_id;
    int soa_a2_sfcsiz4_id;
    int soa_a2_sfgaex1_id;
    int soa_a2_sfgaex2_id;
    int soa_c1_id;
    int soa_c1DDF_id;
    int soa_c1GVF_id;
    int soa_c1SFSBC_id;
    int soa_c1SFSBS_id;
    int soa_c1SFSIC_id;
    int soa_c1SFSIS_id;
    int soa_c1SFWET_id;
    int soa_c1TBF_id;
    int soa_c1_sfcsiz3_id;
    int soa_c1_sfcsiz4_id;
    int soa_c1_sfgaex2_id;
    int soa_c2_id;
    int soa_c2DDF_id;
    int soa_c2GVF_id;
    int soa_c2SFSBC_id;
    int soa_c2SFSBS_id;
    int soa_c2SFSIC_id;
    int soa_c2SFSIS_id;
    int soa_c2SFWET_id;
    int soa_c2TBF_id;
    int soa_c2_sfcsiz3_id;
    int soa_c2_sfcsiz4_id;
    int soa_c2_sfgaex2_id;
    int wat_a1_id;
    int wat_a2_id;
    int wat_a3_id;

    /* rank (number of dimensions) for each variable */
#   define RANK_P0 0
#   define RANK_lat 1
#   define RANK_lon 1
#   define RANK_slat 1
#   define RANK_slon 1
#   define RANK_w_stag 1
#   define RANK_lev 1
#   define RANK_ilev 1
#   define RANK_isccp_prs 1
#   define RANK_isccp_tau 1
#   define RANK_isccp_prstau 1
#   define RANK_time 1
#   define RANK_time_bnds 2
#   define RANK_date_written 2
#   define RANK_time_written 2
#   define RANK_ntrm 0
#   define RANK_ntrn 0
#   define RANK_ntrk 0
#   define RANK_ndbase 0
#   define RANK_nsbase 0
#   define RANK_nbdate 0
#   define RANK_nbsec 0
#   define RANK_mdt 0
#   define RANK_nlon 1
#   define RANK_wnummax 1
#   define RANK_hyai 1
#   define RANK_hybi 1
#   define RANK_hyam 1
#   define RANK_hybm 1
#   define RANK_gw 1
#   define RANK_ndcur 1
#   define RANK_nscur 1
#   define RANK_date 1
#   define RANK_co2vmr 1
#   define RANK_ch4vmr 1
#   define RANK_n2ovmr 1
#   define RANK_f11vmr 1
#   define RANK_f12vmr 1
#   define RANK_sol_tsi 1
#   define RANK_datesec 1
#   define RANK_nsteph 1
#   define RANK_ABSORB 4
#   define RANK_AEROD_v 3
#   define RANK_AODABS 3
#   define RANK_AODDUST1 3
#   define RANK_AODDUST2 3
#   define RANK_AODDUST3 3
#   define RANK_AODMODE1 3
#   define RANK_AODMODE2 3
#   define RANK_AODMODE3 3
#   define RANK_AODVIS 3
#   define RANK_AQSO4_H2O2 3
#   define RANK_AQSO4_O3 3
#   define RANK_AQ_DMS 3
#   define RANK_AQ_H2O2 3
#   define RANK_AQ_H2SO4 3
#   define RANK_AQ_SO2 3
#   define RANK_AQ_SOAG 3
#   define RANK_AQ_bc_a1 3
#   define RANK_AQ_dst_a1 3
#   define RANK_AQ_dst_a3 3
#   define RANK_AQ_ncl_a1 3
#   define RANK_AQ_ncl_a2 3
#   define RANK_AQ_ncl_a3 3
#   define RANK_AQ_num_a1 3
#   define RANK_AQ_num_a2 3
#   define RANK_AQ_num_a3 3
#   define RANK_AQ_pom_a1 3
#   define RANK_AQ_so4_a1 3
#   define RANK_AQ_so4_a2 3
#   define RANK_AQ_so4_a3 3
#   define RANK_AQ_soa_a1 3
#   define RANK_AQ_soa_a2 3
#   define RANK_BPROD 4
#   define RANK_BURDEN1 3
#   define RANK_BURDEN2 3
#   define RANK_BURDEN3 3
#   define RANK_CCN1 4
#   define RANK_CCN2 4
#   define RANK_CCN3 4
#   define RANK_CCN4 4
#   define RANK_CCN5 4
#   define RANK_CCN6 4
#   define RANK_CLDHGH 3
#   define RANK_CLDICE 4
#   define RANK_CLDLIQ 4
#   define RANK_CLDLOW 3
#   define RANK_CLDMED 3
#   define RANK_CLDTOT 3
#   define RANK_CLOUD 4
#   define RANK_CMFDQ 4
#   define RANK_CMFDQR 4
#   define RANK_CMFDT 4
#   define RANK_CMFMC 4
#   define RANK_CMFMCDZM 4
#   define RANK_CONCLD 4
#   define RANK_DCQ 4
#   define RANK_DMS 4
#   define RANK_DSTODXC 3
#   define RANK_DSTSFDRY 3
#   define RANK_DSTSFMBL 3
#   define RANK_DSTSFWET 3
#   define RANK_DTCOND 4
#   define RANK_DTV 4
#   define RANK_EXTINCT 4
#   define RANK_FICE 4
#   define RANK_FLDS 3
#   define RANK_FLNS 3
#   define RANK_FLNSC 3
#   define RANK_FLNT 3
#   define RANK_FLNTC 3
#   define RANK_FLUT 3
#   define RANK_FLUTC 3
#   define RANK_FREQSH 3
#   define RANK_FREQZM 3
#   define RANK_FSDS 3
#   define RANK_FSDSC 3
#   define RANK_FSNS 3
#   define RANK_FSNSC 3
#   define RANK_FSNT 3
#   define RANK_FSNTC 3
#   define RANK_FSNTOA 3
#   define RANK_FSNTOAC 3
#   define RANK_FSUTOA 3
#   define RANK_GS_DMS 3
#   define RANK_GS_H2O2 3
#   define RANK_GS_H2SO4 3
#   define RANK_GS_SO2 3
#   define RANK_GS_SOAG 3
#   define RANK_GS_bc_a1 3
#   define RANK_GS_dst_a1 3
#   define RANK_GS_dst_a3 3
#   define RANK_GS_ncl_a1 3
#   define RANK_GS_ncl_a2 3
#   define RANK_GS_ncl_a3 3
#   define RANK_GS_num_a1 3
#   define RANK_GS_num_a2 3
#   define RANK_GS_num_a3 3
#   define RANK_GS_pom_a1 3
#   define RANK_GS_so4_a1 3
#   define RANK_GS_so4_a2 3
#   define RANK_GS_so4_a3 3
#   define RANK_GS_soa_a1 3
#   define RANK_GS_soa_a2 3
#   define RANK_H2O2 4
#   define RANK_H2SO4 4
#   define RANK_H2SO4_sfgaex1 3
#   define RANK_H2SO4_sfnnuc1 3
#   define RANK_ICEFRAC 3
#   define RANK_ICIMR 4
#   define RANK_ICWMR 4
#   define RANK_KVH 4
#   define RANK_KVM 4
#   define RANK_LANDFRAC 3
#   define RANK_LCLOUD 4
#   define RANK_LHFLX 3
#   define RANK_LND_MBL 3
#   define RANK_LWCF 3
#   define RANK_NDROPCOL 3
#   define RANK_NDROPMIX 4
#   define RANK_NDROPSNK 4
#   define RANK_NDROPSRC 4
#   define RANK_NUMICE 4
#   define RANK_NUMLIQ 4
#   define RANK_OCNFRAC 3
#   define RANK_ODV_bc_a1 3
#   define RANK_ODV_dst_a1 3
#   define RANK_ODV_dst_a3 3
#   define RANK_ODV_ncl_a1 3
#   define RANK_ODV_ncl_a3 3
#   define RANK_ODV_pom_a1 3
#   define RANK_ODV_so4_a1 3
#   define RANK_ODV_soa_a1 3
#   define RANK_OMEGA 4
#   define RANK_OMEGAT 4
#   define RANK_ORO 3
#   define RANK_PBLH 3
#   define RANK_PCONVB 3
#   define RANK_PCONVT 3
#   define RANK_PHIS 3
#   define RANK_PRECC 3
#   define RANK_PRECCDZM 3
#   define RANK_PRECL 3
#   define RANK_PRECSC 3
#   define RANK_PRECSH 3
#   define RANK_PRECSL 3
#   define RANK_PRECT 3
#   define RANK_PS 3
#   define RANK_PSL 3
#   define RANK_Q 4
#   define RANK_QC 4
#   define RANK_QFLX 3
#   define RANK_QREFHT 3
#   define RANK_QRL 4
#   define RANK_QRS 4
#   define RANK_QT 4
#   define RANK_QTFLX 4
#   define RANK_RAM1 3
#   define RANK_RELHUM 4
#   define RANK_RHREFHT 3
#   define RANK_SFCLDICE 3
#   define RANK_SFCLDLIQ 3
#   define RANK_SFI 4
#   define RANK_SFNUMICE 3
#   define RANK_SFNUMLIQ 3
#   define RANK_SHFLX 3
#   define RANK_SL 4
#   define RANK_SLFLX 4
#   define RANK_SLV 4
#   define RANK_SNOWHICE 3
#   define RANK_SNOWHLND 3
#   define RANK_SO2 4
#   define RANK_SO2_CLXF 3
#   define RANK_SO2_XFRC 4
#   define RANK_SOAG 4
#   define RANK_SOAG_sfgaex1 3
#   define RANK_SOLIN 3
#   define RANK_SPROD 4
#   define RANK_SRFRAD 3
#   define RANK_SSAVIS 3
#   define RANK_SSTODXC 3
#   define RANK_SSTSFDRY 3
#   define RANK_SSTSFMBL 3
#   define RANK_SSTSFWET 3
#   define RANK_SWCF 3
#   define RANK_T 4
#   define RANK_TAUTMSX 3
#   define RANK_TAUTMSY 3
#   define RANK_TAUX 3
#   define RANK_TAUY 3
#   define RANK_TGCLDCWP 3
#   define RANK_TGCLDIWP 3
#   define RANK_TGCLDLWP 3
#   define RANK_TKE 4
#   define RANK_TMQ 3
#   define RANK_TREFHT 3
#   define RANK_TREFMNAV 3
#   define RANK_TREFMXAV 3
#   define RANK_TROP_FD 3
#   define RANK_TROP_P 3
#   define RANK_TROP_PD 4
#   define RANK_TROP_T 3
#   define RANK_TROP_Z 3
#   define RANK_TS 3
#   define RANK_TSMN 3
#   define RANK_TSMX 3
#   define RANK_U 4
#   define RANK_UFLX 4
#   define RANK_US 4
#   define RANK_UU 4
#   define RANK_V 4
#   define RANK_VD01 4
#   define RANK_VFLX 4
#   define RANK_VQ 4
#   define RANK_VS 4
#   define RANK_VT 4
#   define RANK_VU 4
#   define RANK_VV 4
#   define RANK_WGUSTD 3
#   define RANK_WTKE 4
#   define RANK_XPH_LWC 4
#   define RANK_Z3 4
#   define RANK_airFV 3
#   define RANK_bc_a1 4
#   define RANK_bc_a1DDF 3
#   define RANK_bc_a1GVF 3
#   define RANK_bc_a1SFSBC 3
#   define RANK_bc_a1SFSBS 3
#   define RANK_bc_a1SFSIC 3
#   define RANK_bc_a1SFSIS 3
#   define RANK_bc_a1SFWET 3
#   define RANK_bc_a1TBF 3
#   define RANK_bc_a1_CLXF 3
#   define RANK_bc_a1_XFRC 4
#   define RANK_bc_c1 4
#   define RANK_bc_c1DDF 3
#   define RANK_bc_c1GVF 3
#   define RANK_bc_c1SFSBC 3
#   define RANK_bc_c1SFSBS 3
#   define RANK_bc_c1SFSIC 3
#   define RANK_bc_c1SFSIS 3
#   define RANK_bc_c1SFWET 3
#   define RANK_bc_c1TBF 3
#   define RANK_chem_trop 4
#   define RANK_chem_trop_tropop 4
#   define RANK_dgnd_a01 4
#   define RANK_dgnd_a02 4
#   define RANK_dgnd_a03 4
#   define RANK_dgnw_a01 4
#   define RANK_dgnw_a02 4
#   define RANK_dgnw_a03 4
#   define RANK_dst_a1 4
#   define RANK_dst_a1DDF 3
#   define RANK_dst_a1GVF 3
#   define RANK_dst_a1SF 3
#   define RANK_dst_a1SFSBC 3
#   define RANK_dst_a1SFSBS 3
#   define RANK_dst_a1SFSIC 3
#   define RANK_dst_a1SFSIS 3
#   define RANK_dst_a1SFWET 3
#   define RANK_dst_a1TBF 3
#   define RANK_dst_a3 4
#   define RANK_dst_a3DDF 3
#   define RANK_dst_a3GVF 3
#   define RANK_dst_a3SF 3
#   define RANK_dst_a3SFSBC 3
#   define RANK_dst_a3SFSBS 3
#   define RANK_dst_a3SFSIC 3
#   define RANK_dst_a3SFSIS 3
#   define RANK_dst_a3SFWET 3
#   define RANK_dst_a3TBF 3
#   define RANK_dst_c1 4
#   define RANK_dst_c1DDF 3
#   define RANK_dst_c1GVF 3
#   define RANK_dst_c1SFSBC 3
#   define RANK_dst_c1SFSBS 3
#   define RANK_dst_c1SFSIC 3
#   define RANK_dst_c1SFSIS 3
#   define RANK_dst_c1SFWET 3
#   define RANK_dst_c1TBF 3
#   define RANK_dst_c3 4
#   define RANK_dst_c3DDF 3
#   define RANK_dst_c3GVF 3
#   define RANK_dst_c3SFSBC 3
#   define RANK_dst_c3SFSBS 3
#   define RANK_dst_c3SFSIC 3
#   define RANK_dst_c3SFSIS 3
#   define RANK_dst_c3SFWET 3
#   define RANK_dst_c3TBF 3
#   define RANK_ncl_a1 4
#   define RANK_ncl_a1DDF 3
#   define RANK_ncl_a1GVF 3
#   define RANK_ncl_a1SF 3
#   define RANK_ncl_a1SFSBC 3
#   define RANK_ncl_a1SFSBS 3
#   define RANK_ncl_a1SFSIC 3
#   define RANK_ncl_a1SFSIS 3
#   define RANK_ncl_a1SFWET 3
#   define RANK_ncl_a1TBF 3
#   define RANK_ncl_a1_sfcoag1 3
#   define RANK_ncl_a1_sfcsiz3 3
#   define RANK_ncl_a1_sfcsiz4 3
#   define RANK_ncl_a1_sfgaex2 3
#   define RANK_ncl_a2 4
#   define RANK_ncl_a2DDF 3
#   define RANK_ncl_a2GVF 3
#   define RANK_ncl_a2SF 3
#   define RANK_ncl_a2SFSBC 3
#   define RANK_ncl_a2SFSBS 3
#   define RANK_ncl_a2SFSIC 3
#   define RANK_ncl_a2SFSIS 3
#   define RANK_ncl_a2SFWET 3
#   define RANK_ncl_a2TBF 3
#   define RANK_ncl_a2_sfcoag1 3
#   define RANK_ncl_a2_sfcsiz3 3
#   define RANK_ncl_a2_sfcsiz4 3
#   define RANK_ncl_a2_sfgaex2 3
#   define RANK_ncl_a3 4
#   define RANK_ncl_a3DDF 3
#   define RANK_ncl_a3GVF 3
#   define RANK_ncl_a3SF 3
#   define RANK_ncl_a3SFSBC 3
#   define RANK_ncl_a3SFSBS 3
#   define RANK_ncl_a3SFSIC 3
#   define RANK_ncl_a3SFSIS 3
#   define RANK_ncl_a3SFWET 3
#   define RANK_ncl_a3TBF 3
#   define RANK_ncl_c1 4
#   define RANK_ncl_c1DDF 3
#   define RANK_ncl_c1GVF 3
#   define RANK_ncl_c1SFSBC 3
#   define RANK_ncl_c1SFSBS 3
#   define RANK_ncl_c1SFSIC 3
#   define RANK_ncl_c1SFSIS 3
#   define RANK_ncl_c1SFWET 3
#   define RANK_ncl_c1TBF 3
#   define RANK_ncl_c1_sfcsiz3 3
#   define RANK_ncl_c1_sfcsiz4 3
#   define RANK_ncl_c1_sfgaex2 3
#   define RANK_ncl_c2 4
#   define RANK_ncl_c2DDF 3
#   define RANK_ncl_c2GVF 3
#   define RANK_ncl_c2SFSBC 3
#   define RANK_ncl_c2SFSBS 3
#   define RANK_ncl_c2SFSIC 3
#   define RANK_ncl_c2SFSIS 3
#   define RANK_ncl_c2SFWET 3
#   define RANK_ncl_c2TBF 3
#   define RANK_ncl_c2_sfcsiz3 3
#   define RANK_ncl_c2_sfcsiz4 3
#   define RANK_ncl_c2_sfgaex2 3
#   define RANK_ncl_c3 4
#   define RANK_ncl_c3DDF 3
#   define RANK_ncl_c3GVF 3
#   define RANK_ncl_c3SFSBC 3
#   define RANK_ncl_c3SFSBS 3
#   define RANK_ncl_c3SFSIC 3
#   define RANK_ncl_c3SFSIS 3
#   define RANK_ncl_c3SFWET 3
#   define RANK_ncl_c3TBF 3
#   define RANK_num_a1 4
#   define RANK_num_a1DDF 3
#   define RANK_num_a1GVF 3
#   define RANK_num_a1SFSBC 3
#   define RANK_num_a1SFSBS 3
#   define RANK_num_a1SFSIC 3
#   define RANK_num_a1SFSIS 3
#   define RANK_num_a1SFWET 3
#   define RANK_num_a1TBF 3
#   define RANK_num_a1_CLXF 3
#   define RANK_num_a1_XFRC 4
#   define RANK_num_a1_sfcoag1 3
#   define RANK_num_a1_sfcsiz1 3
#   define RANK_num_a1_sfcsiz2 3
#   define RANK_num_a1_sfcsiz3 3
#   define RANK_num_a1_sfcsiz4 3
#   define RANK_num_a1_sfgaex2 3
#   define RANK_num_a2 4
#   define RANK_num_a2DDF 3
#   define RANK_num_a2GVF 3
#   define RANK_num_a2SFSBC 3
#   define RANK_num_a2SFSBS 3
#   define RANK_num_a2SFSIC 3
#   define RANK_num_a2SFSIS 3
#   define RANK_num_a2SFWET 3
#   define RANK_num_a2TBF 3
#   define RANK_num_a2_CLXF 3
#   define RANK_num_a2_XFRC 4
#   define RANK_num_a2_sfcoag1 3
#   define RANK_num_a2_sfcsiz1 3
#   define RANK_num_a2_sfcsiz2 3
#   define RANK_num_a2_sfcsiz3 3
#   define RANK_num_a2_sfcsiz4 3
#   define RANK_num_a2_sfgaex2 3
#   define RANK_num_a2_sfnnuc1 3
#   define RANK_num_a3 4
#   define RANK_num_a3DDF 3
#   define RANK_num_a3GVF 3
#   define RANK_num_a3SFSBC 3
#   define RANK_num_a3SFSBS 3
#   define RANK_num_a3SFSIC 3
#   define RANK_num_a3SFSIS 3
#   define RANK_num_a3SFWET 3
#   define RANK_num_a3TBF 3
#   define RANK_num_a3_sfcsiz1 3
#   define RANK_num_a3_sfcsiz2 3
#   define RANK_num_c1 4
#   define RANK_num_c1DDF 3
#   define RANK_num_c1GVF 3
#   define RANK_num_c1SFSBC 3
#   define RANK_num_c1SFSBS 3
#   define RANK_num_c1SFSIC 3
#   define RANK_num_c1SFSIS 3
#   define RANK_num_c1SFWET 3
#   define RANK_num_c1TBF 3
#   define RANK_num_c1_sfcsiz1 3
#   define RANK_num_c1_sfcsiz2 3
#   define RANK_num_c1_sfcsiz3 3
#   define RANK_num_c1_sfcsiz4 3
#   define RANK_num_c1_sfgaex2 3
#   define RANK_num_c2 4
#   define RANK_num_c2DDF 3
#   define RANK_num_c2GVF 3
#   define RANK_num_c2SFSBC 3
#   define RANK_num_c2SFSBS 3
#   define RANK_num_c2SFSIC 3
#   define RANK_num_c2SFSIS 3
#   define RANK_num_c2SFWET 3
#   define RANK_num_c2TBF 3
#   define RANK_num_c2_sfcsiz1 3
#   define RANK_num_c2_sfcsiz2 3
#   define RANK_num_c2_sfcsiz3 3
#   define RANK_num_c2_sfcsiz4 3
#   define RANK_num_c2_sfgaex2 3
#   define RANK_num_c3 4
#   define RANK_num_c3DDF 3
#   define RANK_num_c3GVF 3
#   define RANK_num_c3SFSBC 3
#   define RANK_num_c3SFSBS 3
#   define RANK_num_c3SFSIC 3
#   define RANK_num_c3SFSIS 3
#   define RANK_num_c3SFWET 3
#   define RANK_num_c3TBF 3
#   define RANK_num_c3_sfcsiz1 3
#   define RANK_num_c3_sfcsiz2 3
#   define RANK_pom_a1 4
#   define RANK_pom_a1DDF 3
#   define RANK_pom_a1GVF 3
#   define RANK_pom_a1SFSBC 3
#   define RANK_pom_a1SFSBS 3
#   define RANK_pom_a1SFSIC 3
#   define RANK_pom_a1SFSIS 3
#   define RANK_pom_a1SFWET 3
#   define RANK_pom_a1TBF 3
#   define RANK_pom_a1_CLXF 3
#   define RANK_pom_a1_XFRC 4
#   define RANK_pom_c1 4
#   define RANK_pom_c1DDF 3
#   define RANK_pom_c1GVF 3
#   define RANK_pom_c1SFSBC 3
#   define RANK_pom_c1SFSBS 3
#   define RANK_pom_c1SFSIC 3
#   define RANK_pom_c1SFSIS 3
#   define RANK_pom_c1SFWET 3
#   define RANK_pom_c1TBF 3
#   define RANK_so4_a1 4
#   define RANK_so4_a1DDF 3
#   define RANK_so4_a1GVF 3
#   define RANK_so4_a1SFSBC 3
#   define RANK_so4_a1SFSBS 3
#   define RANK_so4_a1SFSIC 3
#   define RANK_so4_a1SFSIS 3
#   define RANK_so4_a1SFWET 3
#   define RANK_so4_a1TBF 3
#   define RANK_so4_a1_CLXF 3
#   define RANK_so4_a1_XFRC 4
#   define RANK_so4_a1_sfcoag1 3
#   define RANK_so4_a1_sfcsiz3 3
#   define RANK_so4_a1_sfcsiz4 3
#   define RANK_so4_a1_sfgaex1 3
#   define RANK_so4_a1_sfgaex2 3
#   define RANK_so4_a2 4
#   define RANK_so4_a2DDF 3
#   define RANK_so4_a2GVF 3
#   define RANK_so4_a2SFSBC 3
#   define RANK_so4_a2SFSBS 3
#   define RANK_so4_a2SFSIC 3
#   define RANK_so4_a2SFSIS 3
#   define RANK_so4_a2SFWET 3
#   define RANK_so4_a2TBF 3
#   define RANK_so4_a2_CLXF 3
#   define RANK_so4_a2_XFRC 4
#   define RANK_so4_a2_sfcoag1 3
#   define RANK_so4_a2_sfcsiz3 3
#   define RANK_so4_a2_sfcsiz4 3
#   define RANK_so4_a2_sfgaex1 3
#   define RANK_so4_a2_sfgaex2 3
#   define RANK_so4_a2_sfnnuc1 3
#   define RANK_so4_a3 4
#   define RANK_so4_a3DDF 3
#   define RANK_so4_a3GVF 3
#   define RANK_so4_a3SFSBC 3
#   define RANK_so4_a3SFSBS 3
#   define RANK_so4_a3SFSIC 3
#   define RANK_so4_a3SFSIS 3
#   define RANK_so4_a3SFWET 3
#   define RANK_so4_a3TBF 3
#   define RANK_so4_a3_sfgaex1 3
#   define RANK_so4_c1 4
#   define RANK_so4_c1AQH2SO4 3
#   define RANK_so4_c1AQSO4 3
#   define RANK_so4_c1DDF 3
#   define RANK_so4_c1GVF 3
#   define RANK_so4_c1SFSBC 3
#   define RANK_so4_c1SFSBS 3
#   define RANK_so4_c1SFSIC 3
#   define RANK_so4_c1SFSIS 3
#   define RANK_so4_c1SFWET 3
#   define RANK_so4_c1TBF 3
#   define RANK_so4_c1_sfcsiz3 3
#   define RANK_so4_c1_sfcsiz4 3
#   define RANK_so4_c1_sfgaex2 3
#   define RANK_so4_c2 4
#   define RANK_so4_c2AQH2SO4 3
#   define RANK_so4_c2AQSO4 3
#   define RANK_so4_c2DDF 3
#   define RANK_so4_c2GVF 3
#   define RANK_so4_c2SFSBC 3
#   define RANK_so4_c2SFSBS 3
#   define RANK_so4_c2SFSIC 3
#   define RANK_so4_c2SFSIS 3
#   define RANK_so4_c2SFWET 3
#   define RANK_so4_c2TBF 3
#   define RANK_so4_c2_sfcsiz3 3
#   define RANK_so4_c2_sfcsiz4 3
#   define RANK_so4_c2_sfgaex2 3
#   define RANK_so4_c3 4
#   define RANK_so4_c3AQH2SO4 3
#   define RANK_so4_c3AQSO4 3
#   define RANK_so4_c3DDF 3
#   define RANK_so4_c3GVF 3
#   define RANK_so4_c3SFSBC 3
#   define RANK_so4_c3SFSBS 3
#   define RANK_so4_c3SFSIC 3
#   define RANK_so4_c3SFSIS 3
#   define RANK_so4_c3SFWET 3
#   define RANK_so4_c3TBF 3
#   define RANK_soa_a1 4
#   define RANK_soa_a1DDF 3
#   define RANK_soa_a1GVF 3
#   define RANK_soa_a1SFSBC 3
#   define RANK_soa_a1SFSBS 3
#   define RANK_soa_a1SFSIC 3
#   define RANK_soa_a1SFSIS 3
#   define RANK_soa_a1SFWET 3
#   define RANK_soa_a1TBF 3
#   define RANK_soa_a1_sfcoag1 3
#   define RANK_soa_a1_sfcsiz3 3
#   define RANK_soa_a1_sfcsiz4 3
#   define RANK_soa_a1_sfgaex1 3
#   define RANK_soa_a1_sfgaex2 3
#   define RANK_soa_a2 4
#   define RANK_soa_a2DDF 3
#   define RANK_soa_a2GVF 3
#   define RANK_soa_a2SFSBC 3
#   define RANK_soa_a2SFSBS 3
#   define RANK_soa_a2SFSIC 3
#   define RANK_soa_a2SFSIS 3
#   define RANK_soa_a2SFWET 3
#   define RANK_soa_a2TBF 3
#   define RANK_soa_a2_sfcoag1 3
#   define RANK_soa_a2_sfcsiz3 3
#   define RANK_soa_a2_sfcsiz4 3
#   define RANK_soa_a2_sfgaex1 3
#   define RANK_soa_a2_sfgaex2 3
#   define RANK_soa_c1 4
#   define RANK_soa_c1DDF 3
#   define RANK_soa_c1GVF 3
#   define RANK_soa_c1SFSBC 3
#   define RANK_soa_c1SFSBS 3
#   define RANK_soa_c1SFSIC 3
#   define RANK_soa_c1SFSIS 3
#   define RANK_soa_c1SFWET 3
#   define RANK_soa_c1TBF 3
#   define RANK_soa_c1_sfcsiz3 3
#   define RANK_soa_c1_sfcsiz4 3
#   define RANK_soa_c1_sfgaex2 3
#   define RANK_soa_c2 4
#   define RANK_soa_c2DDF 3
#   define RANK_soa_c2GVF 3
#   define RANK_soa_c2SFSBC 3
#   define RANK_soa_c2SFSBS 3
#   define RANK_soa_c2SFSIC 3
#   define RANK_soa_c2SFSIS 3
#   define RANK_soa_c2SFWET 3
#   define RANK_soa_c2TBF 3
#   define RANK_soa_c2_sfcsiz3 3
#   define RANK_soa_c2_sfcsiz4 3
#   define RANK_soa_c2_sfgaex2 3
#   define RANK_wat_a1 4
#   define RANK_wat_a2 4
#   define RANK_wat_a3 4

    /* variable shapes */
    int lat_dims[RANK_lat];
    int lon_dims[RANK_lon];
    int slat_dims[RANK_slat];
    int slon_dims[RANK_slon];
    int w_stag_dims[RANK_w_stag];
    int lev_dims[RANK_lev];
    int ilev_dims[RANK_ilev];
    int isccp_prs_dims[RANK_isccp_prs];
    int isccp_tau_dims[RANK_isccp_tau];
    int isccp_prstau_dims[RANK_isccp_prstau];
    int time_dims[RANK_time];
    int time_bnds_dims[RANK_time_bnds];
    int date_written_dims[RANK_date_written];
    int time_written_dims[RANK_time_written];
    int nlon_dims[RANK_nlon];
    int wnummax_dims[RANK_wnummax];
    int hyai_dims[RANK_hyai];
    int hybi_dims[RANK_hybi];
    int hyam_dims[RANK_hyam];
    int hybm_dims[RANK_hybm];
    int gw_dims[RANK_gw];
    int ndcur_dims[RANK_ndcur];
    int nscur_dims[RANK_nscur];
    int date_dims[RANK_date];
    int co2vmr_dims[RANK_co2vmr];
    int ch4vmr_dims[RANK_ch4vmr];
    int n2ovmr_dims[RANK_n2ovmr];
    int f11vmr_dims[RANK_f11vmr];
    int f12vmr_dims[RANK_f12vmr];
    int sol_tsi_dims[RANK_sol_tsi];
    int datesec_dims[RANK_datesec];
    int nsteph_dims[RANK_nsteph];
    int ABSORB_dims[RANK_ABSORB];
    int AEROD_v_dims[RANK_AEROD_v];
    int AODABS_dims[RANK_AODABS];
    int AODDUST1_dims[RANK_AODDUST1];
    int AODDUST2_dims[RANK_AODDUST2];
    int AODDUST3_dims[RANK_AODDUST3];
    int AODMODE1_dims[RANK_AODMODE1];
    int AODMODE2_dims[RANK_AODMODE2];
    int AODMODE3_dims[RANK_AODMODE3];
    int AODVIS_dims[RANK_AODVIS];
    int AQSO4_H2O2_dims[RANK_AQSO4_H2O2];
    int AQSO4_O3_dims[RANK_AQSO4_O3];
    int AQ_DMS_dims[RANK_AQ_DMS];
    int AQ_H2O2_dims[RANK_AQ_H2O2];
    int AQ_H2SO4_dims[RANK_AQ_H2SO4];
    int AQ_SO2_dims[RANK_AQ_SO2];
    int AQ_SOAG_dims[RANK_AQ_SOAG];
    int AQ_bc_a1_dims[RANK_AQ_bc_a1];
    int AQ_dst_a1_dims[RANK_AQ_dst_a1];
    int AQ_dst_a3_dims[RANK_AQ_dst_a3];
    int AQ_ncl_a1_dims[RANK_AQ_ncl_a1];
    int AQ_ncl_a2_dims[RANK_AQ_ncl_a2];
    int AQ_ncl_a3_dims[RANK_AQ_ncl_a3];
    int AQ_num_a1_dims[RANK_AQ_num_a1];
    int AQ_num_a2_dims[RANK_AQ_num_a2];
    int AQ_num_a3_dims[RANK_AQ_num_a3];
    int AQ_pom_a1_dims[RANK_AQ_pom_a1];
    int AQ_so4_a1_dims[RANK_AQ_so4_a1];
    int AQ_so4_a2_dims[RANK_AQ_so4_a2];
    int AQ_so4_a3_dims[RANK_AQ_so4_a3];
    int AQ_soa_a1_dims[RANK_AQ_soa_a1];
    int AQ_soa_a2_dims[RANK_AQ_soa_a2];
    int BPROD_dims[RANK_BPROD];
    int BURDEN1_dims[RANK_BURDEN1];
    int BURDEN2_dims[RANK_BURDEN2];
    int BURDEN3_dims[RANK_BURDEN3];
    int CCN1_dims[RANK_CCN1];
    int CCN2_dims[RANK_CCN2];
    int CCN3_dims[RANK_CCN3];
    int CCN4_dims[RANK_CCN4];
    int CCN5_dims[RANK_CCN5];
    int CCN6_dims[RANK_CCN6];
    int CLDHGH_dims[RANK_CLDHGH];
    int CLDICE_dims[RANK_CLDICE];
    int CLDLIQ_dims[RANK_CLDLIQ];
    int CLDLOW_dims[RANK_CLDLOW];
    int CLDMED_dims[RANK_CLDMED];
    int CLDTOT_dims[RANK_CLDTOT];
    int CLOUD_dims[RANK_CLOUD];
    int CMFDQ_dims[RANK_CMFDQ];
    int CMFDQR_dims[RANK_CMFDQR];
    int CMFDT_dims[RANK_CMFDT];
    int CMFMC_dims[RANK_CMFMC];
    int CMFMCDZM_dims[RANK_CMFMCDZM];
    int CONCLD_dims[RANK_CONCLD];
    int DCQ_dims[RANK_DCQ];
    int DMS_dims[RANK_DMS];
    int DSTODXC_dims[RANK_DSTODXC];
    int DSTSFDRY_dims[RANK_DSTSFDRY];
    int DSTSFMBL_dims[RANK_DSTSFMBL];
    int DSTSFWET_dims[RANK_DSTSFWET];
    int DTCOND_dims[RANK_DTCOND];
    int DTV_dims[RANK_DTV];
    int EXTINCT_dims[RANK_EXTINCT];
    int FICE_dims[RANK_FICE];
    int FLDS_dims[RANK_FLDS];
    int FLNS_dims[RANK_FLNS];
    int FLNSC_dims[RANK_FLNSC];
    int FLNT_dims[RANK_FLNT];
    int FLNTC_dims[RANK_FLNTC];
    int FLUT_dims[RANK_FLUT];
    int FLUTC_dims[RANK_FLUTC];
    int FREQSH_dims[RANK_FREQSH];
    int FREQZM_dims[RANK_FREQZM];
    int FSDS_dims[RANK_FSDS];
    int FSDSC_dims[RANK_FSDSC];
    int FSNS_dims[RANK_FSNS];
    int FSNSC_dims[RANK_FSNSC];
    int FSNT_dims[RANK_FSNT];
    int FSNTC_dims[RANK_FSNTC];
    int FSNTOA_dims[RANK_FSNTOA];
    int FSNTOAC_dims[RANK_FSNTOAC];
    int FSUTOA_dims[RANK_FSUTOA];
    int GS_DMS_dims[RANK_GS_DMS];
    int GS_H2O2_dims[RANK_GS_H2O2];
    int GS_H2SO4_dims[RANK_GS_H2SO4];
    int GS_SO2_dims[RANK_GS_SO2];
    int GS_SOAG_dims[RANK_GS_SOAG];
    int GS_bc_a1_dims[RANK_GS_bc_a1];
    int GS_dst_a1_dims[RANK_GS_dst_a1];
    int GS_dst_a3_dims[RANK_GS_dst_a3];
    int GS_ncl_a1_dims[RANK_GS_ncl_a1];
    int GS_ncl_a2_dims[RANK_GS_ncl_a2];
    int GS_ncl_a3_dims[RANK_GS_ncl_a3];
    int GS_num_a1_dims[RANK_GS_num_a1];
    int GS_num_a2_dims[RANK_GS_num_a2];
    int GS_num_a3_dims[RANK_GS_num_a3];
    int GS_pom_a1_dims[RANK_GS_pom_a1];
    int GS_so4_a1_dims[RANK_GS_so4_a1];
    int GS_so4_a2_dims[RANK_GS_so4_a2];
    int GS_so4_a3_dims[RANK_GS_so4_a3];
    int GS_soa_a1_dims[RANK_GS_soa_a1];
    int GS_soa_a2_dims[RANK_GS_soa_a2];
    int H2O2_dims[RANK_H2O2];
    int H2SO4_dims[RANK_H2SO4];
    int H2SO4_sfgaex1_dims[RANK_H2SO4_sfgaex1];
    int H2SO4_sfnnuc1_dims[RANK_H2SO4_sfnnuc1];
    int ICEFRAC_dims[RANK_ICEFRAC];
    int ICIMR_dims[RANK_ICIMR];
    int ICWMR_dims[RANK_ICWMR];
    int KVH_dims[RANK_KVH];
    int KVM_dims[RANK_KVM];
    int LANDFRAC_dims[RANK_LANDFRAC];
    int LCLOUD_dims[RANK_LCLOUD];
    int LHFLX_dims[RANK_LHFLX];
    int LND_MBL_dims[RANK_LND_MBL];
    int LWCF_dims[RANK_LWCF];
    int NDROPCOL_dims[RANK_NDROPCOL];
    int NDROPMIX_dims[RANK_NDROPMIX];
    int NDROPSNK_dims[RANK_NDROPSNK];
    int NDROPSRC_dims[RANK_NDROPSRC];
    int NUMICE_dims[RANK_NUMICE];
    int NUMLIQ_dims[RANK_NUMLIQ];
    int OCNFRAC_dims[RANK_OCNFRAC];
    int ODV_bc_a1_dims[RANK_ODV_bc_a1];
    int ODV_dst_a1_dims[RANK_ODV_dst_a1];
    int ODV_dst_a3_dims[RANK_ODV_dst_a3];
    int ODV_ncl_a1_dims[RANK_ODV_ncl_a1];
    int ODV_ncl_a3_dims[RANK_ODV_ncl_a3];
    int ODV_pom_a1_dims[RANK_ODV_pom_a1];
    int ODV_so4_a1_dims[RANK_ODV_so4_a1];
    int ODV_soa_a1_dims[RANK_ODV_soa_a1];
    int OMEGA_dims[RANK_OMEGA];
    int OMEGAT_dims[RANK_OMEGAT];
    int ORO_dims[RANK_ORO];
    int PBLH_dims[RANK_PBLH];
    int PCONVB_dims[RANK_PCONVB];
    int PCONVT_dims[RANK_PCONVT];
    int PHIS_dims[RANK_PHIS];
    int PRECC_dims[RANK_PRECC];
    int PRECCDZM_dims[RANK_PRECCDZM];
    int PRECL_dims[RANK_PRECL];
    int PRECSC_dims[RANK_PRECSC];
    int PRECSH_dims[RANK_PRECSH];
    int PRECSL_dims[RANK_PRECSL];
    int PRECT_dims[RANK_PRECT];
    int PS_dims[RANK_PS];
    int PSL_dims[RANK_PSL];
    int Q_dims[RANK_Q];
    int QC_dims[RANK_QC];
    int QFLX_dims[RANK_QFLX];
    int QREFHT_dims[RANK_QREFHT];
    int QRL_dims[RANK_QRL];
    int QRS_dims[RANK_QRS];
    int QT_dims[RANK_QT];
    int QTFLX_dims[RANK_QTFLX];
    int RAM1_dims[RANK_RAM1];
    int RELHUM_dims[RANK_RELHUM];
    int RHREFHT_dims[RANK_RHREFHT];
    int SFCLDICE_dims[RANK_SFCLDICE];
    int SFCLDLIQ_dims[RANK_SFCLDLIQ];
    int SFI_dims[RANK_SFI];
    int SFNUMICE_dims[RANK_SFNUMICE];
    int SFNUMLIQ_dims[RANK_SFNUMLIQ];
    int SHFLX_dims[RANK_SHFLX];
    int SL_dims[RANK_SL];
    int SLFLX_dims[RANK_SLFLX];
    int SLV_dims[RANK_SLV];
    int SNOWHICE_dims[RANK_SNOWHICE];
    int SNOWHLND_dims[RANK_SNOWHLND];
    int SO2_dims[RANK_SO2];
    int SO2_CLXF_dims[RANK_SO2_CLXF];
    int SO2_XFRC_dims[RANK_SO2_XFRC];
    int SOAG_dims[RANK_SOAG];
    int SOAG_sfgaex1_dims[RANK_SOAG_sfgaex1];
    int SOLIN_dims[RANK_SOLIN];
    int SPROD_dims[RANK_SPROD];
    int SRFRAD_dims[RANK_SRFRAD];
    int SSAVIS_dims[RANK_SSAVIS];
    int SSTODXC_dims[RANK_SSTODXC];
    int SSTSFDRY_dims[RANK_SSTSFDRY];
    int SSTSFMBL_dims[RANK_SSTSFMBL];
    int SSTSFWET_dims[RANK_SSTSFWET];
    int SWCF_dims[RANK_SWCF];
    int T_dims[RANK_T];
    int TAUTMSX_dims[RANK_TAUTMSX];
    int TAUTMSY_dims[RANK_TAUTMSY];
    int TAUX_dims[RANK_TAUX];
    int TAUY_dims[RANK_TAUY];
    int TGCLDCWP_dims[RANK_TGCLDCWP];
    int TGCLDIWP_dims[RANK_TGCLDIWP];
    int TGCLDLWP_dims[RANK_TGCLDLWP];
    int TKE_dims[RANK_TKE];
    int TMQ_dims[RANK_TMQ];
    int TREFHT_dims[RANK_TREFHT];
    int TREFMNAV_dims[RANK_TREFMNAV];
    int TREFMXAV_dims[RANK_TREFMXAV];
    int TROP_FD_dims[RANK_TROP_FD];
    int TROP_P_dims[RANK_TROP_P];
    int TROP_PD_dims[RANK_TROP_PD];
    int TROP_T_dims[RANK_TROP_T];
    int TROP_Z_dims[RANK_TROP_Z];
    int TS_dims[RANK_TS];
    int TSMN_dims[RANK_TSMN];
    int TSMX_dims[RANK_TSMX];
    int U_dims[RANK_U];
    int UFLX_dims[RANK_UFLX];
    int US_dims[RANK_US];
    int UU_dims[RANK_UU];
    int V_dims[RANK_V];
    int VD01_dims[RANK_VD01];
    int VFLX_dims[RANK_VFLX];
    int VQ_dims[RANK_VQ];
    int VS_dims[RANK_VS];
    int VT_dims[RANK_VT];
    int VU_dims[RANK_VU];
    int VV_dims[RANK_VV];
    int WGUSTD_dims[RANK_WGUSTD];
    int WTKE_dims[RANK_WTKE];
    int XPH_LWC_dims[RANK_XPH_LWC];
    int Z3_dims[RANK_Z3];
    int airFV_dims[RANK_airFV];
    int bc_a1_dims[RANK_bc_a1];
    int bc_a1DDF_dims[RANK_bc_a1DDF];
    int bc_a1GVF_dims[RANK_bc_a1GVF];
    int bc_a1SFSBC_dims[RANK_bc_a1SFSBC];
    int bc_a1SFSBS_dims[RANK_bc_a1SFSBS];
    int bc_a1SFSIC_dims[RANK_bc_a1SFSIC];
    int bc_a1SFSIS_dims[RANK_bc_a1SFSIS];
    int bc_a1SFWET_dims[RANK_bc_a1SFWET];
    int bc_a1TBF_dims[RANK_bc_a1TBF];
    int bc_a1_CLXF_dims[RANK_bc_a1_CLXF];
    int bc_a1_XFRC_dims[RANK_bc_a1_XFRC];
    int bc_c1_dims[RANK_bc_c1];
    int bc_c1DDF_dims[RANK_bc_c1DDF];
    int bc_c1GVF_dims[RANK_bc_c1GVF];
    int bc_c1SFSBC_dims[RANK_bc_c1SFSBC];
    int bc_c1SFSBS_dims[RANK_bc_c1SFSBS];
    int bc_c1SFSIC_dims[RANK_bc_c1SFSIC];
    int bc_c1SFSIS_dims[RANK_bc_c1SFSIS];
    int bc_c1SFWET_dims[RANK_bc_c1SFWET];
    int bc_c1TBF_dims[RANK_bc_c1TBF];
    int chem_trop_dims[RANK_chem_trop];
    int chem_trop_tropop_dims[RANK_chem_trop_tropop];
    int dgnd_a01_dims[RANK_dgnd_a01];
    int dgnd_a02_dims[RANK_dgnd_a02];
    int dgnd_a03_dims[RANK_dgnd_a03];
    int dgnw_a01_dims[RANK_dgnw_a01];
    int dgnw_a02_dims[RANK_dgnw_a02];
    int dgnw_a03_dims[RANK_dgnw_a03];
    int dst_a1_dims[RANK_dst_a1];
    int dst_a1DDF_dims[RANK_dst_a1DDF];
    int dst_a1GVF_dims[RANK_dst_a1GVF];
    int dst_a1SF_dims[RANK_dst_a1SF];
    int dst_a1SFSBC_dims[RANK_dst_a1SFSBC];
    int dst_a1SFSBS_dims[RANK_dst_a1SFSBS];
    int dst_a1SFSIC_dims[RANK_dst_a1SFSIC];
    int dst_a1SFSIS_dims[RANK_dst_a1SFSIS];
    int dst_a1SFWET_dims[RANK_dst_a1SFWET];
    int dst_a1TBF_dims[RANK_dst_a1TBF];
    int dst_a3_dims[RANK_dst_a3];
    int dst_a3DDF_dims[RANK_dst_a3DDF];
    int dst_a3GVF_dims[RANK_dst_a3GVF];
    int dst_a3SF_dims[RANK_dst_a3SF];
    int dst_a3SFSBC_dims[RANK_dst_a3SFSBC];
    int dst_a3SFSBS_dims[RANK_dst_a3SFSBS];
    int dst_a3SFSIC_dims[RANK_dst_a3SFSIC];
    int dst_a3SFSIS_dims[RANK_dst_a3SFSIS];
    int dst_a3SFWET_dims[RANK_dst_a3SFWET];
    int dst_a3TBF_dims[RANK_dst_a3TBF];
    int dst_c1_dims[RANK_dst_c1];
    int dst_c1DDF_dims[RANK_dst_c1DDF];
    int dst_c1GVF_dims[RANK_dst_c1GVF];
    int dst_c1SFSBC_dims[RANK_dst_c1SFSBC];
    int dst_c1SFSBS_dims[RANK_dst_c1SFSBS];
    int dst_c1SFSIC_dims[RANK_dst_c1SFSIC];
    int dst_c1SFSIS_dims[RANK_dst_c1SFSIS];
    int dst_c1SFWET_dims[RANK_dst_c1SFWET];
    int dst_c1TBF_dims[RANK_dst_c1TBF];
    int dst_c3_dims[RANK_dst_c3];
    int dst_c3DDF_dims[RANK_dst_c3DDF];
    int dst_c3GVF_dims[RANK_dst_c3GVF];
    int dst_c3SFSBC_dims[RANK_dst_c3SFSBC];
    int dst_c3SFSBS_dims[RANK_dst_c3SFSBS];
    int dst_c3SFSIC_dims[RANK_dst_c3SFSIC];
    int dst_c3SFSIS_dims[RANK_dst_c3SFSIS];
    int dst_c3SFWET_dims[RANK_dst_c3SFWET];
    int dst_c3TBF_dims[RANK_dst_c3TBF];
    int ncl_a1_dims[RANK_ncl_a1];
    int ncl_a1DDF_dims[RANK_ncl_a1DDF];
    int ncl_a1GVF_dims[RANK_ncl_a1GVF];
    int ncl_a1SF_dims[RANK_ncl_a1SF];
    int ncl_a1SFSBC_dims[RANK_ncl_a1SFSBC];
    int ncl_a1SFSBS_dims[RANK_ncl_a1SFSBS];
    int ncl_a1SFSIC_dims[RANK_ncl_a1SFSIC];
    int ncl_a1SFSIS_dims[RANK_ncl_a1SFSIS];
    int ncl_a1SFWET_dims[RANK_ncl_a1SFWET];
    int ncl_a1TBF_dims[RANK_ncl_a1TBF];
    int ncl_a1_sfcoag1_dims[RANK_ncl_a1_sfcoag1];
    int ncl_a1_sfcsiz3_dims[RANK_ncl_a1_sfcsiz3];
    int ncl_a1_sfcsiz4_dims[RANK_ncl_a1_sfcsiz4];
    int ncl_a1_sfgaex2_dims[RANK_ncl_a1_sfgaex2];
    int ncl_a2_dims[RANK_ncl_a2];
    int ncl_a2DDF_dims[RANK_ncl_a2DDF];
    int ncl_a2GVF_dims[RANK_ncl_a2GVF];
    int ncl_a2SF_dims[RANK_ncl_a2SF];
    int ncl_a2SFSBC_dims[RANK_ncl_a2SFSBC];
    int ncl_a2SFSBS_dims[RANK_ncl_a2SFSBS];
    int ncl_a2SFSIC_dims[RANK_ncl_a2SFSIC];
    int ncl_a2SFSIS_dims[RANK_ncl_a2SFSIS];
    int ncl_a2SFWET_dims[RANK_ncl_a2SFWET];
    int ncl_a2TBF_dims[RANK_ncl_a2TBF];
    int ncl_a2_sfcoag1_dims[RANK_ncl_a2_sfcoag1];
    int ncl_a2_sfcsiz3_dims[RANK_ncl_a2_sfcsiz3];
    int ncl_a2_sfcsiz4_dims[RANK_ncl_a2_sfcsiz4];
    int ncl_a2_sfgaex2_dims[RANK_ncl_a2_sfgaex2];
    int ncl_a3_dims[RANK_ncl_a3];
    int ncl_a3DDF_dims[RANK_ncl_a3DDF];
    int ncl_a3GVF_dims[RANK_ncl_a3GVF];
    int ncl_a3SF_dims[RANK_ncl_a3SF];
    int ncl_a3SFSBC_dims[RANK_ncl_a3SFSBC];
    int ncl_a3SFSBS_dims[RANK_ncl_a3SFSBS];
    int ncl_a3SFSIC_dims[RANK_ncl_a3SFSIC];
    int ncl_a3SFSIS_dims[RANK_ncl_a3SFSIS];
    int ncl_a3SFWET_dims[RANK_ncl_a3SFWET];
    int ncl_a3TBF_dims[RANK_ncl_a3TBF];
    int ncl_c1_dims[RANK_ncl_c1];
    int ncl_c1DDF_dims[RANK_ncl_c1DDF];
    int ncl_c1GVF_dims[RANK_ncl_c1GVF];
    int ncl_c1SFSBC_dims[RANK_ncl_c1SFSBC];
    int ncl_c1SFSBS_dims[RANK_ncl_c1SFSBS];
    int ncl_c1SFSIC_dims[RANK_ncl_c1SFSIC];
    int ncl_c1SFSIS_dims[RANK_ncl_c1SFSIS];
    int ncl_c1SFWET_dims[RANK_ncl_c1SFWET];
    int ncl_c1TBF_dims[RANK_ncl_c1TBF];
    int ncl_c1_sfcsiz3_dims[RANK_ncl_c1_sfcsiz3];
    int ncl_c1_sfcsiz4_dims[RANK_ncl_c1_sfcsiz4];
    int ncl_c1_sfgaex2_dims[RANK_ncl_c1_sfgaex2];
    int ncl_c2_dims[RANK_ncl_c2];
    int ncl_c2DDF_dims[RANK_ncl_c2DDF];
    int ncl_c2GVF_dims[RANK_ncl_c2GVF];
    int ncl_c2SFSBC_dims[RANK_ncl_c2SFSBC];
    int ncl_c2SFSBS_dims[RANK_ncl_c2SFSBS];
    int ncl_c2SFSIC_dims[RANK_ncl_c2SFSIC];
    int ncl_c2SFSIS_dims[RANK_ncl_c2SFSIS];
    int ncl_c2SFWET_dims[RANK_ncl_c2SFWET];
    int ncl_c2TBF_dims[RANK_ncl_c2TBF];
    int ncl_c2_sfcsiz3_dims[RANK_ncl_c2_sfcsiz3];
    int ncl_c2_sfcsiz4_dims[RANK_ncl_c2_sfcsiz4];
    int ncl_c2_sfgaex2_dims[RANK_ncl_c2_sfgaex2];
    int ncl_c3_dims[RANK_ncl_c3];
    int ncl_c3DDF_dims[RANK_ncl_c3DDF];
    int ncl_c3GVF_dims[RANK_ncl_c3GVF];
    int ncl_c3SFSBC_dims[RANK_ncl_c3SFSBC];
    int ncl_c3SFSBS_dims[RANK_ncl_c3SFSBS];
    int ncl_c3SFSIC_dims[RANK_ncl_c3SFSIC];
    int ncl_c3SFSIS_dims[RANK_ncl_c3SFSIS];
    int ncl_c3SFWET_dims[RANK_ncl_c3SFWET];
    int ncl_c3TBF_dims[RANK_ncl_c3TBF];
    int num_a1_dims[RANK_num_a1];
    int num_a1DDF_dims[RANK_num_a1DDF];
    int num_a1GVF_dims[RANK_num_a1GVF];
    int num_a1SFSBC_dims[RANK_num_a1SFSBC];
    int num_a1SFSBS_dims[RANK_num_a1SFSBS];
    int num_a1SFSIC_dims[RANK_num_a1SFSIC];
    int num_a1SFSIS_dims[RANK_num_a1SFSIS];
    int num_a1SFWET_dims[RANK_num_a1SFWET];
    int num_a1TBF_dims[RANK_num_a1TBF];
    int num_a1_CLXF_dims[RANK_num_a1_CLXF];
    int num_a1_XFRC_dims[RANK_num_a1_XFRC];
    int num_a1_sfcoag1_dims[RANK_num_a1_sfcoag1];
    int num_a1_sfcsiz1_dims[RANK_num_a1_sfcsiz1];
    int num_a1_sfcsiz2_dims[RANK_num_a1_sfcsiz2];
    int num_a1_sfcsiz3_dims[RANK_num_a1_sfcsiz3];
    int num_a1_sfcsiz4_dims[RANK_num_a1_sfcsiz4];
    int num_a1_sfgaex2_dims[RANK_num_a1_sfgaex2];
    int num_a2_dims[RANK_num_a2];
    int num_a2DDF_dims[RANK_num_a2DDF];
    int num_a2GVF_dims[RANK_num_a2GVF];
    int num_a2SFSBC_dims[RANK_num_a2SFSBC];
    int num_a2SFSBS_dims[RANK_num_a2SFSBS];
    int num_a2SFSIC_dims[RANK_num_a2SFSIC];
    int num_a2SFSIS_dims[RANK_num_a2SFSIS];
    int num_a2SFWET_dims[RANK_num_a2SFWET];
    int num_a2TBF_dims[RANK_num_a2TBF];
    int num_a2_CLXF_dims[RANK_num_a2_CLXF];
    int num_a2_XFRC_dims[RANK_num_a2_XFRC];
    int num_a2_sfcoag1_dims[RANK_num_a2_sfcoag1];
    int num_a2_sfcsiz1_dims[RANK_num_a2_sfcsiz1];
    int num_a2_sfcsiz2_dims[RANK_num_a2_sfcsiz2];
    int num_a2_sfcsiz3_dims[RANK_num_a2_sfcsiz3];
    int num_a2_sfcsiz4_dims[RANK_num_a2_sfcsiz4];
    int num_a2_sfgaex2_dims[RANK_num_a2_sfgaex2];
    int num_a2_sfnnuc1_dims[RANK_num_a2_sfnnuc1];
    int num_a3_dims[RANK_num_a3];
    int num_a3DDF_dims[RANK_num_a3DDF];
    int num_a3GVF_dims[RANK_num_a3GVF];
    int num_a3SFSBC_dims[RANK_num_a3SFSBC];
    int num_a3SFSBS_dims[RANK_num_a3SFSBS];
    int num_a3SFSIC_dims[RANK_num_a3SFSIC];
    int num_a3SFSIS_dims[RANK_num_a3SFSIS];
    int num_a3SFWET_dims[RANK_num_a3SFWET];
    int num_a3TBF_dims[RANK_num_a3TBF];
    int num_a3_sfcsiz1_dims[RANK_num_a3_sfcsiz1];
    int num_a3_sfcsiz2_dims[RANK_num_a3_sfcsiz2];
    int num_c1_dims[RANK_num_c1];
    int num_c1DDF_dims[RANK_num_c1DDF];
    int num_c1GVF_dims[RANK_num_c1GVF];
    int num_c1SFSBC_dims[RANK_num_c1SFSBC];
    int num_c1SFSBS_dims[RANK_num_c1SFSBS];
    int num_c1SFSIC_dims[RANK_num_c1SFSIC];
    int num_c1SFSIS_dims[RANK_num_c1SFSIS];
    int num_c1SFWET_dims[RANK_num_c1SFWET];
    int num_c1TBF_dims[RANK_num_c1TBF];
    int num_c1_sfcsiz1_dims[RANK_num_c1_sfcsiz1];
    int num_c1_sfcsiz2_dims[RANK_num_c1_sfcsiz2];
    int num_c1_sfcsiz3_dims[RANK_num_c1_sfcsiz3];
    int num_c1_sfcsiz4_dims[RANK_num_c1_sfcsiz4];
    int num_c1_sfgaex2_dims[RANK_num_c1_sfgaex2];
    int num_c2_dims[RANK_num_c2];
    int num_c2DDF_dims[RANK_num_c2DDF];
    int num_c2GVF_dims[RANK_num_c2GVF];
    int num_c2SFSBC_dims[RANK_num_c2SFSBC];
    int num_c2SFSBS_dims[RANK_num_c2SFSBS];
    int num_c2SFSIC_dims[RANK_num_c2SFSIC];
    int num_c2SFSIS_dims[RANK_num_c2SFSIS];
    int num_c2SFWET_dims[RANK_num_c2SFWET];
    int num_c2TBF_dims[RANK_num_c2TBF];
    int num_c2_sfcsiz1_dims[RANK_num_c2_sfcsiz1];
    int num_c2_sfcsiz2_dims[RANK_num_c2_sfcsiz2];
    int num_c2_sfcsiz3_dims[RANK_num_c2_sfcsiz3];
    int num_c2_sfcsiz4_dims[RANK_num_c2_sfcsiz4];
    int num_c2_sfgaex2_dims[RANK_num_c2_sfgaex2];
    int num_c3_dims[RANK_num_c3];
    int num_c3DDF_dims[RANK_num_c3DDF];
    int num_c3GVF_dims[RANK_num_c3GVF];
    int num_c3SFSBC_dims[RANK_num_c3SFSBC];
    int num_c3SFSBS_dims[RANK_num_c3SFSBS];
    int num_c3SFSIC_dims[RANK_num_c3SFSIC];
    int num_c3SFSIS_dims[RANK_num_c3SFSIS];
    int num_c3SFWET_dims[RANK_num_c3SFWET];
    int num_c3TBF_dims[RANK_num_c3TBF];
    int num_c3_sfcsiz1_dims[RANK_num_c3_sfcsiz1];
    int num_c3_sfcsiz2_dims[RANK_num_c3_sfcsiz2];
    int pom_a1_dims[RANK_pom_a1];
    int pom_a1DDF_dims[RANK_pom_a1DDF];
    int pom_a1GVF_dims[RANK_pom_a1GVF];
    int pom_a1SFSBC_dims[RANK_pom_a1SFSBC];
    int pom_a1SFSBS_dims[RANK_pom_a1SFSBS];
    int pom_a1SFSIC_dims[RANK_pom_a1SFSIC];
    int pom_a1SFSIS_dims[RANK_pom_a1SFSIS];
    int pom_a1SFWET_dims[RANK_pom_a1SFWET];
    int pom_a1TBF_dims[RANK_pom_a1TBF];
    int pom_a1_CLXF_dims[RANK_pom_a1_CLXF];
    int pom_a1_XFRC_dims[RANK_pom_a1_XFRC];
    int pom_c1_dims[RANK_pom_c1];
    int pom_c1DDF_dims[RANK_pom_c1DDF];
    int pom_c1GVF_dims[RANK_pom_c1GVF];
    int pom_c1SFSBC_dims[RANK_pom_c1SFSBC];
    int pom_c1SFSBS_dims[RANK_pom_c1SFSBS];
    int pom_c1SFSIC_dims[RANK_pom_c1SFSIC];
    int pom_c1SFSIS_dims[RANK_pom_c1SFSIS];
    int pom_c1SFWET_dims[RANK_pom_c1SFWET];
    int pom_c1TBF_dims[RANK_pom_c1TBF];
    int so4_a1_dims[RANK_so4_a1];
    int so4_a1DDF_dims[RANK_so4_a1DDF];
    int so4_a1GVF_dims[RANK_so4_a1GVF];
    int so4_a1SFSBC_dims[RANK_so4_a1SFSBC];
    int so4_a1SFSBS_dims[RANK_so4_a1SFSBS];
    int so4_a1SFSIC_dims[RANK_so4_a1SFSIC];
    int so4_a1SFSIS_dims[RANK_so4_a1SFSIS];
    int so4_a1SFWET_dims[RANK_so4_a1SFWET];
    int so4_a1TBF_dims[RANK_so4_a1TBF];
    int so4_a1_CLXF_dims[RANK_so4_a1_CLXF];
    int so4_a1_XFRC_dims[RANK_so4_a1_XFRC];
    int so4_a1_sfcoag1_dims[RANK_so4_a1_sfcoag1];
    int so4_a1_sfcsiz3_dims[RANK_so4_a1_sfcsiz3];
    int so4_a1_sfcsiz4_dims[RANK_so4_a1_sfcsiz4];
    int so4_a1_sfgaex1_dims[RANK_so4_a1_sfgaex1];
    int so4_a1_sfgaex2_dims[RANK_so4_a1_sfgaex2];
    int so4_a2_dims[RANK_so4_a2];
    int so4_a2DDF_dims[RANK_so4_a2DDF];
    int so4_a2GVF_dims[RANK_so4_a2GVF];
    int so4_a2SFSBC_dims[RANK_so4_a2SFSBC];
    int so4_a2SFSBS_dims[RANK_so4_a2SFSBS];
    int so4_a2SFSIC_dims[RANK_so4_a2SFSIC];
    int so4_a2SFSIS_dims[RANK_so4_a2SFSIS];
    int so4_a2SFWET_dims[RANK_so4_a2SFWET];
    int so4_a2TBF_dims[RANK_so4_a2TBF];
    int so4_a2_CLXF_dims[RANK_so4_a2_CLXF];
    int so4_a2_XFRC_dims[RANK_so4_a2_XFRC];
    int so4_a2_sfcoag1_dims[RANK_so4_a2_sfcoag1];
    int so4_a2_sfcsiz3_dims[RANK_so4_a2_sfcsiz3];
    int so4_a2_sfcsiz4_dims[RANK_so4_a2_sfcsiz4];
    int so4_a2_sfgaex1_dims[RANK_so4_a2_sfgaex1];
    int so4_a2_sfgaex2_dims[RANK_so4_a2_sfgaex2];
    int so4_a2_sfnnuc1_dims[RANK_so4_a2_sfnnuc1];
    int so4_a3_dims[RANK_so4_a3];
    int so4_a3DDF_dims[RANK_so4_a3DDF];
    int so4_a3GVF_dims[RANK_so4_a3GVF];
    int so4_a3SFSBC_dims[RANK_so4_a3SFSBC];
    int so4_a3SFSBS_dims[RANK_so4_a3SFSBS];
    int so4_a3SFSIC_dims[RANK_so4_a3SFSIC];
    int so4_a3SFSIS_dims[RANK_so4_a3SFSIS];
    int so4_a3SFWET_dims[RANK_so4_a3SFWET];
    int so4_a3TBF_dims[RANK_so4_a3TBF];
    int so4_a3_sfgaex1_dims[RANK_so4_a3_sfgaex1];
    int so4_c1_dims[RANK_so4_c1];
    int so4_c1AQH2SO4_dims[RANK_so4_c1AQH2SO4];
    int so4_c1AQSO4_dims[RANK_so4_c1AQSO4];
    int so4_c1DDF_dims[RANK_so4_c1DDF];
    int so4_c1GVF_dims[RANK_so4_c1GVF];
    int so4_c1SFSBC_dims[RANK_so4_c1SFSBC];
    int so4_c1SFSBS_dims[RANK_so4_c1SFSBS];
    int so4_c1SFSIC_dims[RANK_so4_c1SFSIC];
    int so4_c1SFSIS_dims[RANK_so4_c1SFSIS];
    int so4_c1SFWET_dims[RANK_so4_c1SFWET];
    int so4_c1TBF_dims[RANK_so4_c1TBF];
    int so4_c1_sfcsiz3_dims[RANK_so4_c1_sfcsiz3];
    int so4_c1_sfcsiz4_dims[RANK_so4_c1_sfcsiz4];
    int so4_c1_sfgaex2_dims[RANK_so4_c1_sfgaex2];
    int so4_c2_dims[RANK_so4_c2];
    int so4_c2AQH2SO4_dims[RANK_so4_c2AQH2SO4];
    int so4_c2AQSO4_dims[RANK_so4_c2AQSO4];
    int so4_c2DDF_dims[RANK_so4_c2DDF];
    int so4_c2GVF_dims[RANK_so4_c2GVF];
    int so4_c2SFSBC_dims[RANK_so4_c2SFSBC];
    int so4_c2SFSBS_dims[RANK_so4_c2SFSBS];
    int so4_c2SFSIC_dims[RANK_so4_c2SFSIC];
    int so4_c2SFSIS_dims[RANK_so4_c2SFSIS];
    int so4_c2SFWET_dims[RANK_so4_c2SFWET];
    int so4_c2TBF_dims[RANK_so4_c2TBF];
    int so4_c2_sfcsiz3_dims[RANK_so4_c2_sfcsiz3];
    int so4_c2_sfcsiz4_dims[RANK_so4_c2_sfcsiz4];
    int so4_c2_sfgaex2_dims[RANK_so4_c2_sfgaex2];
    int so4_c3_dims[RANK_so4_c3];
    int so4_c3AQH2SO4_dims[RANK_so4_c3AQH2SO4];
    int so4_c3AQSO4_dims[RANK_so4_c3AQSO4];
    int so4_c3DDF_dims[RANK_so4_c3DDF];
    int so4_c3GVF_dims[RANK_so4_c3GVF];
    int so4_c3SFSBC_dims[RANK_so4_c3SFSBC];
    int so4_c3SFSBS_dims[RANK_so4_c3SFSBS];
    int so4_c3SFSIC_dims[RANK_so4_c3SFSIC];
    int so4_c3SFSIS_dims[RANK_so4_c3SFSIS];
    int so4_c3SFWET_dims[RANK_so4_c3SFWET];
    int so4_c3TBF_dims[RANK_so4_c3TBF];
    int soa_a1_dims[RANK_soa_a1];
    int soa_a1DDF_dims[RANK_soa_a1DDF];
    int soa_a1GVF_dims[RANK_soa_a1GVF];
    int soa_a1SFSBC_dims[RANK_soa_a1SFSBC];
    int soa_a1SFSBS_dims[RANK_soa_a1SFSBS];
    int soa_a1SFSIC_dims[RANK_soa_a1SFSIC];
    int soa_a1SFSIS_dims[RANK_soa_a1SFSIS];
    int soa_a1SFWET_dims[RANK_soa_a1SFWET];
    int soa_a1TBF_dims[RANK_soa_a1TBF];
    int soa_a1_sfcoag1_dims[RANK_soa_a1_sfcoag1];
    int soa_a1_sfcsiz3_dims[RANK_soa_a1_sfcsiz3];
    int soa_a1_sfcsiz4_dims[RANK_soa_a1_sfcsiz4];
    int soa_a1_sfgaex1_dims[RANK_soa_a1_sfgaex1];
    int soa_a1_sfgaex2_dims[RANK_soa_a1_sfgaex2];
    int soa_a2_dims[RANK_soa_a2];
    int soa_a2DDF_dims[RANK_soa_a2DDF];
    int soa_a2GVF_dims[RANK_soa_a2GVF];
    int soa_a2SFSBC_dims[RANK_soa_a2SFSBC];
    int soa_a2SFSBS_dims[RANK_soa_a2SFSBS];
    int soa_a2SFSIC_dims[RANK_soa_a2SFSIC];
    int soa_a2SFSIS_dims[RANK_soa_a2SFSIS];
    int soa_a2SFWET_dims[RANK_soa_a2SFWET];
    int soa_a2TBF_dims[RANK_soa_a2TBF];
    int soa_a2_sfcoag1_dims[RANK_soa_a2_sfcoag1];
    int soa_a2_sfcsiz3_dims[RANK_soa_a2_sfcsiz3];
    int soa_a2_sfcsiz4_dims[RANK_soa_a2_sfcsiz4];
    int soa_a2_sfgaex1_dims[RANK_soa_a2_sfgaex1];
    int soa_a2_sfgaex2_dims[RANK_soa_a2_sfgaex2];
    int soa_c1_dims[RANK_soa_c1];
    int soa_c1DDF_dims[RANK_soa_c1DDF];
    int soa_c1GVF_dims[RANK_soa_c1GVF];
    int soa_c1SFSBC_dims[RANK_soa_c1SFSBC];
    int soa_c1SFSBS_dims[RANK_soa_c1SFSBS];
    int soa_c1SFSIC_dims[RANK_soa_c1SFSIC];
    int soa_c1SFSIS_dims[RANK_soa_c1SFSIS];
    int soa_c1SFWET_dims[RANK_soa_c1SFWET];
    int soa_c1TBF_dims[RANK_soa_c1TBF];
    int soa_c1_sfcsiz3_dims[RANK_soa_c1_sfcsiz3];
    int soa_c1_sfcsiz4_dims[RANK_soa_c1_sfcsiz4];
    int soa_c1_sfgaex2_dims[RANK_soa_c1_sfgaex2];
    int soa_c2_dims[RANK_soa_c2];
    int soa_c2DDF_dims[RANK_soa_c2DDF];
    int soa_c2GVF_dims[RANK_soa_c2GVF];
    int soa_c2SFSBC_dims[RANK_soa_c2SFSBC];
    int soa_c2SFSBS_dims[RANK_soa_c2SFSBS];
    int soa_c2SFSIC_dims[RANK_soa_c2SFSIC];
    int soa_c2SFSIS_dims[RANK_soa_c2SFSIS];
    int soa_c2SFWET_dims[RANK_soa_c2SFWET];
    int soa_c2TBF_dims[RANK_soa_c2TBF];
    int soa_c2_sfcsiz3_dims[RANK_soa_c2_sfcsiz3];
    int soa_c2_sfcsiz4_dims[RANK_soa_c2_sfcsiz4];
    int soa_c2_sfgaex2_dims[RANK_soa_c2_sfgaex2];
    int wat_a1_dims[RANK_wat_a1];
    int wat_a2_dims[RANK_wat_a2];
    int wat_a3_dims[RANK_wat_a3];

    /* enter define mode */
    stat = nc_create("ref_camrun.nc", NC_CLOBBER, &ncid);
    check_err(stat,__LINE__,__FILE__);

    /* define dimensions */
    stat = nc_def_dim(ncid, "lat", lat_len, &lat_dim);
    check_err(stat,__LINE__,__FILE__);
    stat = nc_def_dim(ncid, "lon", lon_len, &lon_dim);
    check_err(stat,__LINE__,__FILE__);
    stat = nc_def_dim(ncid, "slat", slat_len, &slat_dim);
    check_err(stat,__LINE__,__FILE__);
    stat = nc_def_dim(ncid, "slon", slon_len, &slon_dim);
    check_err(stat,__LINE__,__FILE__);
    stat = nc_def_dim(ncid, "lev", lev_len, &lev_dim);
    check_err(stat,__LINE__,__FILE__);
    stat = nc_def_dim(ncid, "ilev", ilev_len, &ilev_dim);
    check_err(stat,__LINE__,__FILE__);
    stat = nc_def_dim(ncid, "isccp_prs", isccp_prs_len, &isccp_prs_dim);
    check_err(stat,__LINE__,__FILE__);
    stat = nc_def_dim(ncid, "isccp_tau", isccp_tau_len, &isccp_tau_dim);
    check_err(stat,__LINE__,__FILE__);
    stat = nc_def_dim(ncid, "isccp_prstau", isccp_prstau_len, &isccp_prstau_dim);
    check_err(stat,__LINE__,__FILE__);
    stat = nc_def_dim(ncid, "time", time_len, &time_dim);
    check_err(stat,__LINE__,__FILE__);
    stat = nc_def_dim(ncid, "tbnd", tbnd_len, &tbnd_dim);
    check_err(stat,__LINE__,__FILE__);
    stat = nc_def_dim(ncid, "chars", chars_len, &chars_dim);
    check_err(stat,__LINE__,__FILE__);

    /* define variables */

    stat = nc_def_var(ncid, "P0", NC_DOUBLE, RANK_P0, 0, &P0_id);
    check_err(stat,__LINE__,__FILE__);

    lat_dims[0] = lat_dim;
    stat = nc_def_var(ncid, "lat", NC_DOUBLE, RANK_lat, lat_dims, &lat_id);
    check_err(stat,__LINE__,__FILE__);

    lon_dims[0] = lon_dim;
    stat = nc_def_var(ncid, "lon", NC_DOUBLE, RANK_lon, lon_dims, &lon_id);
    check_err(stat,__LINE__,__FILE__);

    slat_dims[0] = slat_dim;
    stat = nc_def_var(ncid, "slat", NC_DOUBLE, RANK_slat, slat_dims, &slat_id);
    check_err(stat,__LINE__,__FILE__);

    slon_dims[0] = slon_dim;
    stat = nc_def_var(ncid, "slon", NC_DOUBLE, RANK_slon, slon_dims, &slon_id);
    check_err(stat,__LINE__,__FILE__);

    w_stag_dims[0] = slat_dim;
    stat = nc_def_var(ncid, "w_stag", NC_DOUBLE, RANK_w_stag, w_stag_dims, &w_stag_id);
    check_err(stat,__LINE__,__FILE__);

    lev_dims[0] = lev_dim;
    stat = nc_def_var(ncid, "lev", NC_DOUBLE, RANK_lev, lev_dims, &lev_id);
    check_err(stat,__LINE__,__FILE__);

    ilev_dims[0] = ilev_dim;
    stat = nc_def_var(ncid, "ilev", NC_DOUBLE, RANK_ilev, ilev_dims, &ilev_id);
    check_err(stat,__LINE__,__FILE__);

    isccp_prs_dims[0] = isccp_prs_dim;
    stat = nc_def_var(ncid, "isccp_prs", NC_DOUBLE, RANK_isccp_prs, isccp_prs_dims, &isccp_prs_id);
    check_err(stat,__LINE__,__FILE__);

    isccp_tau_dims[0] = isccp_tau_dim;
    stat = nc_def_var(ncid, "isccp_tau", NC_DOUBLE, RANK_isccp_tau, isccp_tau_dims, &isccp_tau_id);
    check_err(stat,__LINE__,__FILE__);

    isccp_prstau_dims[0] = isccp_prstau_dim;
    stat = nc_def_var(ncid, "isccp_prstau", NC_DOUBLE, RANK_isccp_prstau, isccp_prstau_dims, &isccp_prstau_id);
    check_err(stat,__LINE__,__FILE__);

    time_dims[0] = time_dim;
    stat = nc_def_var(ncid, "time", NC_DOUBLE, RANK_time, time_dims, &time_id);
    check_err(stat,__LINE__,__FILE__);

    time_bnds_dims[0] = time_dim;
    time_bnds_dims[1] = tbnd_dim;
    stat = nc_def_var(ncid, "time_bnds", NC_DOUBLE, RANK_time_bnds, time_bnds_dims, &time_bnds_id);
    check_err(stat,__LINE__,__FILE__);

    date_written_dims[0] = time_dim;
    date_written_dims[1] = chars_dim;
    stat = nc_def_var(ncid, "date_written", NC_CHAR, RANK_date_written, date_written_dims, &date_written_id);
    check_err(stat,__LINE__,__FILE__);

    time_written_dims[0] = time_dim;
    time_written_dims[1] = chars_dim;
    stat = nc_def_var(ncid, "time_written", NC_CHAR, RANK_time_written, time_written_dims, &time_written_id);
    check_err(stat,__LINE__,__FILE__);

    stat = nc_def_var(ncid, "ntrm", NC_INT, RANK_ntrm, 0, &ntrm_id);
    check_err(stat,__LINE__,__FILE__);

    stat = nc_def_var(ncid, "ntrn", NC_INT, RANK_ntrn, 0, &ntrn_id);
    check_err(stat,__LINE__,__FILE__);

    stat = nc_def_var(ncid, "ntrk", NC_INT, RANK_ntrk, 0, &ntrk_id);
    check_err(stat,__LINE__,__FILE__);

    stat = nc_def_var(ncid, "ndbase", NC_INT, RANK_ndbase, 0, &ndbase_id);
    check_err(stat,__LINE__,__FILE__);

    stat = nc_def_var(ncid, "nsbase", NC_INT, RANK_nsbase, 0, &nsbase_id);
    check_err(stat,__LINE__,__FILE__);

    stat = nc_def_var(ncid, "nbdate", NC_INT, RANK_nbdate, 0, &nbdate_id);
    check_err(stat,__LINE__,__FILE__);

    stat = nc_def_var(ncid, "nbsec", NC_INT, RANK_nbsec, 0, &nbsec_id);
    check_err(stat,__LINE__,__FILE__);

    stat = nc_def_var(ncid, "mdt", NC_INT, RANK_mdt, 0, &mdt_id);
    check_err(stat,__LINE__,__FILE__);

    nlon_dims[0] = lat_dim;
    stat = nc_def_var(ncid, "nlon", NC_INT, RANK_nlon, nlon_dims, &nlon_id);
    check_err(stat,__LINE__,__FILE__);

    wnummax_dims[0] = lat_dim;
    stat = nc_def_var(ncid, "wnummax", NC_INT, RANK_wnummax, wnummax_dims, &wnummax_id);
    check_err(stat,__LINE__,__FILE__);

    hyai_dims[0] = ilev_dim;
    stat = nc_def_var(ncid, "hyai", NC_DOUBLE, RANK_hyai, hyai_dims, &hyai_id);
    check_err(stat,__LINE__,__FILE__);

    hybi_dims[0] = ilev_dim;
    stat = nc_def_var(ncid, "hybi", NC_DOUBLE, RANK_hybi, hybi_dims, &hybi_id);
    check_err(stat,__LINE__,__FILE__);

    hyam_dims[0] = lev_dim;
    stat = nc_def_var(ncid, "hyam", NC_DOUBLE, RANK_hyam, hyam_dims, &hyam_id);
    check_err(stat,__LINE__,__FILE__);

    hybm_dims[0] = lev_dim;
    stat = nc_def_var(ncid, "hybm", NC_DOUBLE, RANK_hybm, hybm_dims, &hybm_id);
    check_err(stat,__LINE__,__FILE__);

    gw_dims[0] = lat_dim;
    stat = nc_def_var(ncid, "gw", NC_DOUBLE, RANK_gw, gw_dims, &gw_id);
    check_err(stat,__LINE__,__FILE__);

    ndcur_dims[0] = time_dim;
    stat = nc_def_var(ncid, "ndcur", NC_INT, RANK_ndcur, ndcur_dims, &ndcur_id);
    check_err(stat,__LINE__,__FILE__);

    nscur_dims[0] = time_dim;
    stat = nc_def_var(ncid, "nscur", NC_INT, RANK_nscur, nscur_dims, &nscur_id);
    check_err(stat,__LINE__,__FILE__);

    date_dims[0] = time_dim;
    stat = nc_def_var(ncid, "date", NC_INT, RANK_date, date_dims, &date_id);
    check_err(stat,__LINE__,__FILE__);

    co2vmr_dims[0] = time_dim;
    stat = nc_def_var(ncid, "co2vmr", NC_DOUBLE, RANK_co2vmr, co2vmr_dims, &co2vmr_id);
    check_err(stat,__LINE__,__FILE__);

    ch4vmr_dims[0] = time_dim;
    stat = nc_def_var(ncid, "ch4vmr", NC_DOUBLE, RANK_ch4vmr, ch4vmr_dims, &ch4vmr_id);
    check_err(stat,__LINE__,__FILE__);

    n2ovmr_dims[0] = time_dim;
    stat = nc_def_var(ncid, "n2ovmr", NC_DOUBLE, RANK_n2ovmr, n2ovmr_dims, &n2ovmr_id);
    check_err(stat,__LINE__,__FILE__);

    f11vmr_dims[0] = time_dim;
    stat = nc_def_var(ncid, "f11vmr", NC_DOUBLE, RANK_f11vmr, f11vmr_dims, &f11vmr_id);
    check_err(stat,__LINE__,__FILE__);

    f12vmr_dims[0] = time_dim;
    stat = nc_def_var(ncid, "f12vmr", NC_DOUBLE, RANK_f12vmr, f12vmr_dims, &f12vmr_id);
    check_err(stat,__LINE__,__FILE__);

    sol_tsi_dims[0] = time_dim;
    stat = nc_def_var(ncid, "sol_tsi", NC_DOUBLE, RANK_sol_tsi, sol_tsi_dims, &sol_tsi_id);
    check_err(stat,__LINE__,__FILE__);

    datesec_dims[0] = time_dim;
    stat = nc_def_var(ncid, "datesec", NC_INT, RANK_datesec, datesec_dims, &datesec_id);
    check_err(stat,__LINE__,__FILE__);

    nsteph_dims[0] = time_dim;
    stat = nc_def_var(ncid, "nsteph", NC_INT, RANK_nsteph, nsteph_dims, &nsteph_id);
    check_err(stat,__LINE__,__FILE__);

    ABSORB_dims[0] = time_dim;
    ABSORB_dims[1] = lev_dim;
    ABSORB_dims[2] = lat_dim;
    ABSORB_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "ABSORB", NC_DOUBLE, RANK_ABSORB, ABSORB_dims, &ABSORB_id);
    check_err(stat,__LINE__,__FILE__);

    AEROD_v_dims[0] = time_dim;
    AEROD_v_dims[1] = lat_dim;
    AEROD_v_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "AEROD_v", NC_DOUBLE, RANK_AEROD_v, AEROD_v_dims, &AEROD_v_id);
    check_err(stat,__LINE__,__FILE__);

    AODABS_dims[0] = time_dim;
    AODABS_dims[1] = lat_dim;
    AODABS_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "AODABS", NC_DOUBLE, RANK_AODABS, AODABS_dims, &AODABS_id);
    check_err(stat,__LINE__,__FILE__);

    AODDUST1_dims[0] = time_dim;
    AODDUST1_dims[1] = lat_dim;
    AODDUST1_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "AODDUST1", NC_DOUBLE, RANK_AODDUST1, AODDUST1_dims, &AODDUST1_id);
    check_err(stat,__LINE__,__FILE__);

    AODDUST2_dims[0] = time_dim;
    AODDUST2_dims[1] = lat_dim;
    AODDUST2_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "AODDUST2", NC_DOUBLE, RANK_AODDUST2, AODDUST2_dims, &AODDUST2_id);
    check_err(stat,__LINE__,__FILE__);

    AODDUST3_dims[0] = time_dim;
    AODDUST3_dims[1] = lat_dim;
    AODDUST3_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "AODDUST3", NC_DOUBLE, RANK_AODDUST3, AODDUST3_dims, &AODDUST3_id);
    check_err(stat,__LINE__,__FILE__);

    AODMODE1_dims[0] = time_dim;
    AODMODE1_dims[1] = lat_dim;
    AODMODE1_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "AODMODE1", NC_DOUBLE, RANK_AODMODE1, AODMODE1_dims, &AODMODE1_id);
    check_err(stat,__LINE__,__FILE__);

    AODMODE2_dims[0] = time_dim;
    AODMODE2_dims[1] = lat_dim;
    AODMODE2_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "AODMODE2", NC_DOUBLE, RANK_AODMODE2, AODMODE2_dims, &AODMODE2_id);
    check_err(stat,__LINE__,__FILE__);

    AODMODE3_dims[0] = time_dim;
    AODMODE3_dims[1] = lat_dim;
    AODMODE3_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "AODMODE3", NC_DOUBLE, RANK_AODMODE3, AODMODE3_dims, &AODMODE3_id);
    check_err(stat,__LINE__,__FILE__);

    AODVIS_dims[0] = time_dim;
    AODVIS_dims[1] = lat_dim;
    AODVIS_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "AODVIS", NC_DOUBLE, RANK_AODVIS, AODVIS_dims, &AODVIS_id);
    check_err(stat,__LINE__,__FILE__);

    AQSO4_H2O2_dims[0] = time_dim;
    AQSO4_H2O2_dims[1] = lat_dim;
    AQSO4_H2O2_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "AQSO4_H2O2", NC_DOUBLE, RANK_AQSO4_H2O2, AQSO4_H2O2_dims, &AQSO4_H2O2_id);
    check_err(stat,__LINE__,__FILE__);

    AQSO4_O3_dims[0] = time_dim;
    AQSO4_O3_dims[1] = lat_dim;
    AQSO4_O3_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "AQSO4_O3", NC_DOUBLE, RANK_AQSO4_O3, AQSO4_O3_dims, &AQSO4_O3_id);
    check_err(stat,__LINE__,__FILE__);

    AQ_DMS_dims[0] = time_dim;
    AQ_DMS_dims[1] = lat_dim;
    AQ_DMS_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "AQ_DMS", NC_DOUBLE, RANK_AQ_DMS, AQ_DMS_dims, &AQ_DMS_id);
    check_err(stat,__LINE__,__FILE__);

    AQ_H2O2_dims[0] = time_dim;
    AQ_H2O2_dims[1] = lat_dim;
    AQ_H2O2_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "AQ_H2O2", NC_DOUBLE, RANK_AQ_H2O2, AQ_H2O2_dims, &AQ_H2O2_id);
    check_err(stat,__LINE__,__FILE__);

    AQ_H2SO4_dims[0] = time_dim;
    AQ_H2SO4_dims[1] = lat_dim;
    AQ_H2SO4_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "AQ_H2SO4", NC_DOUBLE, RANK_AQ_H2SO4, AQ_H2SO4_dims, &AQ_H2SO4_id);
    check_err(stat,__LINE__,__FILE__);

    AQ_SO2_dims[0] = time_dim;
    AQ_SO2_dims[1] = lat_dim;
    AQ_SO2_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "AQ_SO2", NC_DOUBLE, RANK_AQ_SO2, AQ_SO2_dims, &AQ_SO2_id);
    check_err(stat,__LINE__,__FILE__);

    AQ_SOAG_dims[0] = time_dim;
    AQ_SOAG_dims[1] = lat_dim;
    AQ_SOAG_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "AQ_SOAG", NC_DOUBLE, RANK_AQ_SOAG, AQ_SOAG_dims, &AQ_SOAG_id);
    check_err(stat,__LINE__,__FILE__);

    AQ_bc_a1_dims[0] = time_dim;
    AQ_bc_a1_dims[1] = lat_dim;
    AQ_bc_a1_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "AQ_bc_a1", NC_DOUBLE, RANK_AQ_bc_a1, AQ_bc_a1_dims, &AQ_bc_a1_id);
    check_err(stat,__LINE__,__FILE__);

    AQ_dst_a1_dims[0] = time_dim;
    AQ_dst_a1_dims[1] = lat_dim;
    AQ_dst_a1_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "AQ_dst_a1", NC_DOUBLE, RANK_AQ_dst_a1, AQ_dst_a1_dims, &AQ_dst_a1_id);
    check_err(stat,__LINE__,__FILE__);

    AQ_dst_a3_dims[0] = time_dim;
    AQ_dst_a3_dims[1] = lat_dim;
    AQ_dst_a3_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "AQ_dst_a3", NC_DOUBLE, RANK_AQ_dst_a3, AQ_dst_a3_dims, &AQ_dst_a3_id);
    check_err(stat,__LINE__,__FILE__);

    AQ_ncl_a1_dims[0] = time_dim;
    AQ_ncl_a1_dims[1] = lat_dim;
    AQ_ncl_a1_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "AQ_ncl_a1", NC_DOUBLE, RANK_AQ_ncl_a1, AQ_ncl_a1_dims, &AQ_ncl_a1_id);
    check_err(stat,__LINE__,__FILE__);

    AQ_ncl_a2_dims[0] = time_dim;
    AQ_ncl_a2_dims[1] = lat_dim;
    AQ_ncl_a2_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "AQ_ncl_a2", NC_DOUBLE, RANK_AQ_ncl_a2, AQ_ncl_a2_dims, &AQ_ncl_a2_id);
    check_err(stat,__LINE__,__FILE__);

    AQ_ncl_a3_dims[0] = time_dim;
    AQ_ncl_a3_dims[1] = lat_dim;
    AQ_ncl_a3_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "AQ_ncl_a3", NC_DOUBLE, RANK_AQ_ncl_a3, AQ_ncl_a3_dims, &AQ_ncl_a3_id);
    check_err(stat,__LINE__,__FILE__);

    AQ_num_a1_dims[0] = time_dim;
    AQ_num_a1_dims[1] = lat_dim;
    AQ_num_a1_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "AQ_num_a1", NC_DOUBLE, RANK_AQ_num_a1, AQ_num_a1_dims, &AQ_num_a1_id);
    check_err(stat,__LINE__,__FILE__);

    AQ_num_a2_dims[0] = time_dim;
    AQ_num_a2_dims[1] = lat_dim;
    AQ_num_a2_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "AQ_num_a2", NC_DOUBLE, RANK_AQ_num_a2, AQ_num_a2_dims, &AQ_num_a2_id);
    check_err(stat,__LINE__,__FILE__);

    AQ_num_a3_dims[0] = time_dim;
    AQ_num_a3_dims[1] = lat_dim;
    AQ_num_a3_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "AQ_num_a3", NC_DOUBLE, RANK_AQ_num_a3, AQ_num_a3_dims, &AQ_num_a3_id);
    check_err(stat,__LINE__,__FILE__);

    AQ_pom_a1_dims[0] = time_dim;
    AQ_pom_a1_dims[1] = lat_dim;
    AQ_pom_a1_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "AQ_pom_a1", NC_DOUBLE, RANK_AQ_pom_a1, AQ_pom_a1_dims, &AQ_pom_a1_id);
    check_err(stat,__LINE__,__FILE__);

    AQ_so4_a1_dims[0] = time_dim;
    AQ_so4_a1_dims[1] = lat_dim;
    AQ_so4_a1_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "AQ_so4_a1", NC_DOUBLE, RANK_AQ_so4_a1, AQ_so4_a1_dims, &AQ_so4_a1_id);
    check_err(stat,__LINE__,__FILE__);

    AQ_so4_a2_dims[0] = time_dim;
    AQ_so4_a2_dims[1] = lat_dim;
    AQ_so4_a2_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "AQ_so4_a2", NC_DOUBLE, RANK_AQ_so4_a2, AQ_so4_a2_dims, &AQ_so4_a2_id);
    check_err(stat,__LINE__,__FILE__);

    AQ_so4_a3_dims[0] = time_dim;
    AQ_so4_a3_dims[1] = lat_dim;
    AQ_so4_a3_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "AQ_so4_a3", NC_DOUBLE, RANK_AQ_so4_a3, AQ_so4_a3_dims, &AQ_so4_a3_id);
    check_err(stat,__LINE__,__FILE__);

    AQ_soa_a1_dims[0] = time_dim;
    AQ_soa_a1_dims[1] = lat_dim;
    AQ_soa_a1_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "AQ_soa_a1", NC_DOUBLE, RANK_AQ_soa_a1, AQ_soa_a1_dims, &AQ_soa_a1_id);
    check_err(stat,__LINE__,__FILE__);

    AQ_soa_a2_dims[0] = time_dim;
    AQ_soa_a2_dims[1] = lat_dim;
    AQ_soa_a2_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "AQ_soa_a2", NC_DOUBLE, RANK_AQ_soa_a2, AQ_soa_a2_dims, &AQ_soa_a2_id);
    check_err(stat,__LINE__,__FILE__);

    BPROD_dims[0] = time_dim;
    BPROD_dims[1] = ilev_dim;
    BPROD_dims[2] = lat_dim;
    BPROD_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "BPROD", NC_DOUBLE, RANK_BPROD, BPROD_dims, &BPROD_id);
    check_err(stat,__LINE__,__FILE__);

    BURDEN1_dims[0] = time_dim;
    BURDEN1_dims[1] = lat_dim;
    BURDEN1_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "BURDEN1", NC_DOUBLE, RANK_BURDEN1, BURDEN1_dims, &BURDEN1_id);
    check_err(stat,__LINE__,__FILE__);

    BURDEN2_dims[0] = time_dim;
    BURDEN2_dims[1] = lat_dim;
    BURDEN2_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "BURDEN2", NC_DOUBLE, RANK_BURDEN2, BURDEN2_dims, &BURDEN2_id);
    check_err(stat,__LINE__,__FILE__);

    BURDEN3_dims[0] = time_dim;
    BURDEN3_dims[1] = lat_dim;
    BURDEN3_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "BURDEN3", NC_DOUBLE, RANK_BURDEN3, BURDEN3_dims, &BURDEN3_id);
    check_err(stat,__LINE__,__FILE__);

    CCN1_dims[0] = time_dim;
    CCN1_dims[1] = lev_dim;
    CCN1_dims[2] = lat_dim;
    CCN1_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "CCN1", NC_DOUBLE, RANK_CCN1, CCN1_dims, &CCN1_id);
    check_err(stat,__LINE__,__FILE__);

    CCN2_dims[0] = time_dim;
    CCN2_dims[1] = lev_dim;
    CCN2_dims[2] = lat_dim;
    CCN2_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "CCN2", NC_DOUBLE, RANK_CCN2, CCN2_dims, &CCN2_id);
    check_err(stat,__LINE__,__FILE__);

    CCN3_dims[0] = time_dim;
    CCN3_dims[1] = lev_dim;
    CCN3_dims[2] = lat_dim;
    CCN3_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "CCN3", NC_DOUBLE, RANK_CCN3, CCN3_dims, &CCN3_id);
    check_err(stat,__LINE__,__FILE__);

    CCN4_dims[0] = time_dim;
    CCN4_dims[1] = lev_dim;
    CCN4_dims[2] = lat_dim;
    CCN4_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "CCN4", NC_DOUBLE, RANK_CCN4, CCN4_dims, &CCN4_id);
    check_err(stat,__LINE__,__FILE__);

    CCN5_dims[0] = time_dim;
    CCN5_dims[1] = lev_dim;
    CCN5_dims[2] = lat_dim;
    CCN5_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "CCN5", NC_DOUBLE, RANK_CCN5, CCN5_dims, &CCN5_id);
    check_err(stat,__LINE__,__FILE__);

    CCN6_dims[0] = time_dim;
    CCN6_dims[1] = lev_dim;
    CCN6_dims[2] = lat_dim;
    CCN6_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "CCN6", NC_DOUBLE, RANK_CCN6, CCN6_dims, &CCN6_id);
    check_err(stat,__LINE__,__FILE__);

    CLDHGH_dims[0] = time_dim;
    CLDHGH_dims[1] = lat_dim;
    CLDHGH_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "CLDHGH", NC_DOUBLE, RANK_CLDHGH, CLDHGH_dims, &CLDHGH_id);
    check_err(stat,__LINE__,__FILE__);

    CLDICE_dims[0] = time_dim;
    CLDICE_dims[1] = lev_dim;
    CLDICE_dims[2] = lat_dim;
    CLDICE_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "CLDICE", NC_DOUBLE, RANK_CLDICE, CLDICE_dims, &CLDICE_id);
    check_err(stat,__LINE__,__FILE__);

    CLDLIQ_dims[0] = time_dim;
    CLDLIQ_dims[1] = lev_dim;
    CLDLIQ_dims[2] = lat_dim;
    CLDLIQ_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "CLDLIQ", NC_DOUBLE, RANK_CLDLIQ, CLDLIQ_dims, &CLDLIQ_id);
    check_err(stat,__LINE__,__FILE__);

    CLDLOW_dims[0] = time_dim;
    CLDLOW_dims[1] = lat_dim;
    CLDLOW_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "CLDLOW", NC_DOUBLE, RANK_CLDLOW, CLDLOW_dims, &CLDLOW_id);
    check_err(stat,__LINE__,__FILE__);

    CLDMED_dims[0] = time_dim;
    CLDMED_dims[1] = lat_dim;
    CLDMED_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "CLDMED", NC_DOUBLE, RANK_CLDMED, CLDMED_dims, &CLDMED_id);
    check_err(stat,__LINE__,__FILE__);

    CLDTOT_dims[0] = time_dim;
    CLDTOT_dims[1] = lat_dim;
    CLDTOT_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "CLDTOT", NC_DOUBLE, RANK_CLDTOT, CLDTOT_dims, &CLDTOT_id);
    check_err(stat,__LINE__,__FILE__);

    CLOUD_dims[0] = time_dim;
    CLOUD_dims[1] = lev_dim;
    CLOUD_dims[2] = lat_dim;
    CLOUD_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "CLOUD", NC_DOUBLE, RANK_CLOUD, CLOUD_dims, &CLOUD_id);
    check_err(stat,__LINE__,__FILE__);

    CMFDQ_dims[0] = time_dim;
    CMFDQ_dims[1] = lev_dim;
    CMFDQ_dims[2] = lat_dim;
    CMFDQ_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "CMFDQ", NC_DOUBLE, RANK_CMFDQ, CMFDQ_dims, &CMFDQ_id);
    check_err(stat,__LINE__,__FILE__);

    CMFDQR_dims[0] = time_dim;
    CMFDQR_dims[1] = lev_dim;
    CMFDQR_dims[2] = lat_dim;
    CMFDQR_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "CMFDQR", NC_DOUBLE, RANK_CMFDQR, CMFDQR_dims, &CMFDQR_id);
    check_err(stat,__LINE__,__FILE__);

    CMFDT_dims[0] = time_dim;
    CMFDT_dims[1] = lev_dim;
    CMFDT_dims[2] = lat_dim;
    CMFDT_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "CMFDT", NC_DOUBLE, RANK_CMFDT, CMFDT_dims, &CMFDT_id);
    check_err(stat,__LINE__,__FILE__);

    CMFMC_dims[0] = time_dim;
    CMFMC_dims[1] = ilev_dim;
    CMFMC_dims[2] = lat_dim;
    CMFMC_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "CMFMC", NC_DOUBLE, RANK_CMFMC, CMFMC_dims, &CMFMC_id);
    check_err(stat,__LINE__,__FILE__);

    CMFMCDZM_dims[0] = time_dim;
    CMFMCDZM_dims[1] = ilev_dim;
    CMFMCDZM_dims[2] = lat_dim;
    CMFMCDZM_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "CMFMCDZM", NC_DOUBLE, RANK_CMFMCDZM, CMFMCDZM_dims, &CMFMCDZM_id);
    check_err(stat,__LINE__,__FILE__);

    CONCLD_dims[0] = time_dim;
    CONCLD_dims[1] = lev_dim;
    CONCLD_dims[2] = lat_dim;
    CONCLD_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "CONCLD", NC_DOUBLE, RANK_CONCLD, CONCLD_dims, &CONCLD_id);
    check_err(stat,__LINE__,__FILE__);

    DCQ_dims[0] = time_dim;
    DCQ_dims[1] = lev_dim;
    DCQ_dims[2] = lat_dim;
    DCQ_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "DCQ", NC_DOUBLE, RANK_DCQ, DCQ_dims, &DCQ_id);
    check_err(stat,__LINE__,__FILE__);

    DMS_dims[0] = time_dim;
    DMS_dims[1] = lev_dim;
    DMS_dims[2] = lat_dim;
    DMS_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "DMS", NC_DOUBLE, RANK_DMS, DMS_dims, &DMS_id);
    check_err(stat,__LINE__,__FILE__);

    DSTODXC_dims[0] = time_dim;
    DSTODXC_dims[1] = lat_dim;
    DSTODXC_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "DSTODXC", NC_DOUBLE, RANK_DSTODXC, DSTODXC_dims, &DSTODXC_id);
    check_err(stat,__LINE__,__FILE__);

    DSTSFDRY_dims[0] = time_dim;
    DSTSFDRY_dims[1] = lat_dim;
    DSTSFDRY_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "DSTSFDRY", NC_DOUBLE, RANK_DSTSFDRY, DSTSFDRY_dims, &DSTSFDRY_id);
    check_err(stat,__LINE__,__FILE__);

    DSTSFMBL_dims[0] = time_dim;
    DSTSFMBL_dims[1] = lat_dim;
    DSTSFMBL_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "DSTSFMBL", NC_DOUBLE, RANK_DSTSFMBL, DSTSFMBL_dims, &DSTSFMBL_id);
    check_err(stat,__LINE__,__FILE__);

    DSTSFWET_dims[0] = time_dim;
    DSTSFWET_dims[1] = lat_dim;
    DSTSFWET_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "DSTSFWET", NC_DOUBLE, RANK_DSTSFWET, DSTSFWET_dims, &DSTSFWET_id);
    check_err(stat,__LINE__,__FILE__);

    DTCOND_dims[0] = time_dim;
    DTCOND_dims[1] = lev_dim;
    DTCOND_dims[2] = lat_dim;
    DTCOND_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "DTCOND", NC_DOUBLE, RANK_DTCOND, DTCOND_dims, &DTCOND_id);
    check_err(stat,__LINE__,__FILE__);

    DTV_dims[0] = time_dim;
    DTV_dims[1] = lev_dim;
    DTV_dims[2] = lat_dim;
    DTV_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "DTV", NC_DOUBLE, RANK_DTV, DTV_dims, &DTV_id);
    check_err(stat,__LINE__,__FILE__);

    EXTINCT_dims[0] = time_dim;
    EXTINCT_dims[1] = lev_dim;
    EXTINCT_dims[2] = lat_dim;
    EXTINCT_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "EXTINCT", NC_DOUBLE, RANK_EXTINCT, EXTINCT_dims, &EXTINCT_id);
    check_err(stat,__LINE__,__FILE__);

    FICE_dims[0] = time_dim;
    FICE_dims[1] = lev_dim;
    FICE_dims[2] = lat_dim;
    FICE_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "FICE", NC_DOUBLE, RANK_FICE, FICE_dims, &FICE_id);
    check_err(stat,__LINE__,__FILE__);

    FLDS_dims[0] = time_dim;
    FLDS_dims[1] = lat_dim;
    FLDS_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "FLDS", NC_DOUBLE, RANK_FLDS, FLDS_dims, &FLDS_id);
    check_err(stat,__LINE__,__FILE__);

    FLNS_dims[0] = time_dim;
    FLNS_dims[1] = lat_dim;
    FLNS_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "FLNS", NC_DOUBLE, RANK_FLNS, FLNS_dims, &FLNS_id);
    check_err(stat,__LINE__,__FILE__);

    FLNSC_dims[0] = time_dim;
    FLNSC_dims[1] = lat_dim;
    FLNSC_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "FLNSC", NC_DOUBLE, RANK_FLNSC, FLNSC_dims, &FLNSC_id);
    check_err(stat,__LINE__,__FILE__);

    FLNT_dims[0] = time_dim;
    FLNT_dims[1] = lat_dim;
    FLNT_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "FLNT", NC_DOUBLE, RANK_FLNT, FLNT_dims, &FLNT_id);
    check_err(stat,__LINE__,__FILE__);

    FLNTC_dims[0] = time_dim;
    FLNTC_dims[1] = lat_dim;
    FLNTC_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "FLNTC", NC_DOUBLE, RANK_FLNTC, FLNTC_dims, &FLNTC_id);
    check_err(stat,__LINE__,__FILE__);

    FLUT_dims[0] = time_dim;
    FLUT_dims[1] = lat_dim;
    FLUT_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "FLUT", NC_DOUBLE, RANK_FLUT, FLUT_dims, &FLUT_id);
    check_err(stat,__LINE__,__FILE__);

    FLUTC_dims[0] = time_dim;
    FLUTC_dims[1] = lat_dim;
    FLUTC_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "FLUTC", NC_DOUBLE, RANK_FLUTC, FLUTC_dims, &FLUTC_id);
    check_err(stat,__LINE__,__FILE__);

    FREQSH_dims[0] = time_dim;
    FREQSH_dims[1] = lat_dim;
    FREQSH_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "FREQSH", NC_DOUBLE, RANK_FREQSH, FREQSH_dims, &FREQSH_id);
    check_err(stat,__LINE__,__FILE__);

    FREQZM_dims[0] = time_dim;
    FREQZM_dims[1] = lat_dim;
    FREQZM_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "FREQZM", NC_DOUBLE, RANK_FREQZM, FREQZM_dims, &FREQZM_id);
    check_err(stat,__LINE__,__FILE__);

    FSDS_dims[0] = time_dim;
    FSDS_dims[1] = lat_dim;
    FSDS_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "FSDS", NC_DOUBLE, RANK_FSDS, FSDS_dims, &FSDS_id);
    check_err(stat,__LINE__,__FILE__);

    FSDSC_dims[0] = time_dim;
    FSDSC_dims[1] = lat_dim;
    FSDSC_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "FSDSC", NC_DOUBLE, RANK_FSDSC, FSDSC_dims, &FSDSC_id);
    check_err(stat,__LINE__,__FILE__);

    FSNS_dims[0] = time_dim;
    FSNS_dims[1] = lat_dim;
    FSNS_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "FSNS", NC_DOUBLE, RANK_FSNS, FSNS_dims, &FSNS_id);
    check_err(stat,__LINE__,__FILE__);

    FSNSC_dims[0] = time_dim;
    FSNSC_dims[1] = lat_dim;
    FSNSC_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "FSNSC", NC_DOUBLE, RANK_FSNSC, FSNSC_dims, &FSNSC_id);
    check_err(stat,__LINE__,__FILE__);

    FSNT_dims[0] = time_dim;
    FSNT_dims[1] = lat_dim;
    FSNT_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "FSNT", NC_DOUBLE, RANK_FSNT, FSNT_dims, &FSNT_id);
    check_err(stat,__LINE__,__FILE__);

    FSNTC_dims[0] = time_dim;
    FSNTC_dims[1] = lat_dim;
    FSNTC_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "FSNTC", NC_DOUBLE, RANK_FSNTC, FSNTC_dims, &FSNTC_id);
    check_err(stat,__LINE__,__FILE__);

    FSNTOA_dims[0] = time_dim;
    FSNTOA_dims[1] = lat_dim;
    FSNTOA_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "FSNTOA", NC_DOUBLE, RANK_FSNTOA, FSNTOA_dims, &FSNTOA_id);
    check_err(stat,__LINE__,__FILE__);

    FSNTOAC_dims[0] = time_dim;
    FSNTOAC_dims[1] = lat_dim;
    FSNTOAC_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "FSNTOAC", NC_DOUBLE, RANK_FSNTOAC, FSNTOAC_dims, &FSNTOAC_id);
    check_err(stat,__LINE__,__FILE__);

    FSUTOA_dims[0] = time_dim;
    FSUTOA_dims[1] = lat_dim;
    FSUTOA_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "FSUTOA", NC_DOUBLE, RANK_FSUTOA, FSUTOA_dims, &FSUTOA_id);
    check_err(stat,__LINE__,__FILE__);

    GS_DMS_dims[0] = time_dim;
    GS_DMS_dims[1] = lat_dim;
    GS_DMS_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "GS_DMS", NC_DOUBLE, RANK_GS_DMS, GS_DMS_dims, &GS_DMS_id);
    check_err(stat,__LINE__,__FILE__);

    GS_H2O2_dims[0] = time_dim;
    GS_H2O2_dims[1] = lat_dim;
    GS_H2O2_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "GS_H2O2", NC_DOUBLE, RANK_GS_H2O2, GS_H2O2_dims, &GS_H2O2_id);
    check_err(stat,__LINE__,__FILE__);

    GS_H2SO4_dims[0] = time_dim;
    GS_H2SO4_dims[1] = lat_dim;
    GS_H2SO4_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "GS_H2SO4", NC_DOUBLE, RANK_GS_H2SO4, GS_H2SO4_dims, &GS_H2SO4_id);
    check_err(stat,__LINE__,__FILE__);

    GS_SO2_dims[0] = time_dim;
    GS_SO2_dims[1] = lat_dim;
    GS_SO2_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "GS_SO2", NC_DOUBLE, RANK_GS_SO2, GS_SO2_dims, &GS_SO2_id);
    check_err(stat,__LINE__,__FILE__);

    GS_SOAG_dims[0] = time_dim;
    GS_SOAG_dims[1] = lat_dim;
    GS_SOAG_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "GS_SOAG", NC_DOUBLE, RANK_GS_SOAG, GS_SOAG_dims, &GS_SOAG_id);
    check_err(stat,__LINE__,__FILE__);

    GS_bc_a1_dims[0] = time_dim;
    GS_bc_a1_dims[1] = lat_dim;
    GS_bc_a1_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "GS_bc_a1", NC_DOUBLE, RANK_GS_bc_a1, GS_bc_a1_dims, &GS_bc_a1_id);
    check_err(stat,__LINE__,__FILE__);

    GS_dst_a1_dims[0] = time_dim;
    GS_dst_a1_dims[1] = lat_dim;
    GS_dst_a1_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "GS_dst_a1", NC_DOUBLE, RANK_GS_dst_a1, GS_dst_a1_dims, &GS_dst_a1_id);
    check_err(stat,__LINE__,__FILE__);

    GS_dst_a3_dims[0] = time_dim;
    GS_dst_a3_dims[1] = lat_dim;
    GS_dst_a3_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "GS_dst_a3", NC_DOUBLE, RANK_GS_dst_a3, GS_dst_a3_dims, &GS_dst_a3_id);
    check_err(stat,__LINE__,__FILE__);

    GS_ncl_a1_dims[0] = time_dim;
    GS_ncl_a1_dims[1] = lat_dim;
    GS_ncl_a1_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "GS_ncl_a1", NC_DOUBLE, RANK_GS_ncl_a1, GS_ncl_a1_dims, &GS_ncl_a1_id);
    check_err(stat,__LINE__,__FILE__);

    GS_ncl_a2_dims[0] = time_dim;
    GS_ncl_a2_dims[1] = lat_dim;
    GS_ncl_a2_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "GS_ncl_a2", NC_DOUBLE, RANK_GS_ncl_a2, GS_ncl_a2_dims, &GS_ncl_a2_id);
    check_err(stat,__LINE__,__FILE__);

    GS_ncl_a3_dims[0] = time_dim;
    GS_ncl_a3_dims[1] = lat_dim;
    GS_ncl_a3_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "GS_ncl_a3", NC_DOUBLE, RANK_GS_ncl_a3, GS_ncl_a3_dims, &GS_ncl_a3_id);
    check_err(stat,__LINE__,__FILE__);

    GS_num_a1_dims[0] = time_dim;
    GS_num_a1_dims[1] = lat_dim;
    GS_num_a1_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "GS_num_a1", NC_DOUBLE, RANK_GS_num_a1, GS_num_a1_dims, &GS_num_a1_id);
    check_err(stat,__LINE__,__FILE__);

    GS_num_a2_dims[0] = time_dim;
    GS_num_a2_dims[1] = lat_dim;
    GS_num_a2_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "GS_num_a2", NC_DOUBLE, RANK_GS_num_a2, GS_num_a2_dims, &GS_num_a2_id);
    check_err(stat,__LINE__,__FILE__);

    GS_num_a3_dims[0] = time_dim;
    GS_num_a3_dims[1] = lat_dim;
    GS_num_a3_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "GS_num_a3", NC_DOUBLE, RANK_GS_num_a3, GS_num_a3_dims, &GS_num_a3_id);
    check_err(stat,__LINE__,__FILE__);

    GS_pom_a1_dims[0] = time_dim;
    GS_pom_a1_dims[1] = lat_dim;
    GS_pom_a1_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "GS_pom_a1", NC_DOUBLE, RANK_GS_pom_a1, GS_pom_a1_dims, &GS_pom_a1_id);
    check_err(stat,__LINE__,__FILE__);

    GS_so4_a1_dims[0] = time_dim;
    GS_so4_a1_dims[1] = lat_dim;
    GS_so4_a1_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "GS_so4_a1", NC_DOUBLE, RANK_GS_so4_a1, GS_so4_a1_dims, &GS_so4_a1_id);
    check_err(stat,__LINE__,__FILE__);

    GS_so4_a2_dims[0] = time_dim;
    GS_so4_a2_dims[1] = lat_dim;
    GS_so4_a2_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "GS_so4_a2", NC_DOUBLE, RANK_GS_so4_a2, GS_so4_a2_dims, &GS_so4_a2_id);
    check_err(stat,__LINE__,__FILE__);

    GS_so4_a3_dims[0] = time_dim;
    GS_so4_a3_dims[1] = lat_dim;
    GS_so4_a3_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "GS_so4_a3", NC_DOUBLE, RANK_GS_so4_a3, GS_so4_a3_dims, &GS_so4_a3_id);
    check_err(stat,__LINE__,__FILE__);

    GS_soa_a1_dims[0] = time_dim;
    GS_soa_a1_dims[1] = lat_dim;
    GS_soa_a1_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "GS_soa_a1", NC_DOUBLE, RANK_GS_soa_a1, GS_soa_a1_dims, &GS_soa_a1_id);
    check_err(stat,__LINE__,__FILE__);

    GS_soa_a2_dims[0] = time_dim;
    GS_soa_a2_dims[1] = lat_dim;
    GS_soa_a2_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "GS_soa_a2", NC_DOUBLE, RANK_GS_soa_a2, GS_soa_a2_dims, &GS_soa_a2_id);
    check_err(stat,__LINE__,__FILE__);

    H2O2_dims[0] = time_dim;
    H2O2_dims[1] = lev_dim;
    H2O2_dims[2] = lat_dim;
    H2O2_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "H2O2", NC_DOUBLE, RANK_H2O2, H2O2_dims, &H2O2_id);
    check_err(stat,__LINE__,__FILE__);

    H2SO4_dims[0] = time_dim;
    H2SO4_dims[1] = lev_dim;
    H2SO4_dims[2] = lat_dim;
    H2SO4_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "H2SO4", NC_DOUBLE, RANK_H2SO4, H2SO4_dims, &H2SO4_id);
    check_err(stat,__LINE__,__FILE__);

    H2SO4_sfgaex1_dims[0] = time_dim;
    H2SO4_sfgaex1_dims[1] = lat_dim;
    H2SO4_sfgaex1_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "H2SO4_sfgaex1", NC_DOUBLE, RANK_H2SO4_sfgaex1, H2SO4_sfgaex1_dims, &H2SO4_sfgaex1_id);
    check_err(stat,__LINE__,__FILE__);

    H2SO4_sfnnuc1_dims[0] = time_dim;
    H2SO4_sfnnuc1_dims[1] = lat_dim;
    H2SO4_sfnnuc1_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "H2SO4_sfnnuc1", NC_DOUBLE, RANK_H2SO4_sfnnuc1, H2SO4_sfnnuc1_dims, &H2SO4_sfnnuc1_id);
    check_err(stat,__LINE__,__FILE__);

    ICEFRAC_dims[0] = time_dim;
    ICEFRAC_dims[1] = lat_dim;
    ICEFRAC_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "ICEFRAC", NC_DOUBLE, RANK_ICEFRAC, ICEFRAC_dims, &ICEFRAC_id);
    check_err(stat,__LINE__,__FILE__);

    ICIMR_dims[0] = time_dim;
    ICIMR_dims[1] = lev_dim;
    ICIMR_dims[2] = lat_dim;
    ICIMR_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "ICIMR", NC_DOUBLE, RANK_ICIMR, ICIMR_dims, &ICIMR_id);
    check_err(stat,__LINE__,__FILE__);

    ICWMR_dims[0] = time_dim;
    ICWMR_dims[1] = lev_dim;
    ICWMR_dims[2] = lat_dim;
    ICWMR_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "ICWMR", NC_DOUBLE, RANK_ICWMR, ICWMR_dims, &ICWMR_id);
    check_err(stat,__LINE__,__FILE__);

    KVH_dims[0] = time_dim;
    KVH_dims[1] = ilev_dim;
    KVH_dims[2] = lat_dim;
    KVH_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "KVH", NC_DOUBLE, RANK_KVH, KVH_dims, &KVH_id);
    check_err(stat,__LINE__,__FILE__);

    KVM_dims[0] = time_dim;
    KVM_dims[1] = ilev_dim;
    KVM_dims[2] = lat_dim;
    KVM_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "KVM", NC_DOUBLE, RANK_KVM, KVM_dims, &KVM_id);
    check_err(stat,__LINE__,__FILE__);

    LANDFRAC_dims[0] = time_dim;
    LANDFRAC_dims[1] = lat_dim;
    LANDFRAC_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "LANDFRAC", NC_DOUBLE, RANK_LANDFRAC, LANDFRAC_dims, &LANDFRAC_id);
    check_err(stat,__LINE__,__FILE__);

    LCLOUD_dims[0] = time_dim;
    LCLOUD_dims[1] = lev_dim;
    LCLOUD_dims[2] = lat_dim;
    LCLOUD_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "LCLOUD", NC_DOUBLE, RANK_LCLOUD, LCLOUD_dims, &LCLOUD_id);
    check_err(stat,__LINE__,__FILE__);

    LHFLX_dims[0] = time_dim;
    LHFLX_dims[1] = lat_dim;
    LHFLX_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "LHFLX", NC_DOUBLE, RANK_LHFLX, LHFLX_dims, &LHFLX_id);
    check_err(stat,__LINE__,__FILE__);

    LND_MBL_dims[0] = time_dim;
    LND_MBL_dims[1] = lat_dim;
    LND_MBL_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "LND_MBL", NC_DOUBLE, RANK_LND_MBL, LND_MBL_dims, &LND_MBL_id);
    check_err(stat,__LINE__,__FILE__);

    LWCF_dims[0] = time_dim;
    LWCF_dims[1] = lat_dim;
    LWCF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "LWCF", NC_DOUBLE, RANK_LWCF, LWCF_dims, &LWCF_id);
    check_err(stat,__LINE__,__FILE__);

    NDROPCOL_dims[0] = time_dim;
    NDROPCOL_dims[1] = lat_dim;
    NDROPCOL_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "NDROPCOL", NC_DOUBLE, RANK_NDROPCOL, NDROPCOL_dims, &NDROPCOL_id);
    check_err(stat,__LINE__,__FILE__);

    NDROPMIX_dims[0] = time_dim;
    NDROPMIX_dims[1] = lev_dim;
    NDROPMIX_dims[2] = lat_dim;
    NDROPMIX_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "NDROPMIX", NC_DOUBLE, RANK_NDROPMIX, NDROPMIX_dims, &NDROPMIX_id);
    check_err(stat,__LINE__,__FILE__);

    NDROPSNK_dims[0] = time_dim;
    NDROPSNK_dims[1] = lev_dim;
    NDROPSNK_dims[2] = lat_dim;
    NDROPSNK_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "NDROPSNK", NC_DOUBLE, RANK_NDROPSNK, NDROPSNK_dims, &NDROPSNK_id);
    check_err(stat,__LINE__,__FILE__);

    NDROPSRC_dims[0] = time_dim;
    NDROPSRC_dims[1] = lev_dim;
    NDROPSRC_dims[2] = lat_dim;
    NDROPSRC_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "NDROPSRC", NC_DOUBLE, RANK_NDROPSRC, NDROPSRC_dims, &NDROPSRC_id);
    check_err(stat,__LINE__,__FILE__);

    NUMICE_dims[0] = time_dim;
    NUMICE_dims[1] = lev_dim;
    NUMICE_dims[2] = lat_dim;
    NUMICE_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "NUMICE", NC_DOUBLE, RANK_NUMICE, NUMICE_dims, &NUMICE_id);
    check_err(stat,__LINE__,__FILE__);

    NUMLIQ_dims[0] = time_dim;
    NUMLIQ_dims[1] = lev_dim;
    NUMLIQ_dims[2] = lat_dim;
    NUMLIQ_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "NUMLIQ", NC_DOUBLE, RANK_NUMLIQ, NUMLIQ_dims, &NUMLIQ_id);
    check_err(stat,__LINE__,__FILE__);

    OCNFRAC_dims[0] = time_dim;
    OCNFRAC_dims[1] = lat_dim;
    OCNFRAC_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "OCNFRAC", NC_DOUBLE, RANK_OCNFRAC, OCNFRAC_dims, &OCNFRAC_id);
    check_err(stat,__LINE__,__FILE__);

    ODV_bc_a1_dims[0] = time_dim;
    ODV_bc_a1_dims[1] = lat_dim;
    ODV_bc_a1_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "ODV_bc_a1", NC_DOUBLE, RANK_ODV_bc_a1, ODV_bc_a1_dims, &ODV_bc_a1_id);
    check_err(stat,__LINE__,__FILE__);

    ODV_dst_a1_dims[0] = time_dim;
    ODV_dst_a1_dims[1] = lat_dim;
    ODV_dst_a1_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "ODV_dst_a1", NC_DOUBLE, RANK_ODV_dst_a1, ODV_dst_a1_dims, &ODV_dst_a1_id);
    check_err(stat,__LINE__,__FILE__);

    ODV_dst_a3_dims[0] = time_dim;
    ODV_dst_a3_dims[1] = lat_dim;
    ODV_dst_a3_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "ODV_dst_a3", NC_DOUBLE, RANK_ODV_dst_a3, ODV_dst_a3_dims, &ODV_dst_a3_id);
    check_err(stat,__LINE__,__FILE__);

    ODV_ncl_a1_dims[0] = time_dim;
    ODV_ncl_a1_dims[1] = lat_dim;
    ODV_ncl_a1_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "ODV_ncl_a1", NC_DOUBLE, RANK_ODV_ncl_a1, ODV_ncl_a1_dims, &ODV_ncl_a1_id);
    check_err(stat,__LINE__,__FILE__);

    ODV_ncl_a3_dims[0] = time_dim;
    ODV_ncl_a3_dims[1] = lat_dim;
    ODV_ncl_a3_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "ODV_ncl_a3", NC_DOUBLE, RANK_ODV_ncl_a3, ODV_ncl_a3_dims, &ODV_ncl_a3_id);
    check_err(stat,__LINE__,__FILE__);

    ODV_pom_a1_dims[0] = time_dim;
    ODV_pom_a1_dims[1] = lat_dim;
    ODV_pom_a1_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "ODV_pom_a1", NC_DOUBLE, RANK_ODV_pom_a1, ODV_pom_a1_dims, &ODV_pom_a1_id);
    check_err(stat,__LINE__,__FILE__);

    ODV_so4_a1_dims[0] = time_dim;
    ODV_so4_a1_dims[1] = lat_dim;
    ODV_so4_a1_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "ODV_so4_a1", NC_DOUBLE, RANK_ODV_so4_a1, ODV_so4_a1_dims, &ODV_so4_a1_id);
    check_err(stat,__LINE__,__FILE__);

    ODV_soa_a1_dims[0] = time_dim;
    ODV_soa_a1_dims[1] = lat_dim;
    ODV_soa_a1_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "ODV_soa_a1", NC_DOUBLE, RANK_ODV_soa_a1, ODV_soa_a1_dims, &ODV_soa_a1_id);
    check_err(stat,__LINE__,__FILE__);

    OMEGA_dims[0] = time_dim;
    OMEGA_dims[1] = lev_dim;
    OMEGA_dims[2] = lat_dim;
    OMEGA_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "OMEGA", NC_DOUBLE, RANK_OMEGA, OMEGA_dims, &OMEGA_id);
    check_err(stat,__LINE__,__FILE__);

    OMEGAT_dims[0] = time_dim;
    OMEGAT_dims[1] = lev_dim;
    OMEGAT_dims[2] = lat_dim;
    OMEGAT_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "OMEGAT", NC_DOUBLE, RANK_OMEGAT, OMEGAT_dims, &OMEGAT_id);
    check_err(stat,__LINE__,__FILE__);

    ORO_dims[0] = time_dim;
    ORO_dims[1] = lat_dim;
    ORO_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "ORO", NC_DOUBLE, RANK_ORO, ORO_dims, &ORO_id);
    check_err(stat,__LINE__,__FILE__);

    PBLH_dims[0] = time_dim;
    PBLH_dims[1] = lat_dim;
    PBLH_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "PBLH", NC_DOUBLE, RANK_PBLH, PBLH_dims, &PBLH_id);
    check_err(stat,__LINE__,__FILE__);

    PCONVB_dims[0] = time_dim;
    PCONVB_dims[1] = lat_dim;
    PCONVB_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "PCONVB", NC_DOUBLE, RANK_PCONVB, PCONVB_dims, &PCONVB_id);
    check_err(stat,__LINE__,__FILE__);

    PCONVT_dims[0] = time_dim;
    PCONVT_dims[1] = lat_dim;
    PCONVT_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "PCONVT", NC_DOUBLE, RANK_PCONVT, PCONVT_dims, &PCONVT_id);
    check_err(stat,__LINE__,__FILE__);

    PHIS_dims[0] = time_dim;
    PHIS_dims[1] = lat_dim;
    PHIS_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "PHIS", NC_DOUBLE, RANK_PHIS, PHIS_dims, &PHIS_id);
    check_err(stat,__LINE__,__FILE__);

    PRECC_dims[0] = time_dim;
    PRECC_dims[1] = lat_dim;
    PRECC_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "PRECC", NC_DOUBLE, RANK_PRECC, PRECC_dims, &PRECC_id);
    check_err(stat,__LINE__,__FILE__);

    PRECCDZM_dims[0] = time_dim;
    PRECCDZM_dims[1] = lat_dim;
    PRECCDZM_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "PRECCDZM", NC_DOUBLE, RANK_PRECCDZM, PRECCDZM_dims, &PRECCDZM_id);
    check_err(stat,__LINE__,__FILE__);

    PRECL_dims[0] = time_dim;
    PRECL_dims[1] = lat_dim;
    PRECL_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "PRECL", NC_DOUBLE, RANK_PRECL, PRECL_dims, &PRECL_id);
    check_err(stat,__LINE__,__FILE__);

    PRECSC_dims[0] = time_dim;
    PRECSC_dims[1] = lat_dim;
    PRECSC_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "PRECSC", NC_DOUBLE, RANK_PRECSC, PRECSC_dims, &PRECSC_id);
    check_err(stat,__LINE__,__FILE__);

    PRECSH_dims[0] = time_dim;
    PRECSH_dims[1] = lat_dim;
    PRECSH_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "PRECSH", NC_DOUBLE, RANK_PRECSH, PRECSH_dims, &PRECSH_id);
    check_err(stat,__LINE__,__FILE__);

    PRECSL_dims[0] = time_dim;
    PRECSL_dims[1] = lat_dim;
    PRECSL_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "PRECSL", NC_DOUBLE, RANK_PRECSL, PRECSL_dims, &PRECSL_id);
    check_err(stat,__LINE__,__FILE__);

    PRECT_dims[0] = time_dim;
    PRECT_dims[1] = lat_dim;
    PRECT_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "PRECT", NC_DOUBLE, RANK_PRECT, PRECT_dims, &PRECT_id);
    check_err(stat,__LINE__,__FILE__);

    PS_dims[0] = time_dim;
    PS_dims[1] = lat_dim;
    PS_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "PS", NC_DOUBLE, RANK_PS, PS_dims, &PS_id);
    check_err(stat,__LINE__,__FILE__);

    PSL_dims[0] = time_dim;
    PSL_dims[1] = lat_dim;
    PSL_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "PSL", NC_DOUBLE, RANK_PSL, PSL_dims, &PSL_id);
    check_err(stat,__LINE__,__FILE__);

    Q_dims[0] = time_dim;
    Q_dims[1] = lev_dim;
    Q_dims[2] = lat_dim;
    Q_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "Q", NC_DOUBLE, RANK_Q, Q_dims, &Q_id);
    check_err(stat,__LINE__,__FILE__);

    QC_dims[0] = time_dim;
    QC_dims[1] = lev_dim;
    QC_dims[2] = lat_dim;
    QC_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "QC", NC_DOUBLE, RANK_QC, QC_dims, &QC_id);
    check_err(stat,__LINE__,__FILE__);

    QFLX_dims[0] = time_dim;
    QFLX_dims[1] = lat_dim;
    QFLX_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "QFLX", NC_DOUBLE, RANK_QFLX, QFLX_dims, &QFLX_id);
    check_err(stat,__LINE__,__FILE__);

    QREFHT_dims[0] = time_dim;
    QREFHT_dims[1] = lat_dim;
    QREFHT_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "QREFHT", NC_DOUBLE, RANK_QREFHT, QREFHT_dims, &QREFHT_id);
    check_err(stat,__LINE__,__FILE__);

    QRL_dims[0] = time_dim;
    QRL_dims[1] = lev_dim;
    QRL_dims[2] = lat_dim;
    QRL_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "QRL", NC_DOUBLE, RANK_QRL, QRL_dims, &QRL_id);
    check_err(stat,__LINE__,__FILE__);

    QRS_dims[0] = time_dim;
    QRS_dims[1] = lev_dim;
    QRS_dims[2] = lat_dim;
    QRS_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "QRS", NC_DOUBLE, RANK_QRS, QRS_dims, &QRS_id);
    check_err(stat,__LINE__,__FILE__);

    QT_dims[0] = time_dim;
    QT_dims[1] = lev_dim;
    QT_dims[2] = lat_dim;
    QT_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "QT", NC_DOUBLE, RANK_QT, QT_dims, &QT_id);
    check_err(stat,__LINE__,__FILE__);

    QTFLX_dims[0] = time_dim;
    QTFLX_dims[1] = ilev_dim;
    QTFLX_dims[2] = lat_dim;
    QTFLX_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "QTFLX", NC_DOUBLE, RANK_QTFLX, QTFLX_dims, &QTFLX_id);
    check_err(stat,__LINE__,__FILE__);

    RAM1_dims[0] = time_dim;
    RAM1_dims[1] = lat_dim;
    RAM1_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "RAM1", NC_DOUBLE, RANK_RAM1, RAM1_dims, &RAM1_id);
    check_err(stat,__LINE__,__FILE__);

    RELHUM_dims[0] = time_dim;
    RELHUM_dims[1] = lev_dim;
    RELHUM_dims[2] = lat_dim;
    RELHUM_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "RELHUM", NC_DOUBLE, RANK_RELHUM, RELHUM_dims, &RELHUM_id);
    check_err(stat,__LINE__,__FILE__);

    RHREFHT_dims[0] = time_dim;
    RHREFHT_dims[1] = lat_dim;
    RHREFHT_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "RHREFHT", NC_DOUBLE, RANK_RHREFHT, RHREFHT_dims, &RHREFHT_id);
    check_err(stat,__LINE__,__FILE__);

    SFCLDICE_dims[0] = time_dim;
    SFCLDICE_dims[1] = lat_dim;
    SFCLDICE_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "SFCLDICE", NC_DOUBLE, RANK_SFCLDICE, SFCLDICE_dims, &SFCLDICE_id);
    check_err(stat,__LINE__,__FILE__);

    SFCLDLIQ_dims[0] = time_dim;
    SFCLDLIQ_dims[1] = lat_dim;
    SFCLDLIQ_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "SFCLDLIQ", NC_DOUBLE, RANK_SFCLDLIQ, SFCLDLIQ_dims, &SFCLDLIQ_id);
    check_err(stat,__LINE__,__FILE__);

    SFI_dims[0] = time_dim;
    SFI_dims[1] = ilev_dim;
    SFI_dims[2] = lat_dim;
    SFI_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "SFI", NC_DOUBLE, RANK_SFI, SFI_dims, &SFI_id);
    check_err(stat,__LINE__,__FILE__);

    SFNUMICE_dims[0] = time_dim;
    SFNUMICE_dims[1] = lat_dim;
    SFNUMICE_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "SFNUMICE", NC_DOUBLE, RANK_SFNUMICE, SFNUMICE_dims, &SFNUMICE_id);
    check_err(stat,__LINE__,__FILE__);

    SFNUMLIQ_dims[0] = time_dim;
    SFNUMLIQ_dims[1] = lat_dim;
    SFNUMLIQ_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "SFNUMLIQ", NC_DOUBLE, RANK_SFNUMLIQ, SFNUMLIQ_dims, &SFNUMLIQ_id);
    check_err(stat,__LINE__,__FILE__);

    SHFLX_dims[0] = time_dim;
    SHFLX_dims[1] = lat_dim;
    SHFLX_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "SHFLX", NC_DOUBLE, RANK_SHFLX, SHFLX_dims, &SHFLX_id);
    check_err(stat,__LINE__,__FILE__);

    SL_dims[0] = time_dim;
    SL_dims[1] = lev_dim;
    SL_dims[2] = lat_dim;
    SL_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "SL", NC_DOUBLE, RANK_SL, SL_dims, &SL_id);
    check_err(stat,__LINE__,__FILE__);

    SLFLX_dims[0] = time_dim;
    SLFLX_dims[1] = ilev_dim;
    SLFLX_dims[2] = lat_dim;
    SLFLX_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "SLFLX", NC_DOUBLE, RANK_SLFLX, SLFLX_dims, &SLFLX_id);
    check_err(stat,__LINE__,__FILE__);

    SLV_dims[0] = time_dim;
    SLV_dims[1] = lev_dim;
    SLV_dims[2] = lat_dim;
    SLV_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "SLV", NC_DOUBLE, RANK_SLV, SLV_dims, &SLV_id);
    check_err(stat,__LINE__,__FILE__);

    SNOWHICE_dims[0] = time_dim;
    SNOWHICE_dims[1] = lat_dim;
    SNOWHICE_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "SNOWHICE", NC_DOUBLE, RANK_SNOWHICE, SNOWHICE_dims, &SNOWHICE_id);
    check_err(stat,__LINE__,__FILE__);

    SNOWHLND_dims[0] = time_dim;
    SNOWHLND_dims[1] = lat_dim;
    SNOWHLND_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "SNOWHLND", NC_DOUBLE, RANK_SNOWHLND, SNOWHLND_dims, &SNOWHLND_id);
    check_err(stat,__LINE__,__FILE__);

    SO2_dims[0] = time_dim;
    SO2_dims[1] = lev_dim;
    SO2_dims[2] = lat_dim;
    SO2_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "SO2", NC_DOUBLE, RANK_SO2, SO2_dims, &SO2_id);
    check_err(stat,__LINE__,__FILE__);

    SO2_CLXF_dims[0] = time_dim;
    SO2_CLXF_dims[1] = lat_dim;
    SO2_CLXF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "SO2_CLXF", NC_DOUBLE, RANK_SO2_CLXF, SO2_CLXF_dims, &SO2_CLXF_id);
    check_err(stat,__LINE__,__FILE__);

    SO2_XFRC_dims[0] = time_dim;
    SO2_XFRC_dims[1] = lev_dim;
    SO2_XFRC_dims[2] = lat_dim;
    SO2_XFRC_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "SO2_XFRC", NC_DOUBLE, RANK_SO2_XFRC, SO2_XFRC_dims, &SO2_XFRC_id);
    check_err(stat,__LINE__,__FILE__);

    SOAG_dims[0] = time_dim;
    SOAG_dims[1] = lev_dim;
    SOAG_dims[2] = lat_dim;
    SOAG_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "SOAG", NC_DOUBLE, RANK_SOAG, SOAG_dims, &SOAG_id);
    check_err(stat,__LINE__,__FILE__);

    SOAG_sfgaex1_dims[0] = time_dim;
    SOAG_sfgaex1_dims[1] = lat_dim;
    SOAG_sfgaex1_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "SOAG_sfgaex1", NC_DOUBLE, RANK_SOAG_sfgaex1, SOAG_sfgaex1_dims, &SOAG_sfgaex1_id);
    check_err(stat,__LINE__,__FILE__);

    SOLIN_dims[0] = time_dim;
    SOLIN_dims[1] = lat_dim;
    SOLIN_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "SOLIN", NC_DOUBLE, RANK_SOLIN, SOLIN_dims, &SOLIN_id);
    check_err(stat,__LINE__,__FILE__);

    SPROD_dims[0] = time_dim;
    SPROD_dims[1] = ilev_dim;
    SPROD_dims[2] = lat_dim;
    SPROD_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "SPROD", NC_DOUBLE, RANK_SPROD, SPROD_dims, &SPROD_id);
    check_err(stat,__LINE__,__FILE__);

    SRFRAD_dims[0] = time_dim;
    SRFRAD_dims[1] = lat_dim;
    SRFRAD_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "SRFRAD", NC_DOUBLE, RANK_SRFRAD, SRFRAD_dims, &SRFRAD_id);
    check_err(stat,__LINE__,__FILE__);

    SSAVIS_dims[0] = time_dim;
    SSAVIS_dims[1] = lat_dim;
    SSAVIS_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "SSAVIS", NC_DOUBLE, RANK_SSAVIS, SSAVIS_dims, &SSAVIS_id);
    check_err(stat,__LINE__,__FILE__);

    SSTODXC_dims[0] = time_dim;
    SSTODXC_dims[1] = lat_dim;
    SSTODXC_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "SSTODXC", NC_DOUBLE, RANK_SSTODXC, SSTODXC_dims, &SSTODXC_id);
    check_err(stat,__LINE__,__FILE__);

    SSTSFDRY_dims[0] = time_dim;
    SSTSFDRY_dims[1] = lat_dim;
    SSTSFDRY_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "SSTSFDRY", NC_DOUBLE, RANK_SSTSFDRY, SSTSFDRY_dims, &SSTSFDRY_id);
    check_err(stat,__LINE__,__FILE__);

    SSTSFMBL_dims[0] = time_dim;
    SSTSFMBL_dims[1] = lat_dim;
    SSTSFMBL_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "SSTSFMBL", NC_DOUBLE, RANK_SSTSFMBL, SSTSFMBL_dims, &SSTSFMBL_id);
    check_err(stat,__LINE__,__FILE__);

    SSTSFWET_dims[0] = time_dim;
    SSTSFWET_dims[1] = lat_dim;
    SSTSFWET_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "SSTSFWET", NC_DOUBLE, RANK_SSTSFWET, SSTSFWET_dims, &SSTSFWET_id);
    check_err(stat,__LINE__,__FILE__);

    SWCF_dims[0] = time_dim;
    SWCF_dims[1] = lat_dim;
    SWCF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "SWCF", NC_DOUBLE, RANK_SWCF, SWCF_dims, &SWCF_id);
    check_err(stat,__LINE__,__FILE__);

    T_dims[0] = time_dim;
    T_dims[1] = lev_dim;
    T_dims[2] = lat_dim;
    T_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "T", NC_DOUBLE, RANK_T, T_dims, &T_id);
    check_err(stat,__LINE__,__FILE__);

    TAUTMSX_dims[0] = time_dim;
    TAUTMSX_dims[1] = lat_dim;
    TAUTMSX_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "TAUTMSX", NC_DOUBLE, RANK_TAUTMSX, TAUTMSX_dims, &TAUTMSX_id);
    check_err(stat,__LINE__,__FILE__);

    TAUTMSY_dims[0] = time_dim;
    TAUTMSY_dims[1] = lat_dim;
    TAUTMSY_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "TAUTMSY", NC_DOUBLE, RANK_TAUTMSY, TAUTMSY_dims, &TAUTMSY_id);
    check_err(stat,__LINE__,__FILE__);

    TAUX_dims[0] = time_dim;
    TAUX_dims[1] = lat_dim;
    TAUX_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "TAUX", NC_DOUBLE, RANK_TAUX, TAUX_dims, &TAUX_id);
    check_err(stat,__LINE__,__FILE__);

    TAUY_dims[0] = time_dim;
    TAUY_dims[1] = lat_dim;
    TAUY_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "TAUY", NC_DOUBLE, RANK_TAUY, TAUY_dims, &TAUY_id);
    check_err(stat,__LINE__,__FILE__);

    TGCLDCWP_dims[0] = time_dim;
    TGCLDCWP_dims[1] = lat_dim;
    TGCLDCWP_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "TGCLDCWP", NC_DOUBLE, RANK_TGCLDCWP, TGCLDCWP_dims, &TGCLDCWP_id);
    check_err(stat,__LINE__,__FILE__);

    TGCLDIWP_dims[0] = time_dim;
    TGCLDIWP_dims[1] = lat_dim;
    TGCLDIWP_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "TGCLDIWP", NC_DOUBLE, RANK_TGCLDIWP, TGCLDIWP_dims, &TGCLDIWP_id);
    check_err(stat,__LINE__,__FILE__);

    TGCLDLWP_dims[0] = time_dim;
    TGCLDLWP_dims[1] = lat_dim;
    TGCLDLWP_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "TGCLDLWP", NC_DOUBLE, RANK_TGCLDLWP, TGCLDLWP_dims, &TGCLDLWP_id);
    check_err(stat,__LINE__,__FILE__);

    TKE_dims[0] = time_dim;
    TKE_dims[1] = ilev_dim;
    TKE_dims[2] = lat_dim;
    TKE_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "TKE", NC_DOUBLE, RANK_TKE, TKE_dims, &TKE_id);
    check_err(stat,__LINE__,__FILE__);

    TMQ_dims[0] = time_dim;
    TMQ_dims[1] = lat_dim;
    TMQ_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "TMQ", NC_DOUBLE, RANK_TMQ, TMQ_dims, &TMQ_id);
    check_err(stat,__LINE__,__FILE__);

    TREFHT_dims[0] = time_dim;
    TREFHT_dims[1] = lat_dim;
    TREFHT_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "TREFHT", NC_DOUBLE, RANK_TREFHT, TREFHT_dims, &TREFHT_id);
    check_err(stat,__LINE__,__FILE__);

    TREFMNAV_dims[0] = time_dim;
    TREFMNAV_dims[1] = lat_dim;
    TREFMNAV_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "TREFMNAV", NC_DOUBLE, RANK_TREFMNAV, TREFMNAV_dims, &TREFMNAV_id);
    check_err(stat,__LINE__,__FILE__);

    TREFMXAV_dims[0] = time_dim;
    TREFMXAV_dims[1] = lat_dim;
    TREFMXAV_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "TREFMXAV", NC_DOUBLE, RANK_TREFMXAV, TREFMXAV_dims, &TREFMXAV_id);
    check_err(stat,__LINE__,__FILE__);

    TROP_FD_dims[0] = time_dim;
    TROP_FD_dims[1] = lat_dim;
    TROP_FD_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "TROP_FD", NC_DOUBLE, RANK_TROP_FD, TROP_FD_dims, &TROP_FD_id);
    check_err(stat,__LINE__,__FILE__);

    TROP_P_dims[0] = time_dim;
    TROP_P_dims[1] = lat_dim;
    TROP_P_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "TROP_P", NC_DOUBLE, RANK_TROP_P, TROP_P_dims, &TROP_P_id);
    check_err(stat,__LINE__,__FILE__);

    TROP_PD_dims[0] = time_dim;
    TROP_PD_dims[1] = lev_dim;
    TROP_PD_dims[2] = lat_dim;
    TROP_PD_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "TROP_PD", NC_DOUBLE, RANK_TROP_PD, TROP_PD_dims, &TROP_PD_id);
    check_err(stat,__LINE__,__FILE__);

    TROP_T_dims[0] = time_dim;
    TROP_T_dims[1] = lat_dim;
    TROP_T_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "TROP_T", NC_DOUBLE, RANK_TROP_T, TROP_T_dims, &TROP_T_id);
    check_err(stat,__LINE__,__FILE__);

    TROP_Z_dims[0] = time_dim;
    TROP_Z_dims[1] = lat_dim;
    TROP_Z_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "TROP_Z", NC_DOUBLE, RANK_TROP_Z, TROP_Z_dims, &TROP_Z_id);
    check_err(stat,__LINE__,__FILE__);

    TS_dims[0] = time_dim;
    TS_dims[1] = lat_dim;
    TS_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "TS", NC_DOUBLE, RANK_TS, TS_dims, &TS_id);
    check_err(stat,__LINE__,__FILE__);

    TSMN_dims[0] = time_dim;
    TSMN_dims[1] = lat_dim;
    TSMN_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "TSMN", NC_DOUBLE, RANK_TSMN, TSMN_dims, &TSMN_id);
    check_err(stat,__LINE__,__FILE__);

    TSMX_dims[0] = time_dim;
    TSMX_dims[1] = lat_dim;
    TSMX_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "TSMX", NC_DOUBLE, RANK_TSMX, TSMX_dims, &TSMX_id);
    check_err(stat,__LINE__,__FILE__);

    U_dims[0] = time_dim;
    U_dims[1] = lev_dim;
    U_dims[2] = lat_dim;
    U_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "U", NC_DOUBLE, RANK_U, U_dims, &U_id);
    check_err(stat,__LINE__,__FILE__);

    UFLX_dims[0] = time_dim;
    UFLX_dims[1] = ilev_dim;
    UFLX_dims[2] = lat_dim;
    UFLX_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "UFLX", NC_DOUBLE, RANK_UFLX, UFLX_dims, &UFLX_id);
    check_err(stat,__LINE__,__FILE__);

    US_dims[0] = time_dim;
    US_dims[1] = lev_dim;
    US_dims[2] = slat_dim;
    US_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "US", NC_DOUBLE, RANK_US, US_dims, &US_id);
    check_err(stat,__LINE__,__FILE__);

    UU_dims[0] = time_dim;
    UU_dims[1] = lev_dim;
    UU_dims[2] = lat_dim;
    UU_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "UU", NC_DOUBLE, RANK_UU, UU_dims, &UU_id);
    check_err(stat,__LINE__,__FILE__);

    V_dims[0] = time_dim;
    V_dims[1] = lev_dim;
    V_dims[2] = lat_dim;
    V_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "V", NC_DOUBLE, RANK_V, V_dims, &V_id);
    check_err(stat,__LINE__,__FILE__);

    VD01_dims[0] = time_dim;
    VD01_dims[1] = lev_dim;
    VD01_dims[2] = lat_dim;
    VD01_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "VD01", NC_DOUBLE, RANK_VD01, VD01_dims, &VD01_id);
    check_err(stat,__LINE__,__FILE__);

    VFLX_dims[0] = time_dim;
    VFLX_dims[1] = ilev_dim;
    VFLX_dims[2] = lat_dim;
    VFLX_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "VFLX", NC_DOUBLE, RANK_VFLX, VFLX_dims, &VFLX_id);
    check_err(stat,__LINE__,__FILE__);

    VQ_dims[0] = time_dim;
    VQ_dims[1] = lev_dim;
    VQ_dims[2] = lat_dim;
    VQ_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "VQ", NC_DOUBLE, RANK_VQ, VQ_dims, &VQ_id);
    check_err(stat,__LINE__,__FILE__);

    VS_dims[0] = time_dim;
    VS_dims[1] = lev_dim;
    VS_dims[2] = lat_dim;
    VS_dims[3] = slon_dim;
    stat = nc_def_var(ncid, "VS", NC_DOUBLE, RANK_VS, VS_dims, &VS_id);
    check_err(stat,__LINE__,__FILE__);

    VT_dims[0] = time_dim;
    VT_dims[1] = lev_dim;
    VT_dims[2] = lat_dim;
    VT_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "VT", NC_DOUBLE, RANK_VT, VT_dims, &VT_id);
    check_err(stat,__LINE__,__FILE__);

    VU_dims[0] = time_dim;
    VU_dims[1] = lev_dim;
    VU_dims[2] = lat_dim;
    VU_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "VU", NC_DOUBLE, RANK_VU, VU_dims, &VU_id);
    check_err(stat,__LINE__,__FILE__);

    VV_dims[0] = time_dim;
    VV_dims[1] = lev_dim;
    VV_dims[2] = lat_dim;
    VV_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "VV", NC_DOUBLE, RANK_VV, VV_dims, &VV_id);
    check_err(stat,__LINE__,__FILE__);

    WGUSTD_dims[0] = time_dim;
    WGUSTD_dims[1] = lat_dim;
    WGUSTD_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "WGUSTD", NC_DOUBLE, RANK_WGUSTD, WGUSTD_dims, &WGUSTD_id);
    check_err(stat,__LINE__,__FILE__);

    WTKE_dims[0] = time_dim;
    WTKE_dims[1] = lev_dim;
    WTKE_dims[2] = lat_dim;
    WTKE_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "WTKE", NC_DOUBLE, RANK_WTKE, WTKE_dims, &WTKE_id);
    check_err(stat,__LINE__,__FILE__);

    XPH_LWC_dims[0] = time_dim;
    XPH_LWC_dims[1] = lev_dim;
    XPH_LWC_dims[2] = lat_dim;
    XPH_LWC_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "XPH_LWC", NC_DOUBLE, RANK_XPH_LWC, XPH_LWC_dims, &XPH_LWC_id);
    check_err(stat,__LINE__,__FILE__);

    Z3_dims[0] = time_dim;
    Z3_dims[1] = lev_dim;
    Z3_dims[2] = lat_dim;
    Z3_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "Z3", NC_DOUBLE, RANK_Z3, Z3_dims, &Z3_id);
    check_err(stat,__LINE__,__FILE__);

    airFV_dims[0] = time_dim;
    airFV_dims[1] = lat_dim;
    airFV_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "airFV", NC_DOUBLE, RANK_airFV, airFV_dims, &airFV_id);
    check_err(stat,__LINE__,__FILE__);

    bc_a1_dims[0] = time_dim;
    bc_a1_dims[1] = lev_dim;
    bc_a1_dims[2] = lat_dim;
    bc_a1_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "bc_a1", NC_DOUBLE, RANK_bc_a1, bc_a1_dims, &bc_a1_id);
    check_err(stat,__LINE__,__FILE__);

    bc_a1DDF_dims[0] = time_dim;
    bc_a1DDF_dims[1] = lat_dim;
    bc_a1DDF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "bc_a1DDF", NC_DOUBLE, RANK_bc_a1DDF, bc_a1DDF_dims, &bc_a1DDF_id);
    check_err(stat,__LINE__,__FILE__);

    bc_a1GVF_dims[0] = time_dim;
    bc_a1GVF_dims[1] = lat_dim;
    bc_a1GVF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "bc_a1GVF", NC_DOUBLE, RANK_bc_a1GVF, bc_a1GVF_dims, &bc_a1GVF_id);
    check_err(stat,__LINE__,__FILE__);

    bc_a1SFSBC_dims[0] = time_dim;
    bc_a1SFSBC_dims[1] = lat_dim;
    bc_a1SFSBC_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "bc_a1SFSBC", NC_DOUBLE, RANK_bc_a1SFSBC, bc_a1SFSBC_dims, &bc_a1SFSBC_id);
    check_err(stat,__LINE__,__FILE__);

    bc_a1SFSBS_dims[0] = time_dim;
    bc_a1SFSBS_dims[1] = lat_dim;
    bc_a1SFSBS_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "bc_a1SFSBS", NC_DOUBLE, RANK_bc_a1SFSBS, bc_a1SFSBS_dims, &bc_a1SFSBS_id);
    check_err(stat,__LINE__,__FILE__);

    bc_a1SFSIC_dims[0] = time_dim;
    bc_a1SFSIC_dims[1] = lat_dim;
    bc_a1SFSIC_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "bc_a1SFSIC", NC_DOUBLE, RANK_bc_a1SFSIC, bc_a1SFSIC_dims, &bc_a1SFSIC_id);
    check_err(stat,__LINE__,__FILE__);

    bc_a1SFSIS_dims[0] = time_dim;
    bc_a1SFSIS_dims[1] = lat_dim;
    bc_a1SFSIS_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "bc_a1SFSIS", NC_DOUBLE, RANK_bc_a1SFSIS, bc_a1SFSIS_dims, &bc_a1SFSIS_id);
    check_err(stat,__LINE__,__FILE__);

    bc_a1SFWET_dims[0] = time_dim;
    bc_a1SFWET_dims[1] = lat_dim;
    bc_a1SFWET_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "bc_a1SFWET", NC_DOUBLE, RANK_bc_a1SFWET, bc_a1SFWET_dims, &bc_a1SFWET_id);
    check_err(stat,__LINE__,__FILE__);

    bc_a1TBF_dims[0] = time_dim;
    bc_a1TBF_dims[1] = lat_dim;
    bc_a1TBF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "bc_a1TBF", NC_DOUBLE, RANK_bc_a1TBF, bc_a1TBF_dims, &bc_a1TBF_id);
    check_err(stat,__LINE__,__FILE__);

    bc_a1_CLXF_dims[0] = time_dim;
    bc_a1_CLXF_dims[1] = lat_dim;
    bc_a1_CLXF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "bc_a1_CLXF", NC_DOUBLE, RANK_bc_a1_CLXF, bc_a1_CLXF_dims, &bc_a1_CLXF_id);
    check_err(stat,__LINE__,__FILE__);

    bc_a1_XFRC_dims[0] = time_dim;
    bc_a1_XFRC_dims[1] = lev_dim;
    bc_a1_XFRC_dims[2] = lat_dim;
    bc_a1_XFRC_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "bc_a1_XFRC", NC_DOUBLE, RANK_bc_a1_XFRC, bc_a1_XFRC_dims, &bc_a1_XFRC_id);
    check_err(stat,__LINE__,__FILE__);

    bc_c1_dims[0] = time_dim;
    bc_c1_dims[1] = lev_dim;
    bc_c1_dims[2] = lat_dim;
    bc_c1_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "bc_c1", NC_DOUBLE, RANK_bc_c1, bc_c1_dims, &bc_c1_id);
    check_err(stat,__LINE__,__FILE__);

    bc_c1DDF_dims[0] = time_dim;
    bc_c1DDF_dims[1] = lat_dim;
    bc_c1DDF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "bc_c1DDF", NC_DOUBLE, RANK_bc_c1DDF, bc_c1DDF_dims, &bc_c1DDF_id);
    check_err(stat,__LINE__,__FILE__);

    bc_c1GVF_dims[0] = time_dim;
    bc_c1GVF_dims[1] = lat_dim;
    bc_c1GVF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "bc_c1GVF", NC_DOUBLE, RANK_bc_c1GVF, bc_c1GVF_dims, &bc_c1GVF_id);
    check_err(stat,__LINE__,__FILE__);

    bc_c1SFSBC_dims[0] = time_dim;
    bc_c1SFSBC_dims[1] = lat_dim;
    bc_c1SFSBC_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "bc_c1SFSBC", NC_DOUBLE, RANK_bc_c1SFSBC, bc_c1SFSBC_dims, &bc_c1SFSBC_id);
    check_err(stat,__LINE__,__FILE__);

    bc_c1SFSBS_dims[0] = time_dim;
    bc_c1SFSBS_dims[1] = lat_dim;
    bc_c1SFSBS_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "bc_c1SFSBS", NC_DOUBLE, RANK_bc_c1SFSBS, bc_c1SFSBS_dims, &bc_c1SFSBS_id);
    check_err(stat,__LINE__,__FILE__);

    bc_c1SFSIC_dims[0] = time_dim;
    bc_c1SFSIC_dims[1] = lat_dim;
    bc_c1SFSIC_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "bc_c1SFSIC", NC_DOUBLE, RANK_bc_c1SFSIC, bc_c1SFSIC_dims, &bc_c1SFSIC_id);
    check_err(stat,__LINE__,__FILE__);

    bc_c1SFSIS_dims[0] = time_dim;
    bc_c1SFSIS_dims[1] = lat_dim;
    bc_c1SFSIS_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "bc_c1SFSIS", NC_DOUBLE, RANK_bc_c1SFSIS, bc_c1SFSIS_dims, &bc_c1SFSIS_id);
    check_err(stat,__LINE__,__FILE__);

    bc_c1SFWET_dims[0] = time_dim;
    bc_c1SFWET_dims[1] = lat_dim;
    bc_c1SFWET_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "bc_c1SFWET", NC_DOUBLE, RANK_bc_c1SFWET, bc_c1SFWET_dims, &bc_c1SFWET_id);
    check_err(stat,__LINE__,__FILE__);

    bc_c1TBF_dims[0] = time_dim;
    bc_c1TBF_dims[1] = lat_dim;
    bc_c1TBF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "bc_c1TBF", NC_DOUBLE, RANK_bc_c1TBF, bc_c1TBF_dims, &bc_c1TBF_id);
    check_err(stat,__LINE__,__FILE__);

    chem_trop_dims[0] = time_dim;
    chem_trop_dims[1] = lev_dim;
    chem_trop_dims[2] = lat_dim;
    chem_trop_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "chem_trop", NC_DOUBLE, RANK_chem_trop, chem_trop_dims, &chem_trop_id);
    check_err(stat,__LINE__,__FILE__);

    chem_trop_tropop_dims[0] = time_dim;
    chem_trop_tropop_dims[1] = lev_dim;
    chem_trop_tropop_dims[2] = lat_dim;
    chem_trop_tropop_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "chem_trop_tropop", NC_DOUBLE, RANK_chem_trop_tropop, chem_trop_tropop_dims, &chem_trop_tropop_id);
    check_err(stat,__LINE__,__FILE__);

    dgnd_a01_dims[0] = time_dim;
    dgnd_a01_dims[1] = lev_dim;
    dgnd_a01_dims[2] = lat_dim;
    dgnd_a01_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "dgnd_a01", NC_DOUBLE, RANK_dgnd_a01, dgnd_a01_dims, &dgnd_a01_id);
    check_err(stat,__LINE__,__FILE__);

    dgnd_a02_dims[0] = time_dim;
    dgnd_a02_dims[1] = lev_dim;
    dgnd_a02_dims[2] = lat_dim;
    dgnd_a02_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "dgnd_a02", NC_DOUBLE, RANK_dgnd_a02, dgnd_a02_dims, &dgnd_a02_id);
    check_err(stat,__LINE__,__FILE__);

    dgnd_a03_dims[0] = time_dim;
    dgnd_a03_dims[1] = lev_dim;
    dgnd_a03_dims[2] = lat_dim;
    dgnd_a03_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "dgnd_a03", NC_DOUBLE, RANK_dgnd_a03, dgnd_a03_dims, &dgnd_a03_id);
    check_err(stat,__LINE__,__FILE__);

    dgnw_a01_dims[0] = time_dim;
    dgnw_a01_dims[1] = lev_dim;
    dgnw_a01_dims[2] = lat_dim;
    dgnw_a01_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "dgnw_a01", NC_DOUBLE, RANK_dgnw_a01, dgnw_a01_dims, &dgnw_a01_id);
    check_err(stat,__LINE__,__FILE__);

    dgnw_a02_dims[0] = time_dim;
    dgnw_a02_dims[1] = lev_dim;
    dgnw_a02_dims[2] = lat_dim;
    dgnw_a02_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "dgnw_a02", NC_DOUBLE, RANK_dgnw_a02, dgnw_a02_dims, &dgnw_a02_id);
    check_err(stat,__LINE__,__FILE__);

    dgnw_a03_dims[0] = time_dim;
    dgnw_a03_dims[1] = lev_dim;
    dgnw_a03_dims[2] = lat_dim;
    dgnw_a03_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "dgnw_a03", NC_DOUBLE, RANK_dgnw_a03, dgnw_a03_dims, &dgnw_a03_id);
    check_err(stat,__LINE__,__FILE__);

    dst_a1_dims[0] = time_dim;
    dst_a1_dims[1] = lev_dim;
    dst_a1_dims[2] = lat_dim;
    dst_a1_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "dst_a1", NC_DOUBLE, RANK_dst_a1, dst_a1_dims, &dst_a1_id);
    check_err(stat,__LINE__,__FILE__);

    dst_a1DDF_dims[0] = time_dim;
    dst_a1DDF_dims[1] = lat_dim;
    dst_a1DDF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "dst_a1DDF", NC_DOUBLE, RANK_dst_a1DDF, dst_a1DDF_dims, &dst_a1DDF_id);
    check_err(stat,__LINE__,__FILE__);

    dst_a1GVF_dims[0] = time_dim;
    dst_a1GVF_dims[1] = lat_dim;
    dst_a1GVF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "dst_a1GVF", NC_DOUBLE, RANK_dst_a1GVF, dst_a1GVF_dims, &dst_a1GVF_id);
    check_err(stat,__LINE__,__FILE__);

    dst_a1SF_dims[0] = time_dim;
    dst_a1SF_dims[1] = lat_dim;
    dst_a1SF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "dst_a1SF", NC_DOUBLE, RANK_dst_a1SF, dst_a1SF_dims, &dst_a1SF_id);
    check_err(stat,__LINE__,__FILE__);

    dst_a1SFSBC_dims[0] = time_dim;
    dst_a1SFSBC_dims[1] = lat_dim;
    dst_a1SFSBC_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "dst_a1SFSBC", NC_DOUBLE, RANK_dst_a1SFSBC, dst_a1SFSBC_dims, &dst_a1SFSBC_id);
    check_err(stat,__LINE__,__FILE__);

    dst_a1SFSBS_dims[0] = time_dim;
    dst_a1SFSBS_dims[1] = lat_dim;
    dst_a1SFSBS_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "dst_a1SFSBS", NC_DOUBLE, RANK_dst_a1SFSBS, dst_a1SFSBS_dims, &dst_a1SFSBS_id);
    check_err(stat,__LINE__,__FILE__);

    dst_a1SFSIC_dims[0] = time_dim;
    dst_a1SFSIC_dims[1] = lat_dim;
    dst_a1SFSIC_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "dst_a1SFSIC", NC_DOUBLE, RANK_dst_a1SFSIC, dst_a1SFSIC_dims, &dst_a1SFSIC_id);
    check_err(stat,__LINE__,__FILE__);

    dst_a1SFSIS_dims[0] = time_dim;
    dst_a1SFSIS_dims[1] = lat_dim;
    dst_a1SFSIS_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "dst_a1SFSIS", NC_DOUBLE, RANK_dst_a1SFSIS, dst_a1SFSIS_dims, &dst_a1SFSIS_id);
    check_err(stat,__LINE__,__FILE__);

    dst_a1SFWET_dims[0] = time_dim;
    dst_a1SFWET_dims[1] = lat_dim;
    dst_a1SFWET_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "dst_a1SFWET", NC_DOUBLE, RANK_dst_a1SFWET, dst_a1SFWET_dims, &dst_a1SFWET_id);
    check_err(stat,__LINE__,__FILE__);

    dst_a1TBF_dims[0] = time_dim;
    dst_a1TBF_dims[1] = lat_dim;
    dst_a1TBF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "dst_a1TBF", NC_DOUBLE, RANK_dst_a1TBF, dst_a1TBF_dims, &dst_a1TBF_id);
    check_err(stat,__LINE__,__FILE__);

    dst_a3_dims[0] = time_dim;
    dst_a3_dims[1] = lev_dim;
    dst_a3_dims[2] = lat_dim;
    dst_a3_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "dst_a3", NC_DOUBLE, RANK_dst_a3, dst_a3_dims, &dst_a3_id);
    check_err(stat,__LINE__,__FILE__);

    dst_a3DDF_dims[0] = time_dim;
    dst_a3DDF_dims[1] = lat_dim;
    dst_a3DDF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "dst_a3DDF", NC_DOUBLE, RANK_dst_a3DDF, dst_a3DDF_dims, &dst_a3DDF_id);
    check_err(stat,__LINE__,__FILE__);

    dst_a3GVF_dims[0] = time_dim;
    dst_a3GVF_dims[1] = lat_dim;
    dst_a3GVF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "dst_a3GVF", NC_DOUBLE, RANK_dst_a3GVF, dst_a3GVF_dims, &dst_a3GVF_id);
    check_err(stat,__LINE__,__FILE__);

    dst_a3SF_dims[0] = time_dim;
    dst_a3SF_dims[1] = lat_dim;
    dst_a3SF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "dst_a3SF", NC_DOUBLE, RANK_dst_a3SF, dst_a3SF_dims, &dst_a3SF_id);
    check_err(stat,__LINE__,__FILE__);

    dst_a3SFSBC_dims[0] = time_dim;
    dst_a3SFSBC_dims[1] = lat_dim;
    dst_a3SFSBC_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "dst_a3SFSBC", NC_DOUBLE, RANK_dst_a3SFSBC, dst_a3SFSBC_dims, &dst_a3SFSBC_id);
    check_err(stat,__LINE__,__FILE__);

    dst_a3SFSBS_dims[0] = time_dim;
    dst_a3SFSBS_dims[1] = lat_dim;
    dst_a3SFSBS_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "dst_a3SFSBS", NC_DOUBLE, RANK_dst_a3SFSBS, dst_a3SFSBS_dims, &dst_a3SFSBS_id);
    check_err(stat,__LINE__,__FILE__);

    dst_a3SFSIC_dims[0] = time_dim;
    dst_a3SFSIC_dims[1] = lat_dim;
    dst_a3SFSIC_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "dst_a3SFSIC", NC_DOUBLE, RANK_dst_a3SFSIC, dst_a3SFSIC_dims, &dst_a3SFSIC_id);
    check_err(stat,__LINE__,__FILE__);

    dst_a3SFSIS_dims[0] = time_dim;
    dst_a3SFSIS_dims[1] = lat_dim;
    dst_a3SFSIS_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "dst_a3SFSIS", NC_DOUBLE, RANK_dst_a3SFSIS, dst_a3SFSIS_dims, &dst_a3SFSIS_id);
    check_err(stat,__LINE__,__FILE__);

    dst_a3SFWET_dims[0] = time_dim;
    dst_a3SFWET_dims[1] = lat_dim;
    dst_a3SFWET_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "dst_a3SFWET", NC_DOUBLE, RANK_dst_a3SFWET, dst_a3SFWET_dims, &dst_a3SFWET_id);
    check_err(stat,__LINE__,__FILE__);

    dst_a3TBF_dims[0] = time_dim;
    dst_a3TBF_dims[1] = lat_dim;
    dst_a3TBF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "dst_a3TBF", NC_DOUBLE, RANK_dst_a3TBF, dst_a3TBF_dims, &dst_a3TBF_id);
    check_err(stat,__LINE__,__FILE__);

    dst_c1_dims[0] = time_dim;
    dst_c1_dims[1] = lev_dim;
    dst_c1_dims[2] = lat_dim;
    dst_c1_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "dst_c1", NC_DOUBLE, RANK_dst_c1, dst_c1_dims, &dst_c1_id);
    check_err(stat,__LINE__,__FILE__);

    dst_c1DDF_dims[0] = time_dim;
    dst_c1DDF_dims[1] = lat_dim;
    dst_c1DDF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "dst_c1DDF", NC_DOUBLE, RANK_dst_c1DDF, dst_c1DDF_dims, &dst_c1DDF_id);
    check_err(stat,__LINE__,__FILE__);

    dst_c1GVF_dims[0] = time_dim;
    dst_c1GVF_dims[1] = lat_dim;
    dst_c1GVF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "dst_c1GVF", NC_DOUBLE, RANK_dst_c1GVF, dst_c1GVF_dims, &dst_c1GVF_id);
    check_err(stat,__LINE__,__FILE__);

    dst_c1SFSBC_dims[0] = time_dim;
    dst_c1SFSBC_dims[1] = lat_dim;
    dst_c1SFSBC_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "dst_c1SFSBC", NC_DOUBLE, RANK_dst_c1SFSBC, dst_c1SFSBC_dims, &dst_c1SFSBC_id);
    check_err(stat,__LINE__,__FILE__);

    dst_c1SFSBS_dims[0] = time_dim;
    dst_c1SFSBS_dims[1] = lat_dim;
    dst_c1SFSBS_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "dst_c1SFSBS", NC_DOUBLE, RANK_dst_c1SFSBS, dst_c1SFSBS_dims, &dst_c1SFSBS_id);
    check_err(stat,__LINE__,__FILE__);

    dst_c1SFSIC_dims[0] = time_dim;
    dst_c1SFSIC_dims[1] = lat_dim;
    dst_c1SFSIC_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "dst_c1SFSIC", NC_DOUBLE, RANK_dst_c1SFSIC, dst_c1SFSIC_dims, &dst_c1SFSIC_id);
    check_err(stat,__LINE__,__FILE__);

    dst_c1SFSIS_dims[0] = time_dim;
    dst_c1SFSIS_dims[1] = lat_dim;
    dst_c1SFSIS_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "dst_c1SFSIS", NC_DOUBLE, RANK_dst_c1SFSIS, dst_c1SFSIS_dims, &dst_c1SFSIS_id);
    check_err(stat,__LINE__,__FILE__);

    dst_c1SFWET_dims[0] = time_dim;
    dst_c1SFWET_dims[1] = lat_dim;
    dst_c1SFWET_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "dst_c1SFWET", NC_DOUBLE, RANK_dst_c1SFWET, dst_c1SFWET_dims, &dst_c1SFWET_id);
    check_err(stat,__LINE__,__FILE__);

    dst_c1TBF_dims[0] = time_dim;
    dst_c1TBF_dims[1] = lat_dim;
    dst_c1TBF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "dst_c1TBF", NC_DOUBLE, RANK_dst_c1TBF, dst_c1TBF_dims, &dst_c1TBF_id);
    check_err(stat,__LINE__,__FILE__);

    dst_c3_dims[0] = time_dim;
    dst_c3_dims[1] = lev_dim;
    dst_c3_dims[2] = lat_dim;
    dst_c3_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "dst_c3", NC_DOUBLE, RANK_dst_c3, dst_c3_dims, &dst_c3_id);
    check_err(stat,__LINE__,__FILE__);

    dst_c3DDF_dims[0] = time_dim;
    dst_c3DDF_dims[1] = lat_dim;
    dst_c3DDF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "dst_c3DDF", NC_DOUBLE, RANK_dst_c3DDF, dst_c3DDF_dims, &dst_c3DDF_id);
    check_err(stat,__LINE__,__FILE__);

    dst_c3GVF_dims[0] = time_dim;
    dst_c3GVF_dims[1] = lat_dim;
    dst_c3GVF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "dst_c3GVF", NC_DOUBLE, RANK_dst_c3GVF, dst_c3GVF_dims, &dst_c3GVF_id);
    check_err(stat,__LINE__,__FILE__);

    dst_c3SFSBC_dims[0] = time_dim;
    dst_c3SFSBC_dims[1] = lat_dim;
    dst_c3SFSBC_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "dst_c3SFSBC", NC_DOUBLE, RANK_dst_c3SFSBC, dst_c3SFSBC_dims, &dst_c3SFSBC_id);
    check_err(stat,__LINE__,__FILE__);

    dst_c3SFSBS_dims[0] = time_dim;
    dst_c3SFSBS_dims[1] = lat_dim;
    dst_c3SFSBS_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "dst_c3SFSBS", NC_DOUBLE, RANK_dst_c3SFSBS, dst_c3SFSBS_dims, &dst_c3SFSBS_id);
    check_err(stat,__LINE__,__FILE__);

    dst_c3SFSIC_dims[0] = time_dim;
    dst_c3SFSIC_dims[1] = lat_dim;
    dst_c3SFSIC_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "dst_c3SFSIC", NC_DOUBLE, RANK_dst_c3SFSIC, dst_c3SFSIC_dims, &dst_c3SFSIC_id);
    check_err(stat,__LINE__,__FILE__);

    dst_c3SFSIS_dims[0] = time_dim;
    dst_c3SFSIS_dims[1] = lat_dim;
    dst_c3SFSIS_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "dst_c3SFSIS", NC_DOUBLE, RANK_dst_c3SFSIS, dst_c3SFSIS_dims, &dst_c3SFSIS_id);
    check_err(stat,__LINE__,__FILE__);

    dst_c3SFWET_dims[0] = time_dim;
    dst_c3SFWET_dims[1] = lat_dim;
    dst_c3SFWET_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "dst_c3SFWET", NC_DOUBLE, RANK_dst_c3SFWET, dst_c3SFWET_dims, &dst_c3SFWET_id);
    check_err(stat,__LINE__,__FILE__);

    dst_c3TBF_dims[0] = time_dim;
    dst_c3TBF_dims[1] = lat_dim;
    dst_c3TBF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "dst_c3TBF", NC_DOUBLE, RANK_dst_c3TBF, dst_c3TBF_dims, &dst_c3TBF_id);
    check_err(stat,__LINE__,__FILE__);

    ncl_a1_dims[0] = time_dim;
    ncl_a1_dims[1] = lev_dim;
    ncl_a1_dims[2] = lat_dim;
    ncl_a1_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "ncl_a1", NC_DOUBLE, RANK_ncl_a1, ncl_a1_dims, &ncl_a1_id);
    check_err(stat,__LINE__,__FILE__);

    ncl_a1DDF_dims[0] = time_dim;
    ncl_a1DDF_dims[1] = lat_dim;
    ncl_a1DDF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "ncl_a1DDF", NC_DOUBLE, RANK_ncl_a1DDF, ncl_a1DDF_dims, &ncl_a1DDF_id);
    check_err(stat,__LINE__,__FILE__);

    ncl_a1GVF_dims[0] = time_dim;
    ncl_a1GVF_dims[1] = lat_dim;
    ncl_a1GVF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "ncl_a1GVF", NC_DOUBLE, RANK_ncl_a1GVF, ncl_a1GVF_dims, &ncl_a1GVF_id);
    check_err(stat,__LINE__,__FILE__);

    ncl_a1SF_dims[0] = time_dim;
    ncl_a1SF_dims[1] = lat_dim;
    ncl_a1SF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "ncl_a1SF", NC_DOUBLE, RANK_ncl_a1SF, ncl_a1SF_dims, &ncl_a1SF_id);
    check_err(stat,__LINE__,__FILE__);

    ncl_a1SFSBC_dims[0] = time_dim;
    ncl_a1SFSBC_dims[1] = lat_dim;
    ncl_a1SFSBC_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "ncl_a1SFSBC", NC_DOUBLE, RANK_ncl_a1SFSBC, ncl_a1SFSBC_dims, &ncl_a1SFSBC_id);
    check_err(stat,__LINE__,__FILE__);

    ncl_a1SFSBS_dims[0] = time_dim;
    ncl_a1SFSBS_dims[1] = lat_dim;
    ncl_a1SFSBS_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "ncl_a1SFSBS", NC_DOUBLE, RANK_ncl_a1SFSBS, ncl_a1SFSBS_dims, &ncl_a1SFSBS_id);
    check_err(stat,__LINE__,__FILE__);

    ncl_a1SFSIC_dims[0] = time_dim;
    ncl_a1SFSIC_dims[1] = lat_dim;
    ncl_a1SFSIC_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "ncl_a1SFSIC", NC_DOUBLE, RANK_ncl_a1SFSIC, ncl_a1SFSIC_dims, &ncl_a1SFSIC_id);
    check_err(stat,__LINE__,__FILE__);

    ncl_a1SFSIS_dims[0] = time_dim;
    ncl_a1SFSIS_dims[1] = lat_dim;
    ncl_a1SFSIS_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "ncl_a1SFSIS", NC_DOUBLE, RANK_ncl_a1SFSIS, ncl_a1SFSIS_dims, &ncl_a1SFSIS_id);
    check_err(stat,__LINE__,__FILE__);

    ncl_a1SFWET_dims[0] = time_dim;
    ncl_a1SFWET_dims[1] = lat_dim;
    ncl_a1SFWET_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "ncl_a1SFWET", NC_DOUBLE, RANK_ncl_a1SFWET, ncl_a1SFWET_dims, &ncl_a1SFWET_id);
    check_err(stat,__LINE__,__FILE__);

    ncl_a1TBF_dims[0] = time_dim;
    ncl_a1TBF_dims[1] = lat_dim;
    ncl_a1TBF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "ncl_a1TBF", NC_DOUBLE, RANK_ncl_a1TBF, ncl_a1TBF_dims, &ncl_a1TBF_id);
    check_err(stat,__LINE__,__FILE__);

    ncl_a1_sfcoag1_dims[0] = time_dim;
    ncl_a1_sfcoag1_dims[1] = lat_dim;
    ncl_a1_sfcoag1_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "ncl_a1_sfcoag1", NC_DOUBLE, RANK_ncl_a1_sfcoag1, ncl_a1_sfcoag1_dims, &ncl_a1_sfcoag1_id);
    check_err(stat,__LINE__,__FILE__);

    ncl_a1_sfcsiz3_dims[0] = time_dim;
    ncl_a1_sfcsiz3_dims[1] = lat_dim;
    ncl_a1_sfcsiz3_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "ncl_a1_sfcsiz3", NC_DOUBLE, RANK_ncl_a1_sfcsiz3, ncl_a1_sfcsiz3_dims, &ncl_a1_sfcsiz3_id);
    check_err(stat,__LINE__,__FILE__);

    ncl_a1_sfcsiz4_dims[0] = time_dim;
    ncl_a1_sfcsiz4_dims[1] = lat_dim;
    ncl_a1_sfcsiz4_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "ncl_a1_sfcsiz4", NC_DOUBLE, RANK_ncl_a1_sfcsiz4, ncl_a1_sfcsiz4_dims, &ncl_a1_sfcsiz4_id);
    check_err(stat,__LINE__,__FILE__);

    ncl_a1_sfgaex2_dims[0] = time_dim;
    ncl_a1_sfgaex2_dims[1] = lat_dim;
    ncl_a1_sfgaex2_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "ncl_a1_sfgaex2", NC_DOUBLE, RANK_ncl_a1_sfgaex2, ncl_a1_sfgaex2_dims, &ncl_a1_sfgaex2_id);
    check_err(stat,__LINE__,__FILE__);

    ncl_a2_dims[0] = time_dim;
    ncl_a2_dims[1] = lev_dim;
    ncl_a2_dims[2] = lat_dim;
    ncl_a2_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "ncl_a2", NC_DOUBLE, RANK_ncl_a2, ncl_a2_dims, &ncl_a2_id);
    check_err(stat,__LINE__,__FILE__);

    ncl_a2DDF_dims[0] = time_dim;
    ncl_a2DDF_dims[1] = lat_dim;
    ncl_a2DDF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "ncl_a2DDF", NC_DOUBLE, RANK_ncl_a2DDF, ncl_a2DDF_dims, &ncl_a2DDF_id);
    check_err(stat,__LINE__,__FILE__);

    ncl_a2GVF_dims[0] = time_dim;
    ncl_a2GVF_dims[1] = lat_dim;
    ncl_a2GVF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "ncl_a2GVF", NC_DOUBLE, RANK_ncl_a2GVF, ncl_a2GVF_dims, &ncl_a2GVF_id);
    check_err(stat,__LINE__,__FILE__);

    ncl_a2SF_dims[0] = time_dim;
    ncl_a2SF_dims[1] = lat_dim;
    ncl_a2SF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "ncl_a2SF", NC_DOUBLE, RANK_ncl_a2SF, ncl_a2SF_dims, &ncl_a2SF_id);
    check_err(stat,__LINE__,__FILE__);

    ncl_a2SFSBC_dims[0] = time_dim;
    ncl_a2SFSBC_dims[1] = lat_dim;
    ncl_a2SFSBC_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "ncl_a2SFSBC", NC_DOUBLE, RANK_ncl_a2SFSBC, ncl_a2SFSBC_dims, &ncl_a2SFSBC_id);
    check_err(stat,__LINE__,__FILE__);

    ncl_a2SFSBS_dims[0] = time_dim;
    ncl_a2SFSBS_dims[1] = lat_dim;
    ncl_a2SFSBS_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "ncl_a2SFSBS", NC_DOUBLE, RANK_ncl_a2SFSBS, ncl_a2SFSBS_dims, &ncl_a2SFSBS_id);
    check_err(stat,__LINE__,__FILE__);

    ncl_a2SFSIC_dims[0] = time_dim;
    ncl_a2SFSIC_dims[1] = lat_dim;
    ncl_a2SFSIC_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "ncl_a2SFSIC", NC_DOUBLE, RANK_ncl_a2SFSIC, ncl_a2SFSIC_dims, &ncl_a2SFSIC_id);
    check_err(stat,__LINE__,__FILE__);

    ncl_a2SFSIS_dims[0] = time_dim;
    ncl_a2SFSIS_dims[1] = lat_dim;
    ncl_a2SFSIS_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "ncl_a2SFSIS", NC_DOUBLE, RANK_ncl_a2SFSIS, ncl_a2SFSIS_dims, &ncl_a2SFSIS_id);
    check_err(stat,__LINE__,__FILE__);

    ncl_a2SFWET_dims[0] = time_dim;
    ncl_a2SFWET_dims[1] = lat_dim;
    ncl_a2SFWET_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "ncl_a2SFWET", NC_DOUBLE, RANK_ncl_a2SFWET, ncl_a2SFWET_dims, &ncl_a2SFWET_id);
    check_err(stat,__LINE__,__FILE__);

    ncl_a2TBF_dims[0] = time_dim;
    ncl_a2TBF_dims[1] = lat_dim;
    ncl_a2TBF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "ncl_a2TBF", NC_DOUBLE, RANK_ncl_a2TBF, ncl_a2TBF_dims, &ncl_a2TBF_id);
    check_err(stat,__LINE__,__FILE__);

    ncl_a2_sfcoag1_dims[0] = time_dim;
    ncl_a2_sfcoag1_dims[1] = lat_dim;
    ncl_a2_sfcoag1_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "ncl_a2_sfcoag1", NC_DOUBLE, RANK_ncl_a2_sfcoag1, ncl_a2_sfcoag1_dims, &ncl_a2_sfcoag1_id);
    check_err(stat,__LINE__,__FILE__);

    ncl_a2_sfcsiz3_dims[0] = time_dim;
    ncl_a2_sfcsiz3_dims[1] = lat_dim;
    ncl_a2_sfcsiz3_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "ncl_a2_sfcsiz3", NC_DOUBLE, RANK_ncl_a2_sfcsiz3, ncl_a2_sfcsiz3_dims, &ncl_a2_sfcsiz3_id);
    check_err(stat,__LINE__,__FILE__);

    ncl_a2_sfcsiz4_dims[0] = time_dim;
    ncl_a2_sfcsiz4_dims[1] = lat_dim;
    ncl_a2_sfcsiz4_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "ncl_a2_sfcsiz4", NC_DOUBLE, RANK_ncl_a2_sfcsiz4, ncl_a2_sfcsiz4_dims, &ncl_a2_sfcsiz4_id);
    check_err(stat,__LINE__,__FILE__);

    ncl_a2_sfgaex2_dims[0] = time_dim;
    ncl_a2_sfgaex2_dims[1] = lat_dim;
    ncl_a2_sfgaex2_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "ncl_a2_sfgaex2", NC_DOUBLE, RANK_ncl_a2_sfgaex2, ncl_a2_sfgaex2_dims, &ncl_a2_sfgaex2_id);
    check_err(stat,__LINE__,__FILE__);

    ncl_a3_dims[0] = time_dim;
    ncl_a3_dims[1] = lev_dim;
    ncl_a3_dims[2] = lat_dim;
    ncl_a3_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "ncl_a3", NC_DOUBLE, RANK_ncl_a3, ncl_a3_dims, &ncl_a3_id);
    check_err(stat,__LINE__,__FILE__);

    ncl_a3DDF_dims[0] = time_dim;
    ncl_a3DDF_dims[1] = lat_dim;
    ncl_a3DDF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "ncl_a3DDF", NC_DOUBLE, RANK_ncl_a3DDF, ncl_a3DDF_dims, &ncl_a3DDF_id);
    check_err(stat,__LINE__,__FILE__);

    ncl_a3GVF_dims[0] = time_dim;
    ncl_a3GVF_dims[1] = lat_dim;
    ncl_a3GVF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "ncl_a3GVF", NC_DOUBLE, RANK_ncl_a3GVF, ncl_a3GVF_dims, &ncl_a3GVF_id);
    check_err(stat,__LINE__,__FILE__);

    ncl_a3SF_dims[0] = time_dim;
    ncl_a3SF_dims[1] = lat_dim;
    ncl_a3SF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "ncl_a3SF", NC_DOUBLE, RANK_ncl_a3SF, ncl_a3SF_dims, &ncl_a3SF_id);
    check_err(stat,__LINE__,__FILE__);

    ncl_a3SFSBC_dims[0] = time_dim;
    ncl_a3SFSBC_dims[1] = lat_dim;
    ncl_a3SFSBC_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "ncl_a3SFSBC", NC_DOUBLE, RANK_ncl_a3SFSBC, ncl_a3SFSBC_dims, &ncl_a3SFSBC_id);
    check_err(stat,__LINE__,__FILE__);

    ncl_a3SFSBS_dims[0] = time_dim;
    ncl_a3SFSBS_dims[1] = lat_dim;
    ncl_a3SFSBS_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "ncl_a3SFSBS", NC_DOUBLE, RANK_ncl_a3SFSBS, ncl_a3SFSBS_dims, &ncl_a3SFSBS_id);
    check_err(stat,__LINE__,__FILE__);

    ncl_a3SFSIC_dims[0] = time_dim;
    ncl_a3SFSIC_dims[1] = lat_dim;
    ncl_a3SFSIC_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "ncl_a3SFSIC", NC_DOUBLE, RANK_ncl_a3SFSIC, ncl_a3SFSIC_dims, &ncl_a3SFSIC_id);
    check_err(stat,__LINE__,__FILE__);

    ncl_a3SFSIS_dims[0] = time_dim;
    ncl_a3SFSIS_dims[1] = lat_dim;
    ncl_a3SFSIS_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "ncl_a3SFSIS", NC_DOUBLE, RANK_ncl_a3SFSIS, ncl_a3SFSIS_dims, &ncl_a3SFSIS_id);
    check_err(stat,__LINE__,__FILE__);

    ncl_a3SFWET_dims[0] = time_dim;
    ncl_a3SFWET_dims[1] = lat_dim;
    ncl_a3SFWET_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "ncl_a3SFWET", NC_DOUBLE, RANK_ncl_a3SFWET, ncl_a3SFWET_dims, &ncl_a3SFWET_id);
    check_err(stat,__LINE__,__FILE__);

    ncl_a3TBF_dims[0] = time_dim;
    ncl_a3TBF_dims[1] = lat_dim;
    ncl_a3TBF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "ncl_a3TBF", NC_DOUBLE, RANK_ncl_a3TBF, ncl_a3TBF_dims, &ncl_a3TBF_id);
    check_err(stat,__LINE__,__FILE__);

    ncl_c1_dims[0] = time_dim;
    ncl_c1_dims[1] = lev_dim;
    ncl_c1_dims[2] = lat_dim;
    ncl_c1_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "ncl_c1", NC_DOUBLE, RANK_ncl_c1, ncl_c1_dims, &ncl_c1_id);
    check_err(stat,__LINE__,__FILE__);

    ncl_c1DDF_dims[0] = time_dim;
    ncl_c1DDF_dims[1] = lat_dim;
    ncl_c1DDF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "ncl_c1DDF", NC_DOUBLE, RANK_ncl_c1DDF, ncl_c1DDF_dims, &ncl_c1DDF_id);
    check_err(stat,__LINE__,__FILE__);

    ncl_c1GVF_dims[0] = time_dim;
    ncl_c1GVF_dims[1] = lat_dim;
    ncl_c1GVF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "ncl_c1GVF", NC_DOUBLE, RANK_ncl_c1GVF, ncl_c1GVF_dims, &ncl_c1GVF_id);
    check_err(stat,__LINE__,__FILE__);

    ncl_c1SFSBC_dims[0] = time_dim;
    ncl_c1SFSBC_dims[1] = lat_dim;
    ncl_c1SFSBC_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "ncl_c1SFSBC", NC_DOUBLE, RANK_ncl_c1SFSBC, ncl_c1SFSBC_dims, &ncl_c1SFSBC_id);
    check_err(stat,__LINE__,__FILE__);

    ncl_c1SFSBS_dims[0] = time_dim;
    ncl_c1SFSBS_dims[1] = lat_dim;
    ncl_c1SFSBS_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "ncl_c1SFSBS", NC_DOUBLE, RANK_ncl_c1SFSBS, ncl_c1SFSBS_dims, &ncl_c1SFSBS_id);
    check_err(stat,__LINE__,__FILE__);

    ncl_c1SFSIC_dims[0] = time_dim;
    ncl_c1SFSIC_dims[1] = lat_dim;
    ncl_c1SFSIC_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "ncl_c1SFSIC", NC_DOUBLE, RANK_ncl_c1SFSIC, ncl_c1SFSIC_dims, &ncl_c1SFSIC_id);
    check_err(stat,__LINE__,__FILE__);

    ncl_c1SFSIS_dims[0] = time_dim;
    ncl_c1SFSIS_dims[1] = lat_dim;
    ncl_c1SFSIS_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "ncl_c1SFSIS", NC_DOUBLE, RANK_ncl_c1SFSIS, ncl_c1SFSIS_dims, &ncl_c1SFSIS_id);
    check_err(stat,__LINE__,__FILE__);

    ncl_c1SFWET_dims[0] = time_dim;
    ncl_c1SFWET_dims[1] = lat_dim;
    ncl_c1SFWET_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "ncl_c1SFWET", NC_DOUBLE, RANK_ncl_c1SFWET, ncl_c1SFWET_dims, &ncl_c1SFWET_id);
    check_err(stat,__LINE__,__FILE__);

    ncl_c1TBF_dims[0] = time_dim;
    ncl_c1TBF_dims[1] = lat_dim;
    ncl_c1TBF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "ncl_c1TBF", NC_DOUBLE, RANK_ncl_c1TBF, ncl_c1TBF_dims, &ncl_c1TBF_id);
    check_err(stat,__LINE__,__FILE__);

    ncl_c1_sfcsiz3_dims[0] = time_dim;
    ncl_c1_sfcsiz3_dims[1] = lat_dim;
    ncl_c1_sfcsiz3_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "ncl_c1_sfcsiz3", NC_DOUBLE, RANK_ncl_c1_sfcsiz3, ncl_c1_sfcsiz3_dims, &ncl_c1_sfcsiz3_id);
    check_err(stat,__LINE__,__FILE__);

    ncl_c1_sfcsiz4_dims[0] = time_dim;
    ncl_c1_sfcsiz4_dims[1] = lat_dim;
    ncl_c1_sfcsiz4_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "ncl_c1_sfcsiz4", NC_DOUBLE, RANK_ncl_c1_sfcsiz4, ncl_c1_sfcsiz4_dims, &ncl_c1_sfcsiz4_id);
    check_err(stat,__LINE__,__FILE__);

    ncl_c1_sfgaex2_dims[0] = time_dim;
    ncl_c1_sfgaex2_dims[1] = lat_dim;
    ncl_c1_sfgaex2_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "ncl_c1_sfgaex2", NC_DOUBLE, RANK_ncl_c1_sfgaex2, ncl_c1_sfgaex2_dims, &ncl_c1_sfgaex2_id);
    check_err(stat,__LINE__,__FILE__);

    ncl_c2_dims[0] = time_dim;
    ncl_c2_dims[1] = lev_dim;
    ncl_c2_dims[2] = lat_dim;
    ncl_c2_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "ncl_c2", NC_DOUBLE, RANK_ncl_c2, ncl_c2_dims, &ncl_c2_id);
    check_err(stat,__LINE__,__FILE__);

    ncl_c2DDF_dims[0] = time_dim;
    ncl_c2DDF_dims[1] = lat_dim;
    ncl_c2DDF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "ncl_c2DDF", NC_DOUBLE, RANK_ncl_c2DDF, ncl_c2DDF_dims, &ncl_c2DDF_id);
    check_err(stat,__LINE__,__FILE__);

    ncl_c2GVF_dims[0] = time_dim;
    ncl_c2GVF_dims[1] = lat_dim;
    ncl_c2GVF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "ncl_c2GVF", NC_DOUBLE, RANK_ncl_c2GVF, ncl_c2GVF_dims, &ncl_c2GVF_id);
    check_err(stat,__LINE__,__FILE__);

    ncl_c2SFSBC_dims[0] = time_dim;
    ncl_c2SFSBC_dims[1] = lat_dim;
    ncl_c2SFSBC_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "ncl_c2SFSBC", NC_DOUBLE, RANK_ncl_c2SFSBC, ncl_c2SFSBC_dims, &ncl_c2SFSBC_id);
    check_err(stat,__LINE__,__FILE__);

    ncl_c2SFSBS_dims[0] = time_dim;
    ncl_c2SFSBS_dims[1] = lat_dim;
    ncl_c2SFSBS_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "ncl_c2SFSBS", NC_DOUBLE, RANK_ncl_c2SFSBS, ncl_c2SFSBS_dims, &ncl_c2SFSBS_id);
    check_err(stat,__LINE__,__FILE__);

    ncl_c2SFSIC_dims[0] = time_dim;
    ncl_c2SFSIC_dims[1] = lat_dim;
    ncl_c2SFSIC_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "ncl_c2SFSIC", NC_DOUBLE, RANK_ncl_c2SFSIC, ncl_c2SFSIC_dims, &ncl_c2SFSIC_id);
    check_err(stat,__LINE__,__FILE__);

    ncl_c2SFSIS_dims[0] = time_dim;
    ncl_c2SFSIS_dims[1] = lat_dim;
    ncl_c2SFSIS_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "ncl_c2SFSIS", NC_DOUBLE, RANK_ncl_c2SFSIS, ncl_c2SFSIS_dims, &ncl_c2SFSIS_id);
    check_err(stat,__LINE__,__FILE__);

    ncl_c2SFWET_dims[0] = time_dim;
    ncl_c2SFWET_dims[1] = lat_dim;
    ncl_c2SFWET_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "ncl_c2SFWET", NC_DOUBLE, RANK_ncl_c2SFWET, ncl_c2SFWET_dims, &ncl_c2SFWET_id);
    check_err(stat,__LINE__,__FILE__);

    ncl_c2TBF_dims[0] = time_dim;
    ncl_c2TBF_dims[1] = lat_dim;
    ncl_c2TBF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "ncl_c2TBF", NC_DOUBLE, RANK_ncl_c2TBF, ncl_c2TBF_dims, &ncl_c2TBF_id);
    check_err(stat,__LINE__,__FILE__);

    ncl_c2_sfcsiz3_dims[0] = time_dim;
    ncl_c2_sfcsiz3_dims[1] = lat_dim;
    ncl_c2_sfcsiz3_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "ncl_c2_sfcsiz3", NC_DOUBLE, RANK_ncl_c2_sfcsiz3, ncl_c2_sfcsiz3_dims, &ncl_c2_sfcsiz3_id);
    check_err(stat,__LINE__,__FILE__);

    ncl_c2_sfcsiz4_dims[0] = time_dim;
    ncl_c2_sfcsiz4_dims[1] = lat_dim;
    ncl_c2_sfcsiz4_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "ncl_c2_sfcsiz4", NC_DOUBLE, RANK_ncl_c2_sfcsiz4, ncl_c2_sfcsiz4_dims, &ncl_c2_sfcsiz4_id);
    check_err(stat,__LINE__,__FILE__);

    ncl_c2_sfgaex2_dims[0] = time_dim;
    ncl_c2_sfgaex2_dims[1] = lat_dim;
    ncl_c2_sfgaex2_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "ncl_c2_sfgaex2", NC_DOUBLE, RANK_ncl_c2_sfgaex2, ncl_c2_sfgaex2_dims, &ncl_c2_sfgaex2_id);
    check_err(stat,__LINE__,__FILE__);

    ncl_c3_dims[0] = time_dim;
    ncl_c3_dims[1] = lev_dim;
    ncl_c3_dims[2] = lat_dim;
    ncl_c3_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "ncl_c3", NC_DOUBLE, RANK_ncl_c3, ncl_c3_dims, &ncl_c3_id);
    check_err(stat,__LINE__,__FILE__);

    ncl_c3DDF_dims[0] = time_dim;
    ncl_c3DDF_dims[1] = lat_dim;
    ncl_c3DDF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "ncl_c3DDF", NC_DOUBLE, RANK_ncl_c3DDF, ncl_c3DDF_dims, &ncl_c3DDF_id);
    check_err(stat,__LINE__,__FILE__);

    ncl_c3GVF_dims[0] = time_dim;
    ncl_c3GVF_dims[1] = lat_dim;
    ncl_c3GVF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "ncl_c3GVF", NC_DOUBLE, RANK_ncl_c3GVF, ncl_c3GVF_dims, &ncl_c3GVF_id);
    check_err(stat,__LINE__,__FILE__);

    ncl_c3SFSBC_dims[0] = time_dim;
    ncl_c3SFSBC_dims[1] = lat_dim;
    ncl_c3SFSBC_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "ncl_c3SFSBC", NC_DOUBLE, RANK_ncl_c3SFSBC, ncl_c3SFSBC_dims, &ncl_c3SFSBC_id);
    check_err(stat,__LINE__,__FILE__);

    ncl_c3SFSBS_dims[0] = time_dim;
    ncl_c3SFSBS_dims[1] = lat_dim;
    ncl_c3SFSBS_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "ncl_c3SFSBS", NC_DOUBLE, RANK_ncl_c3SFSBS, ncl_c3SFSBS_dims, &ncl_c3SFSBS_id);
    check_err(stat,__LINE__,__FILE__);

    ncl_c3SFSIC_dims[0] = time_dim;
    ncl_c3SFSIC_dims[1] = lat_dim;
    ncl_c3SFSIC_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "ncl_c3SFSIC", NC_DOUBLE, RANK_ncl_c3SFSIC, ncl_c3SFSIC_dims, &ncl_c3SFSIC_id);
    check_err(stat,__LINE__,__FILE__);

    ncl_c3SFSIS_dims[0] = time_dim;
    ncl_c3SFSIS_dims[1] = lat_dim;
    ncl_c3SFSIS_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "ncl_c3SFSIS", NC_DOUBLE, RANK_ncl_c3SFSIS, ncl_c3SFSIS_dims, &ncl_c3SFSIS_id);
    check_err(stat,__LINE__,__FILE__);

    ncl_c3SFWET_dims[0] = time_dim;
    ncl_c3SFWET_dims[1] = lat_dim;
    ncl_c3SFWET_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "ncl_c3SFWET", NC_DOUBLE, RANK_ncl_c3SFWET, ncl_c3SFWET_dims, &ncl_c3SFWET_id);
    check_err(stat,__LINE__,__FILE__);

    ncl_c3TBF_dims[0] = time_dim;
    ncl_c3TBF_dims[1] = lat_dim;
    ncl_c3TBF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "ncl_c3TBF", NC_DOUBLE, RANK_ncl_c3TBF, ncl_c3TBF_dims, &ncl_c3TBF_id);
    check_err(stat,__LINE__,__FILE__);

    num_a1_dims[0] = time_dim;
    num_a1_dims[1] = lev_dim;
    num_a1_dims[2] = lat_dim;
    num_a1_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "num_a1", NC_DOUBLE, RANK_num_a1, num_a1_dims, &num_a1_id);
    check_err(stat,__LINE__,__FILE__);

    num_a1DDF_dims[0] = time_dim;
    num_a1DDF_dims[1] = lat_dim;
    num_a1DDF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "num_a1DDF", NC_DOUBLE, RANK_num_a1DDF, num_a1DDF_dims, &num_a1DDF_id);
    check_err(stat,__LINE__,__FILE__);

    num_a1GVF_dims[0] = time_dim;
    num_a1GVF_dims[1] = lat_dim;
    num_a1GVF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "num_a1GVF", NC_DOUBLE, RANK_num_a1GVF, num_a1GVF_dims, &num_a1GVF_id);
    check_err(stat,__LINE__,__FILE__);

    num_a1SFSBC_dims[0] = time_dim;
    num_a1SFSBC_dims[1] = lat_dim;
    num_a1SFSBC_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "num_a1SFSBC", NC_DOUBLE, RANK_num_a1SFSBC, num_a1SFSBC_dims, &num_a1SFSBC_id);
    check_err(stat,__LINE__,__FILE__);

    num_a1SFSBS_dims[0] = time_dim;
    num_a1SFSBS_dims[1] = lat_dim;
    num_a1SFSBS_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "num_a1SFSBS", NC_DOUBLE, RANK_num_a1SFSBS, num_a1SFSBS_dims, &num_a1SFSBS_id);
    check_err(stat,__LINE__,__FILE__);

    num_a1SFSIC_dims[0] = time_dim;
    num_a1SFSIC_dims[1] = lat_dim;
    num_a1SFSIC_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "num_a1SFSIC", NC_DOUBLE, RANK_num_a1SFSIC, num_a1SFSIC_dims, &num_a1SFSIC_id);
    check_err(stat,__LINE__,__FILE__);

    num_a1SFSIS_dims[0] = time_dim;
    num_a1SFSIS_dims[1] = lat_dim;
    num_a1SFSIS_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "num_a1SFSIS", NC_DOUBLE, RANK_num_a1SFSIS, num_a1SFSIS_dims, &num_a1SFSIS_id);
    check_err(stat,__LINE__,__FILE__);

    num_a1SFWET_dims[0] = time_dim;
    num_a1SFWET_dims[1] = lat_dim;
    num_a1SFWET_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "num_a1SFWET", NC_DOUBLE, RANK_num_a1SFWET, num_a1SFWET_dims, &num_a1SFWET_id);
    check_err(stat,__LINE__,__FILE__);

    num_a1TBF_dims[0] = time_dim;
    num_a1TBF_dims[1] = lat_dim;
    num_a1TBF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "num_a1TBF", NC_DOUBLE, RANK_num_a1TBF, num_a1TBF_dims, &num_a1TBF_id);
    check_err(stat,__LINE__,__FILE__);

    num_a1_CLXF_dims[0] = time_dim;
    num_a1_CLXF_dims[1] = lat_dim;
    num_a1_CLXF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "num_a1_CLXF", NC_DOUBLE, RANK_num_a1_CLXF, num_a1_CLXF_dims, &num_a1_CLXF_id);
    check_err(stat,__LINE__,__FILE__);

    num_a1_XFRC_dims[0] = time_dim;
    num_a1_XFRC_dims[1] = lev_dim;
    num_a1_XFRC_dims[2] = lat_dim;
    num_a1_XFRC_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "num_a1_XFRC", NC_DOUBLE, RANK_num_a1_XFRC, num_a1_XFRC_dims, &num_a1_XFRC_id);
    check_err(stat,__LINE__,__FILE__);

    num_a1_sfcoag1_dims[0] = time_dim;
    num_a1_sfcoag1_dims[1] = lat_dim;
    num_a1_sfcoag1_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "num_a1_sfcoag1", NC_DOUBLE, RANK_num_a1_sfcoag1, num_a1_sfcoag1_dims, &num_a1_sfcoag1_id);
    check_err(stat,__LINE__,__FILE__);

    num_a1_sfcsiz1_dims[0] = time_dim;
    num_a1_sfcsiz1_dims[1] = lat_dim;
    num_a1_sfcsiz1_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "num_a1_sfcsiz1", NC_DOUBLE, RANK_num_a1_sfcsiz1, num_a1_sfcsiz1_dims, &num_a1_sfcsiz1_id);
    check_err(stat,__LINE__,__FILE__);

    num_a1_sfcsiz2_dims[0] = time_dim;
    num_a1_sfcsiz2_dims[1] = lat_dim;
    num_a1_sfcsiz2_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "num_a1_sfcsiz2", NC_DOUBLE, RANK_num_a1_sfcsiz2, num_a1_sfcsiz2_dims, &num_a1_sfcsiz2_id);
    check_err(stat,__LINE__,__FILE__);

    num_a1_sfcsiz3_dims[0] = time_dim;
    num_a1_sfcsiz3_dims[1] = lat_dim;
    num_a1_sfcsiz3_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "num_a1_sfcsiz3", NC_DOUBLE, RANK_num_a1_sfcsiz3, num_a1_sfcsiz3_dims, &num_a1_sfcsiz3_id);
    check_err(stat,__LINE__,__FILE__);

    num_a1_sfcsiz4_dims[0] = time_dim;
    num_a1_sfcsiz4_dims[1] = lat_dim;
    num_a1_sfcsiz4_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "num_a1_sfcsiz4", NC_DOUBLE, RANK_num_a1_sfcsiz4, num_a1_sfcsiz4_dims, &num_a1_sfcsiz4_id);
    check_err(stat,__LINE__,__FILE__);

    num_a1_sfgaex2_dims[0] = time_dim;
    num_a1_sfgaex2_dims[1] = lat_dim;
    num_a1_sfgaex2_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "num_a1_sfgaex2", NC_DOUBLE, RANK_num_a1_sfgaex2, num_a1_sfgaex2_dims, &num_a1_sfgaex2_id);
    check_err(stat,__LINE__,__FILE__);

    num_a2_dims[0] = time_dim;
    num_a2_dims[1] = lev_dim;
    num_a2_dims[2] = lat_dim;
    num_a2_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "num_a2", NC_DOUBLE, RANK_num_a2, num_a2_dims, &num_a2_id);
    check_err(stat,__LINE__,__FILE__);

    num_a2DDF_dims[0] = time_dim;
    num_a2DDF_dims[1] = lat_dim;
    num_a2DDF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "num_a2DDF", NC_DOUBLE, RANK_num_a2DDF, num_a2DDF_dims, &num_a2DDF_id);
    check_err(stat,__LINE__,__FILE__);

    num_a2GVF_dims[0] = time_dim;
    num_a2GVF_dims[1] = lat_dim;
    num_a2GVF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "num_a2GVF", NC_DOUBLE, RANK_num_a2GVF, num_a2GVF_dims, &num_a2GVF_id);
    check_err(stat,__LINE__,__FILE__);

    num_a2SFSBC_dims[0] = time_dim;
    num_a2SFSBC_dims[1] = lat_dim;
    num_a2SFSBC_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "num_a2SFSBC", NC_DOUBLE, RANK_num_a2SFSBC, num_a2SFSBC_dims, &num_a2SFSBC_id);
    check_err(stat,__LINE__,__FILE__);

    num_a2SFSBS_dims[0] = time_dim;
    num_a2SFSBS_dims[1] = lat_dim;
    num_a2SFSBS_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "num_a2SFSBS", NC_DOUBLE, RANK_num_a2SFSBS, num_a2SFSBS_dims, &num_a2SFSBS_id);
    check_err(stat,__LINE__,__FILE__);

    num_a2SFSIC_dims[0] = time_dim;
    num_a2SFSIC_dims[1] = lat_dim;
    num_a2SFSIC_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "num_a2SFSIC", NC_DOUBLE, RANK_num_a2SFSIC, num_a2SFSIC_dims, &num_a2SFSIC_id);
    check_err(stat,__LINE__,__FILE__);

    num_a2SFSIS_dims[0] = time_dim;
    num_a2SFSIS_dims[1] = lat_dim;
    num_a2SFSIS_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "num_a2SFSIS", NC_DOUBLE, RANK_num_a2SFSIS, num_a2SFSIS_dims, &num_a2SFSIS_id);
    check_err(stat,__LINE__,__FILE__);

    num_a2SFWET_dims[0] = time_dim;
    num_a2SFWET_dims[1] = lat_dim;
    num_a2SFWET_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "num_a2SFWET", NC_DOUBLE, RANK_num_a2SFWET, num_a2SFWET_dims, &num_a2SFWET_id);
    check_err(stat,__LINE__,__FILE__);

    num_a2TBF_dims[0] = time_dim;
    num_a2TBF_dims[1] = lat_dim;
    num_a2TBF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "num_a2TBF", NC_DOUBLE, RANK_num_a2TBF, num_a2TBF_dims, &num_a2TBF_id);
    check_err(stat,__LINE__,__FILE__);

    num_a2_CLXF_dims[0] = time_dim;
    num_a2_CLXF_dims[1] = lat_dim;
    num_a2_CLXF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "num_a2_CLXF", NC_DOUBLE, RANK_num_a2_CLXF, num_a2_CLXF_dims, &num_a2_CLXF_id);
    check_err(stat,__LINE__,__FILE__);

    num_a2_XFRC_dims[0] = time_dim;
    num_a2_XFRC_dims[1] = lev_dim;
    num_a2_XFRC_dims[2] = lat_dim;
    num_a2_XFRC_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "num_a2_XFRC", NC_DOUBLE, RANK_num_a2_XFRC, num_a2_XFRC_dims, &num_a2_XFRC_id);
    check_err(stat,__LINE__,__FILE__);

    num_a2_sfcoag1_dims[0] = time_dim;
    num_a2_sfcoag1_dims[1] = lat_dim;
    num_a2_sfcoag1_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "num_a2_sfcoag1", NC_DOUBLE, RANK_num_a2_sfcoag1, num_a2_sfcoag1_dims, &num_a2_sfcoag1_id);
    check_err(stat,__LINE__,__FILE__);

    num_a2_sfcsiz1_dims[0] = time_dim;
    num_a2_sfcsiz1_dims[1] = lat_dim;
    num_a2_sfcsiz1_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "num_a2_sfcsiz1", NC_DOUBLE, RANK_num_a2_sfcsiz1, num_a2_sfcsiz1_dims, &num_a2_sfcsiz1_id);
    check_err(stat,__LINE__,__FILE__);

    num_a2_sfcsiz2_dims[0] = time_dim;
    num_a2_sfcsiz2_dims[1] = lat_dim;
    num_a2_sfcsiz2_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "num_a2_sfcsiz2", NC_DOUBLE, RANK_num_a2_sfcsiz2, num_a2_sfcsiz2_dims, &num_a2_sfcsiz2_id);
    check_err(stat,__LINE__,__FILE__);

    num_a2_sfcsiz3_dims[0] = time_dim;
    num_a2_sfcsiz3_dims[1] = lat_dim;
    num_a2_sfcsiz3_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "num_a2_sfcsiz3", NC_DOUBLE, RANK_num_a2_sfcsiz3, num_a2_sfcsiz3_dims, &num_a2_sfcsiz3_id);
    check_err(stat,__LINE__,__FILE__);

    num_a2_sfcsiz4_dims[0] = time_dim;
    num_a2_sfcsiz4_dims[1] = lat_dim;
    num_a2_sfcsiz4_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "num_a2_sfcsiz4", NC_DOUBLE, RANK_num_a2_sfcsiz4, num_a2_sfcsiz4_dims, &num_a2_sfcsiz4_id);
    check_err(stat,__LINE__,__FILE__);

    num_a2_sfgaex2_dims[0] = time_dim;
    num_a2_sfgaex2_dims[1] = lat_dim;
    num_a2_sfgaex2_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "num_a2_sfgaex2", NC_DOUBLE, RANK_num_a2_sfgaex2, num_a2_sfgaex2_dims, &num_a2_sfgaex2_id);
    check_err(stat,__LINE__,__FILE__);

    num_a2_sfnnuc1_dims[0] = time_dim;
    num_a2_sfnnuc1_dims[1] = lat_dim;
    num_a2_sfnnuc1_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "num_a2_sfnnuc1", NC_DOUBLE, RANK_num_a2_sfnnuc1, num_a2_sfnnuc1_dims, &num_a2_sfnnuc1_id);
    check_err(stat,__LINE__,__FILE__);

    num_a3_dims[0] = time_dim;
    num_a3_dims[1] = lev_dim;
    num_a3_dims[2] = lat_dim;
    num_a3_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "num_a3", NC_DOUBLE, RANK_num_a3, num_a3_dims, &num_a3_id);
    check_err(stat,__LINE__,__FILE__);

    num_a3DDF_dims[0] = time_dim;
    num_a3DDF_dims[1] = lat_dim;
    num_a3DDF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "num_a3DDF", NC_DOUBLE, RANK_num_a3DDF, num_a3DDF_dims, &num_a3DDF_id);
    check_err(stat,__LINE__,__FILE__);

    num_a3GVF_dims[0] = time_dim;
    num_a3GVF_dims[1] = lat_dim;
    num_a3GVF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "num_a3GVF", NC_DOUBLE, RANK_num_a3GVF, num_a3GVF_dims, &num_a3GVF_id);
    check_err(stat,__LINE__,__FILE__);

    num_a3SFSBC_dims[0] = time_dim;
    num_a3SFSBC_dims[1] = lat_dim;
    num_a3SFSBC_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "num_a3SFSBC", NC_DOUBLE, RANK_num_a3SFSBC, num_a3SFSBC_dims, &num_a3SFSBC_id);
    check_err(stat,__LINE__,__FILE__);

    num_a3SFSBS_dims[0] = time_dim;
    num_a3SFSBS_dims[1] = lat_dim;
    num_a3SFSBS_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "num_a3SFSBS", NC_DOUBLE, RANK_num_a3SFSBS, num_a3SFSBS_dims, &num_a3SFSBS_id);
    check_err(stat,__LINE__,__FILE__);

    num_a3SFSIC_dims[0] = time_dim;
    num_a3SFSIC_dims[1] = lat_dim;
    num_a3SFSIC_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "num_a3SFSIC", NC_DOUBLE, RANK_num_a3SFSIC, num_a3SFSIC_dims, &num_a3SFSIC_id);
    check_err(stat,__LINE__,__FILE__);

    num_a3SFSIS_dims[0] = time_dim;
    num_a3SFSIS_dims[1] = lat_dim;
    num_a3SFSIS_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "num_a3SFSIS", NC_DOUBLE, RANK_num_a3SFSIS, num_a3SFSIS_dims, &num_a3SFSIS_id);
    check_err(stat,__LINE__,__FILE__);

    num_a3SFWET_dims[0] = time_dim;
    num_a3SFWET_dims[1] = lat_dim;
    num_a3SFWET_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "num_a3SFWET", NC_DOUBLE, RANK_num_a3SFWET, num_a3SFWET_dims, &num_a3SFWET_id);
    check_err(stat,__LINE__,__FILE__);

    num_a3TBF_dims[0] = time_dim;
    num_a3TBF_dims[1] = lat_dim;
    num_a3TBF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "num_a3TBF", NC_DOUBLE, RANK_num_a3TBF, num_a3TBF_dims, &num_a3TBF_id);
    check_err(stat,__LINE__,__FILE__);

    num_a3_sfcsiz1_dims[0] = time_dim;
    num_a3_sfcsiz1_dims[1] = lat_dim;
    num_a3_sfcsiz1_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "num_a3_sfcsiz1", NC_DOUBLE, RANK_num_a3_sfcsiz1, num_a3_sfcsiz1_dims, &num_a3_sfcsiz1_id);
    check_err(stat,__LINE__,__FILE__);

    num_a3_sfcsiz2_dims[0] = time_dim;
    num_a3_sfcsiz2_dims[1] = lat_dim;
    num_a3_sfcsiz2_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "num_a3_sfcsiz2", NC_DOUBLE, RANK_num_a3_sfcsiz2, num_a3_sfcsiz2_dims, &num_a3_sfcsiz2_id);
    check_err(stat,__LINE__,__FILE__);

    num_c1_dims[0] = time_dim;
    num_c1_dims[1] = lev_dim;
    num_c1_dims[2] = lat_dim;
    num_c1_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "num_c1", NC_DOUBLE, RANK_num_c1, num_c1_dims, &num_c1_id);
    check_err(stat,__LINE__,__FILE__);

    num_c1DDF_dims[0] = time_dim;
    num_c1DDF_dims[1] = lat_dim;
    num_c1DDF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "num_c1DDF", NC_DOUBLE, RANK_num_c1DDF, num_c1DDF_dims, &num_c1DDF_id);
    check_err(stat,__LINE__,__FILE__);

    num_c1GVF_dims[0] = time_dim;
    num_c1GVF_dims[1] = lat_dim;
    num_c1GVF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "num_c1GVF", NC_DOUBLE, RANK_num_c1GVF, num_c1GVF_dims, &num_c1GVF_id);
    check_err(stat,__LINE__,__FILE__);

    num_c1SFSBC_dims[0] = time_dim;
    num_c1SFSBC_dims[1] = lat_dim;
    num_c1SFSBC_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "num_c1SFSBC", NC_DOUBLE, RANK_num_c1SFSBC, num_c1SFSBC_dims, &num_c1SFSBC_id);
    check_err(stat,__LINE__,__FILE__);

    num_c1SFSBS_dims[0] = time_dim;
    num_c1SFSBS_dims[1] = lat_dim;
    num_c1SFSBS_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "num_c1SFSBS", NC_DOUBLE, RANK_num_c1SFSBS, num_c1SFSBS_dims, &num_c1SFSBS_id);
    check_err(stat,__LINE__,__FILE__);

    num_c1SFSIC_dims[0] = time_dim;
    num_c1SFSIC_dims[1] = lat_dim;
    num_c1SFSIC_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "num_c1SFSIC", NC_DOUBLE, RANK_num_c1SFSIC, num_c1SFSIC_dims, &num_c1SFSIC_id);
    check_err(stat,__LINE__,__FILE__);

    num_c1SFSIS_dims[0] = time_dim;
    num_c1SFSIS_dims[1] = lat_dim;
    num_c1SFSIS_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "num_c1SFSIS", NC_DOUBLE, RANK_num_c1SFSIS, num_c1SFSIS_dims, &num_c1SFSIS_id);
    check_err(stat,__LINE__,__FILE__);

    num_c1SFWET_dims[0] = time_dim;
    num_c1SFWET_dims[1] = lat_dim;
    num_c1SFWET_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "num_c1SFWET", NC_DOUBLE, RANK_num_c1SFWET, num_c1SFWET_dims, &num_c1SFWET_id);
    check_err(stat,__LINE__,__FILE__);

    num_c1TBF_dims[0] = time_dim;
    num_c1TBF_dims[1] = lat_dim;
    num_c1TBF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "num_c1TBF", NC_DOUBLE, RANK_num_c1TBF, num_c1TBF_dims, &num_c1TBF_id);
    check_err(stat,__LINE__,__FILE__);

    num_c1_sfcsiz1_dims[0] = time_dim;
    num_c1_sfcsiz1_dims[1] = lat_dim;
    num_c1_sfcsiz1_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "num_c1_sfcsiz1", NC_DOUBLE, RANK_num_c1_sfcsiz1, num_c1_sfcsiz1_dims, &num_c1_sfcsiz1_id);
    check_err(stat,__LINE__,__FILE__);

    num_c1_sfcsiz2_dims[0] = time_dim;
    num_c1_sfcsiz2_dims[1] = lat_dim;
    num_c1_sfcsiz2_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "num_c1_sfcsiz2", NC_DOUBLE, RANK_num_c1_sfcsiz2, num_c1_sfcsiz2_dims, &num_c1_sfcsiz2_id);
    check_err(stat,__LINE__,__FILE__);

    num_c1_sfcsiz3_dims[0] = time_dim;
    num_c1_sfcsiz3_dims[1] = lat_dim;
    num_c1_sfcsiz3_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "num_c1_sfcsiz3", NC_DOUBLE, RANK_num_c1_sfcsiz3, num_c1_sfcsiz3_dims, &num_c1_sfcsiz3_id);
    check_err(stat,__LINE__,__FILE__);

    num_c1_sfcsiz4_dims[0] = time_dim;
    num_c1_sfcsiz4_dims[1] = lat_dim;
    num_c1_sfcsiz4_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "num_c1_sfcsiz4", NC_DOUBLE, RANK_num_c1_sfcsiz4, num_c1_sfcsiz4_dims, &num_c1_sfcsiz4_id);
    check_err(stat,__LINE__,__FILE__);

    num_c1_sfgaex2_dims[0] = time_dim;
    num_c1_sfgaex2_dims[1] = lat_dim;
    num_c1_sfgaex2_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "num_c1_sfgaex2", NC_DOUBLE, RANK_num_c1_sfgaex2, num_c1_sfgaex2_dims, &num_c1_sfgaex2_id);
    check_err(stat,__LINE__,__FILE__);

    num_c2_dims[0] = time_dim;
    num_c2_dims[1] = lev_dim;
    num_c2_dims[2] = lat_dim;
    num_c2_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "num_c2", NC_DOUBLE, RANK_num_c2, num_c2_dims, &num_c2_id);
    check_err(stat,__LINE__,__FILE__);

    num_c2DDF_dims[0] = time_dim;
    num_c2DDF_dims[1] = lat_dim;
    num_c2DDF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "num_c2DDF", NC_DOUBLE, RANK_num_c2DDF, num_c2DDF_dims, &num_c2DDF_id);
    check_err(stat,__LINE__,__FILE__);

    num_c2GVF_dims[0] = time_dim;
    num_c2GVF_dims[1] = lat_dim;
    num_c2GVF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "num_c2GVF", NC_DOUBLE, RANK_num_c2GVF, num_c2GVF_dims, &num_c2GVF_id);
    check_err(stat,__LINE__,__FILE__);

    num_c2SFSBC_dims[0] = time_dim;
    num_c2SFSBC_dims[1] = lat_dim;
    num_c2SFSBC_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "num_c2SFSBC", NC_DOUBLE, RANK_num_c2SFSBC, num_c2SFSBC_dims, &num_c2SFSBC_id);
    check_err(stat,__LINE__,__FILE__);

    num_c2SFSBS_dims[0] = time_dim;
    num_c2SFSBS_dims[1] = lat_dim;
    num_c2SFSBS_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "num_c2SFSBS", NC_DOUBLE, RANK_num_c2SFSBS, num_c2SFSBS_dims, &num_c2SFSBS_id);
    check_err(stat,__LINE__,__FILE__);

    num_c2SFSIC_dims[0] = time_dim;
    num_c2SFSIC_dims[1] = lat_dim;
    num_c2SFSIC_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "num_c2SFSIC", NC_DOUBLE, RANK_num_c2SFSIC, num_c2SFSIC_dims, &num_c2SFSIC_id);
    check_err(stat,__LINE__,__FILE__);

    num_c2SFSIS_dims[0] = time_dim;
    num_c2SFSIS_dims[1] = lat_dim;
    num_c2SFSIS_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "num_c2SFSIS", NC_DOUBLE, RANK_num_c2SFSIS, num_c2SFSIS_dims, &num_c2SFSIS_id);
    check_err(stat,__LINE__,__FILE__);

    num_c2SFWET_dims[0] = time_dim;
    num_c2SFWET_dims[1] = lat_dim;
    num_c2SFWET_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "num_c2SFWET", NC_DOUBLE, RANK_num_c2SFWET, num_c2SFWET_dims, &num_c2SFWET_id);
    check_err(stat,__LINE__,__FILE__);

    num_c2TBF_dims[0] = time_dim;
    num_c2TBF_dims[1] = lat_dim;
    num_c2TBF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "num_c2TBF", NC_DOUBLE, RANK_num_c2TBF, num_c2TBF_dims, &num_c2TBF_id);
    check_err(stat,__LINE__,__FILE__);

    num_c2_sfcsiz1_dims[0] = time_dim;
    num_c2_sfcsiz1_dims[1] = lat_dim;
    num_c2_sfcsiz1_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "num_c2_sfcsiz1", NC_DOUBLE, RANK_num_c2_sfcsiz1, num_c2_sfcsiz1_dims, &num_c2_sfcsiz1_id);
    check_err(stat,__LINE__,__FILE__);

    num_c2_sfcsiz2_dims[0] = time_dim;
    num_c2_sfcsiz2_dims[1] = lat_dim;
    num_c2_sfcsiz2_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "num_c2_sfcsiz2", NC_DOUBLE, RANK_num_c2_sfcsiz2, num_c2_sfcsiz2_dims, &num_c2_sfcsiz2_id);
    check_err(stat,__LINE__,__FILE__);

    num_c2_sfcsiz3_dims[0] = time_dim;
    num_c2_sfcsiz3_dims[1] = lat_dim;
    num_c2_sfcsiz3_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "num_c2_sfcsiz3", NC_DOUBLE, RANK_num_c2_sfcsiz3, num_c2_sfcsiz3_dims, &num_c2_sfcsiz3_id);
    check_err(stat,__LINE__,__FILE__);

    num_c2_sfcsiz4_dims[0] = time_dim;
    num_c2_sfcsiz4_dims[1] = lat_dim;
    num_c2_sfcsiz4_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "num_c2_sfcsiz4", NC_DOUBLE, RANK_num_c2_sfcsiz4, num_c2_sfcsiz4_dims, &num_c2_sfcsiz4_id);
    check_err(stat,__LINE__,__FILE__);

    num_c2_sfgaex2_dims[0] = time_dim;
    num_c2_sfgaex2_dims[1] = lat_dim;
    num_c2_sfgaex2_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "num_c2_sfgaex2", NC_DOUBLE, RANK_num_c2_sfgaex2, num_c2_sfgaex2_dims, &num_c2_sfgaex2_id);
    check_err(stat,__LINE__,__FILE__);

    num_c3_dims[0] = time_dim;
    num_c3_dims[1] = lev_dim;
    num_c3_dims[2] = lat_dim;
    num_c3_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "num_c3", NC_DOUBLE, RANK_num_c3, num_c3_dims, &num_c3_id);
    check_err(stat,__LINE__,__FILE__);

    num_c3DDF_dims[0] = time_dim;
    num_c3DDF_dims[1] = lat_dim;
    num_c3DDF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "num_c3DDF", NC_DOUBLE, RANK_num_c3DDF, num_c3DDF_dims, &num_c3DDF_id);
    check_err(stat,__LINE__,__FILE__);

    num_c3GVF_dims[0] = time_dim;
    num_c3GVF_dims[1] = lat_dim;
    num_c3GVF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "num_c3GVF", NC_DOUBLE, RANK_num_c3GVF, num_c3GVF_dims, &num_c3GVF_id);
    check_err(stat,__LINE__,__FILE__);

    num_c3SFSBC_dims[0] = time_dim;
    num_c3SFSBC_dims[1] = lat_dim;
    num_c3SFSBC_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "num_c3SFSBC", NC_DOUBLE, RANK_num_c3SFSBC, num_c3SFSBC_dims, &num_c3SFSBC_id);
    check_err(stat,__LINE__,__FILE__);

    num_c3SFSBS_dims[0] = time_dim;
    num_c3SFSBS_dims[1] = lat_dim;
    num_c3SFSBS_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "num_c3SFSBS", NC_DOUBLE, RANK_num_c3SFSBS, num_c3SFSBS_dims, &num_c3SFSBS_id);
    check_err(stat,__LINE__,__FILE__);

    num_c3SFSIC_dims[0] = time_dim;
    num_c3SFSIC_dims[1] = lat_dim;
    num_c3SFSIC_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "num_c3SFSIC", NC_DOUBLE, RANK_num_c3SFSIC, num_c3SFSIC_dims, &num_c3SFSIC_id);
    check_err(stat,__LINE__,__FILE__);

    num_c3SFSIS_dims[0] = time_dim;
    num_c3SFSIS_dims[1] = lat_dim;
    num_c3SFSIS_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "num_c3SFSIS", NC_DOUBLE, RANK_num_c3SFSIS, num_c3SFSIS_dims, &num_c3SFSIS_id);
    check_err(stat,__LINE__,__FILE__);

    num_c3SFWET_dims[0] = time_dim;
    num_c3SFWET_dims[1] = lat_dim;
    num_c3SFWET_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "num_c3SFWET", NC_DOUBLE, RANK_num_c3SFWET, num_c3SFWET_dims, &num_c3SFWET_id);
    check_err(stat,__LINE__,__FILE__);

    num_c3TBF_dims[0] = time_dim;
    num_c3TBF_dims[1] = lat_dim;
    num_c3TBF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "num_c3TBF", NC_DOUBLE, RANK_num_c3TBF, num_c3TBF_dims, &num_c3TBF_id);
    check_err(stat,__LINE__,__FILE__);

    num_c3_sfcsiz1_dims[0] = time_dim;
    num_c3_sfcsiz1_dims[1] = lat_dim;
    num_c3_sfcsiz1_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "num_c3_sfcsiz1", NC_DOUBLE, RANK_num_c3_sfcsiz1, num_c3_sfcsiz1_dims, &num_c3_sfcsiz1_id);
    check_err(stat,__LINE__,__FILE__);

    num_c3_sfcsiz2_dims[0] = time_dim;
    num_c3_sfcsiz2_dims[1] = lat_dim;
    num_c3_sfcsiz2_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "num_c3_sfcsiz2", NC_DOUBLE, RANK_num_c3_sfcsiz2, num_c3_sfcsiz2_dims, &num_c3_sfcsiz2_id);
    check_err(stat,__LINE__,__FILE__);

    pom_a1_dims[0] = time_dim;
    pom_a1_dims[1] = lev_dim;
    pom_a1_dims[2] = lat_dim;
    pom_a1_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "pom_a1", NC_DOUBLE, RANK_pom_a1, pom_a1_dims, &pom_a1_id);
    check_err(stat,__LINE__,__FILE__);

    pom_a1DDF_dims[0] = time_dim;
    pom_a1DDF_dims[1] = lat_dim;
    pom_a1DDF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "pom_a1DDF", NC_DOUBLE, RANK_pom_a1DDF, pom_a1DDF_dims, &pom_a1DDF_id);
    check_err(stat,__LINE__,__FILE__);

    pom_a1GVF_dims[0] = time_dim;
    pom_a1GVF_dims[1] = lat_dim;
    pom_a1GVF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "pom_a1GVF", NC_DOUBLE, RANK_pom_a1GVF, pom_a1GVF_dims, &pom_a1GVF_id);
    check_err(stat,__LINE__,__FILE__);

    pom_a1SFSBC_dims[0] = time_dim;
    pom_a1SFSBC_dims[1] = lat_dim;
    pom_a1SFSBC_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "pom_a1SFSBC", NC_DOUBLE, RANK_pom_a1SFSBC, pom_a1SFSBC_dims, &pom_a1SFSBC_id);
    check_err(stat,__LINE__,__FILE__);

    pom_a1SFSBS_dims[0] = time_dim;
    pom_a1SFSBS_dims[1] = lat_dim;
    pom_a1SFSBS_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "pom_a1SFSBS", NC_DOUBLE, RANK_pom_a1SFSBS, pom_a1SFSBS_dims, &pom_a1SFSBS_id);
    check_err(stat,__LINE__,__FILE__);

    pom_a1SFSIC_dims[0] = time_dim;
    pom_a1SFSIC_dims[1] = lat_dim;
    pom_a1SFSIC_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "pom_a1SFSIC", NC_DOUBLE, RANK_pom_a1SFSIC, pom_a1SFSIC_dims, &pom_a1SFSIC_id);
    check_err(stat,__LINE__,__FILE__);

    pom_a1SFSIS_dims[0] = time_dim;
    pom_a1SFSIS_dims[1] = lat_dim;
    pom_a1SFSIS_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "pom_a1SFSIS", NC_DOUBLE, RANK_pom_a1SFSIS, pom_a1SFSIS_dims, &pom_a1SFSIS_id);
    check_err(stat,__LINE__,__FILE__);

    pom_a1SFWET_dims[0] = time_dim;
    pom_a1SFWET_dims[1] = lat_dim;
    pom_a1SFWET_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "pom_a1SFWET", NC_DOUBLE, RANK_pom_a1SFWET, pom_a1SFWET_dims, &pom_a1SFWET_id);
    check_err(stat,__LINE__,__FILE__);

    pom_a1TBF_dims[0] = time_dim;
    pom_a1TBF_dims[1] = lat_dim;
    pom_a1TBF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "pom_a1TBF", NC_DOUBLE, RANK_pom_a1TBF, pom_a1TBF_dims, &pom_a1TBF_id);
    check_err(stat,__LINE__,__FILE__);

    pom_a1_CLXF_dims[0] = time_dim;
    pom_a1_CLXF_dims[1] = lat_dim;
    pom_a1_CLXF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "pom_a1_CLXF", NC_DOUBLE, RANK_pom_a1_CLXF, pom_a1_CLXF_dims, &pom_a1_CLXF_id);
    check_err(stat,__LINE__,__FILE__);

    pom_a1_XFRC_dims[0] = time_dim;
    pom_a1_XFRC_dims[1] = lev_dim;
    pom_a1_XFRC_dims[2] = lat_dim;
    pom_a1_XFRC_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "pom_a1_XFRC", NC_DOUBLE, RANK_pom_a1_XFRC, pom_a1_XFRC_dims, &pom_a1_XFRC_id);
    check_err(stat,__LINE__,__FILE__);

    pom_c1_dims[0] = time_dim;
    pom_c1_dims[1] = lev_dim;
    pom_c1_dims[2] = lat_dim;
    pom_c1_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "pom_c1", NC_DOUBLE, RANK_pom_c1, pom_c1_dims, &pom_c1_id);
    check_err(stat,__LINE__,__FILE__);

    pom_c1DDF_dims[0] = time_dim;
    pom_c1DDF_dims[1] = lat_dim;
    pom_c1DDF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "pom_c1DDF", NC_DOUBLE, RANK_pom_c1DDF, pom_c1DDF_dims, &pom_c1DDF_id);
    check_err(stat,__LINE__,__FILE__);

    pom_c1GVF_dims[0] = time_dim;
    pom_c1GVF_dims[1] = lat_dim;
    pom_c1GVF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "pom_c1GVF", NC_DOUBLE, RANK_pom_c1GVF, pom_c1GVF_dims, &pom_c1GVF_id);
    check_err(stat,__LINE__,__FILE__);

    pom_c1SFSBC_dims[0] = time_dim;
    pom_c1SFSBC_dims[1] = lat_dim;
    pom_c1SFSBC_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "pom_c1SFSBC", NC_DOUBLE, RANK_pom_c1SFSBC, pom_c1SFSBC_dims, &pom_c1SFSBC_id);
    check_err(stat,__LINE__,__FILE__);

    pom_c1SFSBS_dims[0] = time_dim;
    pom_c1SFSBS_dims[1] = lat_dim;
    pom_c1SFSBS_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "pom_c1SFSBS", NC_DOUBLE, RANK_pom_c1SFSBS, pom_c1SFSBS_dims, &pom_c1SFSBS_id);
    check_err(stat,__LINE__,__FILE__);

    pom_c1SFSIC_dims[0] = time_dim;
    pom_c1SFSIC_dims[1] = lat_dim;
    pom_c1SFSIC_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "pom_c1SFSIC", NC_DOUBLE, RANK_pom_c1SFSIC, pom_c1SFSIC_dims, &pom_c1SFSIC_id);
    check_err(stat,__LINE__,__FILE__);

    pom_c1SFSIS_dims[0] = time_dim;
    pom_c1SFSIS_dims[1] = lat_dim;
    pom_c1SFSIS_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "pom_c1SFSIS", NC_DOUBLE, RANK_pom_c1SFSIS, pom_c1SFSIS_dims, &pom_c1SFSIS_id);
    check_err(stat,__LINE__,__FILE__);

    pom_c1SFWET_dims[0] = time_dim;
    pom_c1SFWET_dims[1] = lat_dim;
    pom_c1SFWET_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "pom_c1SFWET", NC_DOUBLE, RANK_pom_c1SFWET, pom_c1SFWET_dims, &pom_c1SFWET_id);
    check_err(stat,__LINE__,__FILE__);

    pom_c1TBF_dims[0] = time_dim;
    pom_c1TBF_dims[1] = lat_dim;
    pom_c1TBF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "pom_c1TBF", NC_DOUBLE, RANK_pom_c1TBF, pom_c1TBF_dims, &pom_c1TBF_id);
    check_err(stat,__LINE__,__FILE__);

    so4_a1_dims[0] = time_dim;
    so4_a1_dims[1] = lev_dim;
    so4_a1_dims[2] = lat_dim;
    so4_a1_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "so4_a1", NC_DOUBLE, RANK_so4_a1, so4_a1_dims, &so4_a1_id);
    check_err(stat,__LINE__,__FILE__);

    so4_a1DDF_dims[0] = time_dim;
    so4_a1DDF_dims[1] = lat_dim;
    so4_a1DDF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "so4_a1DDF", NC_DOUBLE, RANK_so4_a1DDF, so4_a1DDF_dims, &so4_a1DDF_id);
    check_err(stat,__LINE__,__FILE__);

    so4_a1GVF_dims[0] = time_dim;
    so4_a1GVF_dims[1] = lat_dim;
    so4_a1GVF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "so4_a1GVF", NC_DOUBLE, RANK_so4_a1GVF, so4_a1GVF_dims, &so4_a1GVF_id);
    check_err(stat,__LINE__,__FILE__);

    so4_a1SFSBC_dims[0] = time_dim;
    so4_a1SFSBC_dims[1] = lat_dim;
    so4_a1SFSBC_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "so4_a1SFSBC", NC_DOUBLE, RANK_so4_a1SFSBC, so4_a1SFSBC_dims, &so4_a1SFSBC_id);
    check_err(stat,__LINE__,__FILE__);

    so4_a1SFSBS_dims[0] = time_dim;
    so4_a1SFSBS_dims[1] = lat_dim;
    so4_a1SFSBS_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "so4_a1SFSBS", NC_DOUBLE, RANK_so4_a1SFSBS, so4_a1SFSBS_dims, &so4_a1SFSBS_id);
    check_err(stat,__LINE__,__FILE__);

    so4_a1SFSIC_dims[0] = time_dim;
    so4_a1SFSIC_dims[1] = lat_dim;
    so4_a1SFSIC_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "so4_a1SFSIC", NC_DOUBLE, RANK_so4_a1SFSIC, so4_a1SFSIC_dims, &so4_a1SFSIC_id);
    check_err(stat,__LINE__,__FILE__);

    so4_a1SFSIS_dims[0] = time_dim;
    so4_a1SFSIS_dims[1] = lat_dim;
    so4_a1SFSIS_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "so4_a1SFSIS", NC_DOUBLE, RANK_so4_a1SFSIS, so4_a1SFSIS_dims, &so4_a1SFSIS_id);
    check_err(stat,__LINE__,__FILE__);

    so4_a1SFWET_dims[0] = time_dim;
    so4_a1SFWET_dims[1] = lat_dim;
    so4_a1SFWET_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "so4_a1SFWET", NC_DOUBLE, RANK_so4_a1SFWET, so4_a1SFWET_dims, &so4_a1SFWET_id);
    check_err(stat,__LINE__,__FILE__);

    so4_a1TBF_dims[0] = time_dim;
    so4_a1TBF_dims[1] = lat_dim;
    so4_a1TBF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "so4_a1TBF", NC_DOUBLE, RANK_so4_a1TBF, so4_a1TBF_dims, &so4_a1TBF_id);
    check_err(stat,__LINE__,__FILE__);

    so4_a1_CLXF_dims[0] = time_dim;
    so4_a1_CLXF_dims[1] = lat_dim;
    so4_a1_CLXF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "so4_a1_CLXF", NC_DOUBLE, RANK_so4_a1_CLXF, so4_a1_CLXF_dims, &so4_a1_CLXF_id);
    check_err(stat,__LINE__,__FILE__);

    so4_a1_XFRC_dims[0] = time_dim;
    so4_a1_XFRC_dims[1] = lev_dim;
    so4_a1_XFRC_dims[2] = lat_dim;
    so4_a1_XFRC_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "so4_a1_XFRC", NC_DOUBLE, RANK_so4_a1_XFRC, so4_a1_XFRC_dims, &so4_a1_XFRC_id);
    check_err(stat,__LINE__,__FILE__);

    so4_a1_sfcoag1_dims[0] = time_dim;
    so4_a1_sfcoag1_dims[1] = lat_dim;
    so4_a1_sfcoag1_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "so4_a1_sfcoag1", NC_DOUBLE, RANK_so4_a1_sfcoag1, so4_a1_sfcoag1_dims, &so4_a1_sfcoag1_id);
    check_err(stat,__LINE__,__FILE__);

    so4_a1_sfcsiz3_dims[0] = time_dim;
    so4_a1_sfcsiz3_dims[1] = lat_dim;
    so4_a1_sfcsiz3_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "so4_a1_sfcsiz3", NC_DOUBLE, RANK_so4_a1_sfcsiz3, so4_a1_sfcsiz3_dims, &so4_a1_sfcsiz3_id);
    check_err(stat,__LINE__,__FILE__);

    so4_a1_sfcsiz4_dims[0] = time_dim;
    so4_a1_sfcsiz4_dims[1] = lat_dim;
    so4_a1_sfcsiz4_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "so4_a1_sfcsiz4", NC_DOUBLE, RANK_so4_a1_sfcsiz4, so4_a1_sfcsiz4_dims, &so4_a1_sfcsiz4_id);
    check_err(stat,__LINE__,__FILE__);

    so4_a1_sfgaex1_dims[0] = time_dim;
    so4_a1_sfgaex1_dims[1] = lat_dim;
    so4_a1_sfgaex1_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "so4_a1_sfgaex1", NC_DOUBLE, RANK_so4_a1_sfgaex1, so4_a1_sfgaex1_dims, &so4_a1_sfgaex1_id);
    check_err(stat,__LINE__,__FILE__);

    so4_a1_sfgaex2_dims[0] = time_dim;
    so4_a1_sfgaex2_dims[1] = lat_dim;
    so4_a1_sfgaex2_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "so4_a1_sfgaex2", NC_DOUBLE, RANK_so4_a1_sfgaex2, so4_a1_sfgaex2_dims, &so4_a1_sfgaex2_id);
    check_err(stat,__LINE__,__FILE__);

    so4_a2_dims[0] = time_dim;
    so4_a2_dims[1] = lev_dim;
    so4_a2_dims[2] = lat_dim;
    so4_a2_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "so4_a2", NC_DOUBLE, RANK_so4_a2, so4_a2_dims, &so4_a2_id);
    check_err(stat,__LINE__,__FILE__);

    so4_a2DDF_dims[0] = time_dim;
    so4_a2DDF_dims[1] = lat_dim;
    so4_a2DDF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "so4_a2DDF", NC_DOUBLE, RANK_so4_a2DDF, so4_a2DDF_dims, &so4_a2DDF_id);
    check_err(stat,__LINE__,__FILE__);

    so4_a2GVF_dims[0] = time_dim;
    so4_a2GVF_dims[1] = lat_dim;
    so4_a2GVF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "so4_a2GVF", NC_DOUBLE, RANK_so4_a2GVF, so4_a2GVF_dims, &so4_a2GVF_id);
    check_err(stat,__LINE__,__FILE__);

    so4_a2SFSBC_dims[0] = time_dim;
    so4_a2SFSBC_dims[1] = lat_dim;
    so4_a2SFSBC_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "so4_a2SFSBC", NC_DOUBLE, RANK_so4_a2SFSBC, so4_a2SFSBC_dims, &so4_a2SFSBC_id);
    check_err(stat,__LINE__,__FILE__);

    so4_a2SFSBS_dims[0] = time_dim;
    so4_a2SFSBS_dims[1] = lat_dim;
    so4_a2SFSBS_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "so4_a2SFSBS", NC_DOUBLE, RANK_so4_a2SFSBS, so4_a2SFSBS_dims, &so4_a2SFSBS_id);
    check_err(stat,__LINE__,__FILE__);

    so4_a2SFSIC_dims[0] = time_dim;
    so4_a2SFSIC_dims[1] = lat_dim;
    so4_a2SFSIC_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "so4_a2SFSIC", NC_DOUBLE, RANK_so4_a2SFSIC, so4_a2SFSIC_dims, &so4_a2SFSIC_id);
    check_err(stat,__LINE__,__FILE__);

    so4_a2SFSIS_dims[0] = time_dim;
    so4_a2SFSIS_dims[1] = lat_dim;
    so4_a2SFSIS_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "so4_a2SFSIS", NC_DOUBLE, RANK_so4_a2SFSIS, so4_a2SFSIS_dims, &so4_a2SFSIS_id);
    check_err(stat,__LINE__,__FILE__);

    so4_a2SFWET_dims[0] = time_dim;
    so4_a2SFWET_dims[1] = lat_dim;
    so4_a2SFWET_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "so4_a2SFWET", NC_DOUBLE, RANK_so4_a2SFWET, so4_a2SFWET_dims, &so4_a2SFWET_id);
    check_err(stat,__LINE__,__FILE__);

    so4_a2TBF_dims[0] = time_dim;
    so4_a2TBF_dims[1] = lat_dim;
    so4_a2TBF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "so4_a2TBF", NC_DOUBLE, RANK_so4_a2TBF, so4_a2TBF_dims, &so4_a2TBF_id);
    check_err(stat,__LINE__,__FILE__);

    so4_a2_CLXF_dims[0] = time_dim;
    so4_a2_CLXF_dims[1] = lat_dim;
    so4_a2_CLXF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "so4_a2_CLXF", NC_DOUBLE, RANK_so4_a2_CLXF, so4_a2_CLXF_dims, &so4_a2_CLXF_id);
    check_err(stat,__LINE__,__FILE__);

    so4_a2_XFRC_dims[0] = time_dim;
    so4_a2_XFRC_dims[1] = lev_dim;
    so4_a2_XFRC_dims[2] = lat_dim;
    so4_a2_XFRC_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "so4_a2_XFRC", NC_DOUBLE, RANK_so4_a2_XFRC, so4_a2_XFRC_dims, &so4_a2_XFRC_id);
    check_err(stat,__LINE__,__FILE__);

    so4_a2_sfcoag1_dims[0] = time_dim;
    so4_a2_sfcoag1_dims[1] = lat_dim;
    so4_a2_sfcoag1_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "so4_a2_sfcoag1", NC_DOUBLE, RANK_so4_a2_sfcoag1, so4_a2_sfcoag1_dims, &so4_a2_sfcoag1_id);
    check_err(stat,__LINE__,__FILE__);

    so4_a2_sfcsiz3_dims[0] = time_dim;
    so4_a2_sfcsiz3_dims[1] = lat_dim;
    so4_a2_sfcsiz3_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "so4_a2_sfcsiz3", NC_DOUBLE, RANK_so4_a2_sfcsiz3, so4_a2_sfcsiz3_dims, &so4_a2_sfcsiz3_id);
    check_err(stat,__LINE__,__FILE__);

    so4_a2_sfcsiz4_dims[0] = time_dim;
    so4_a2_sfcsiz4_dims[1] = lat_dim;
    so4_a2_sfcsiz4_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "so4_a2_sfcsiz4", NC_DOUBLE, RANK_so4_a2_sfcsiz4, so4_a2_sfcsiz4_dims, &so4_a2_sfcsiz4_id);
    check_err(stat,__LINE__,__FILE__);

    so4_a2_sfgaex1_dims[0] = time_dim;
    so4_a2_sfgaex1_dims[1] = lat_dim;
    so4_a2_sfgaex1_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "so4_a2_sfgaex1", NC_DOUBLE, RANK_so4_a2_sfgaex1, so4_a2_sfgaex1_dims, &so4_a2_sfgaex1_id);
    check_err(stat,__LINE__,__FILE__);

    so4_a2_sfgaex2_dims[0] = time_dim;
    so4_a2_sfgaex2_dims[1] = lat_dim;
    so4_a2_sfgaex2_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "so4_a2_sfgaex2", NC_DOUBLE, RANK_so4_a2_sfgaex2, so4_a2_sfgaex2_dims, &so4_a2_sfgaex2_id);
    check_err(stat,__LINE__,__FILE__);

    so4_a2_sfnnuc1_dims[0] = time_dim;
    so4_a2_sfnnuc1_dims[1] = lat_dim;
    so4_a2_sfnnuc1_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "so4_a2_sfnnuc1", NC_DOUBLE, RANK_so4_a2_sfnnuc1, so4_a2_sfnnuc1_dims, &so4_a2_sfnnuc1_id);
    check_err(stat,__LINE__,__FILE__);

    so4_a3_dims[0] = time_dim;
    so4_a3_dims[1] = lev_dim;
    so4_a3_dims[2] = lat_dim;
    so4_a3_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "so4_a3", NC_DOUBLE, RANK_so4_a3, so4_a3_dims, &so4_a3_id);
    check_err(stat,__LINE__,__FILE__);

    so4_a3DDF_dims[0] = time_dim;
    so4_a3DDF_dims[1] = lat_dim;
    so4_a3DDF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "so4_a3DDF", NC_DOUBLE, RANK_so4_a3DDF, so4_a3DDF_dims, &so4_a3DDF_id);
    check_err(stat,__LINE__,__FILE__);

    so4_a3GVF_dims[0] = time_dim;
    so4_a3GVF_dims[1] = lat_dim;
    so4_a3GVF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "so4_a3GVF", NC_DOUBLE, RANK_so4_a3GVF, so4_a3GVF_dims, &so4_a3GVF_id);
    check_err(stat,__LINE__,__FILE__);

    so4_a3SFSBC_dims[0] = time_dim;
    so4_a3SFSBC_dims[1] = lat_dim;
    so4_a3SFSBC_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "so4_a3SFSBC", NC_DOUBLE, RANK_so4_a3SFSBC, so4_a3SFSBC_dims, &so4_a3SFSBC_id);
    check_err(stat,__LINE__,__FILE__);

    so4_a3SFSBS_dims[0] = time_dim;
    so4_a3SFSBS_dims[1] = lat_dim;
    so4_a3SFSBS_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "so4_a3SFSBS", NC_DOUBLE, RANK_so4_a3SFSBS, so4_a3SFSBS_dims, &so4_a3SFSBS_id);
    check_err(stat,__LINE__,__FILE__);

    so4_a3SFSIC_dims[0] = time_dim;
    so4_a3SFSIC_dims[1] = lat_dim;
    so4_a3SFSIC_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "so4_a3SFSIC", NC_DOUBLE, RANK_so4_a3SFSIC, so4_a3SFSIC_dims, &so4_a3SFSIC_id);
    check_err(stat,__LINE__,__FILE__);

    so4_a3SFSIS_dims[0] = time_dim;
    so4_a3SFSIS_dims[1] = lat_dim;
    so4_a3SFSIS_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "so4_a3SFSIS", NC_DOUBLE, RANK_so4_a3SFSIS, so4_a3SFSIS_dims, &so4_a3SFSIS_id);
    check_err(stat,__LINE__,__FILE__);

    so4_a3SFWET_dims[0] = time_dim;
    so4_a3SFWET_dims[1] = lat_dim;
    so4_a3SFWET_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "so4_a3SFWET", NC_DOUBLE, RANK_so4_a3SFWET, so4_a3SFWET_dims, &so4_a3SFWET_id);
    check_err(stat,__LINE__,__FILE__);

    so4_a3TBF_dims[0] = time_dim;
    so4_a3TBF_dims[1] = lat_dim;
    so4_a3TBF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "so4_a3TBF", NC_DOUBLE, RANK_so4_a3TBF, so4_a3TBF_dims, &so4_a3TBF_id);
    check_err(stat,__LINE__,__FILE__);

    so4_a3_sfgaex1_dims[0] = time_dim;
    so4_a3_sfgaex1_dims[1] = lat_dim;
    so4_a3_sfgaex1_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "so4_a3_sfgaex1", NC_DOUBLE, RANK_so4_a3_sfgaex1, so4_a3_sfgaex1_dims, &so4_a3_sfgaex1_id);
    check_err(stat,__LINE__,__FILE__);

    so4_c1_dims[0] = time_dim;
    so4_c1_dims[1] = lev_dim;
    so4_c1_dims[2] = lat_dim;
    so4_c1_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "so4_c1", NC_DOUBLE, RANK_so4_c1, so4_c1_dims, &so4_c1_id);
    check_err(stat,__LINE__,__FILE__);

    so4_c1AQH2SO4_dims[0] = time_dim;
    so4_c1AQH2SO4_dims[1] = lat_dim;
    so4_c1AQH2SO4_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "so4_c1AQH2SO4", NC_DOUBLE, RANK_so4_c1AQH2SO4, so4_c1AQH2SO4_dims, &so4_c1AQH2SO4_id);
    check_err(stat,__LINE__,__FILE__);

    so4_c1AQSO4_dims[0] = time_dim;
    so4_c1AQSO4_dims[1] = lat_dim;
    so4_c1AQSO4_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "so4_c1AQSO4", NC_DOUBLE, RANK_so4_c1AQSO4, so4_c1AQSO4_dims, &so4_c1AQSO4_id);
    check_err(stat,__LINE__,__FILE__);

    so4_c1DDF_dims[0] = time_dim;
    so4_c1DDF_dims[1] = lat_dim;
    so4_c1DDF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "so4_c1DDF", NC_DOUBLE, RANK_so4_c1DDF, so4_c1DDF_dims, &so4_c1DDF_id);
    check_err(stat,__LINE__,__FILE__);

    so4_c1GVF_dims[0] = time_dim;
    so4_c1GVF_dims[1] = lat_dim;
    so4_c1GVF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "so4_c1GVF", NC_DOUBLE, RANK_so4_c1GVF, so4_c1GVF_dims, &so4_c1GVF_id);
    check_err(stat,__LINE__,__FILE__);

    so4_c1SFSBC_dims[0] = time_dim;
    so4_c1SFSBC_dims[1] = lat_dim;
    so4_c1SFSBC_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "so4_c1SFSBC", NC_DOUBLE, RANK_so4_c1SFSBC, so4_c1SFSBC_dims, &so4_c1SFSBC_id);
    check_err(stat,__LINE__,__FILE__);

    so4_c1SFSBS_dims[0] = time_dim;
    so4_c1SFSBS_dims[1] = lat_dim;
    so4_c1SFSBS_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "so4_c1SFSBS", NC_DOUBLE, RANK_so4_c1SFSBS, so4_c1SFSBS_dims, &so4_c1SFSBS_id);
    check_err(stat,__LINE__,__FILE__);

    so4_c1SFSIC_dims[0] = time_dim;
    so4_c1SFSIC_dims[1] = lat_dim;
    so4_c1SFSIC_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "so4_c1SFSIC", NC_DOUBLE, RANK_so4_c1SFSIC, so4_c1SFSIC_dims, &so4_c1SFSIC_id);
    check_err(stat,__LINE__,__FILE__);

    so4_c1SFSIS_dims[0] = time_dim;
    so4_c1SFSIS_dims[1] = lat_dim;
    so4_c1SFSIS_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "so4_c1SFSIS", NC_DOUBLE, RANK_so4_c1SFSIS, so4_c1SFSIS_dims, &so4_c1SFSIS_id);
    check_err(stat,__LINE__,__FILE__);

    so4_c1SFWET_dims[0] = time_dim;
    so4_c1SFWET_dims[1] = lat_dim;
    so4_c1SFWET_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "so4_c1SFWET", NC_DOUBLE, RANK_so4_c1SFWET, so4_c1SFWET_dims, &so4_c1SFWET_id);
    check_err(stat,__LINE__,__FILE__);

    so4_c1TBF_dims[0] = time_dim;
    so4_c1TBF_dims[1] = lat_dim;
    so4_c1TBF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "so4_c1TBF", NC_DOUBLE, RANK_so4_c1TBF, so4_c1TBF_dims, &so4_c1TBF_id);
    check_err(stat,__LINE__,__FILE__);

    so4_c1_sfcsiz3_dims[0] = time_dim;
    so4_c1_sfcsiz3_dims[1] = lat_dim;
    so4_c1_sfcsiz3_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "so4_c1_sfcsiz3", NC_DOUBLE, RANK_so4_c1_sfcsiz3, so4_c1_sfcsiz3_dims, &so4_c1_sfcsiz3_id);
    check_err(stat,__LINE__,__FILE__);

    so4_c1_sfcsiz4_dims[0] = time_dim;
    so4_c1_sfcsiz4_dims[1] = lat_dim;
    so4_c1_sfcsiz4_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "so4_c1_sfcsiz4", NC_DOUBLE, RANK_so4_c1_sfcsiz4, so4_c1_sfcsiz4_dims, &so4_c1_sfcsiz4_id);
    check_err(stat,__LINE__,__FILE__);

    so4_c1_sfgaex2_dims[0] = time_dim;
    so4_c1_sfgaex2_dims[1] = lat_dim;
    so4_c1_sfgaex2_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "so4_c1_sfgaex2", NC_DOUBLE, RANK_so4_c1_sfgaex2, so4_c1_sfgaex2_dims, &so4_c1_sfgaex2_id);
    check_err(stat,__LINE__,__FILE__);

    so4_c2_dims[0] = time_dim;
    so4_c2_dims[1] = lev_dim;
    so4_c2_dims[2] = lat_dim;
    so4_c2_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "so4_c2", NC_DOUBLE, RANK_so4_c2, so4_c2_dims, &so4_c2_id);
    check_err(stat,__LINE__,__FILE__);

    so4_c2AQH2SO4_dims[0] = time_dim;
    so4_c2AQH2SO4_dims[1] = lat_dim;
    so4_c2AQH2SO4_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "so4_c2AQH2SO4", NC_DOUBLE, RANK_so4_c2AQH2SO4, so4_c2AQH2SO4_dims, &so4_c2AQH2SO4_id);
    check_err(stat,__LINE__,__FILE__);

    so4_c2AQSO4_dims[0] = time_dim;
    so4_c2AQSO4_dims[1] = lat_dim;
    so4_c2AQSO4_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "so4_c2AQSO4", NC_DOUBLE, RANK_so4_c2AQSO4, so4_c2AQSO4_dims, &so4_c2AQSO4_id);
    check_err(stat,__LINE__,__FILE__);

    so4_c2DDF_dims[0] = time_dim;
    so4_c2DDF_dims[1] = lat_dim;
    so4_c2DDF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "so4_c2DDF", NC_DOUBLE, RANK_so4_c2DDF, so4_c2DDF_dims, &so4_c2DDF_id);
    check_err(stat,__LINE__,__FILE__);

    so4_c2GVF_dims[0] = time_dim;
    so4_c2GVF_dims[1] = lat_dim;
    so4_c2GVF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "so4_c2GVF", NC_DOUBLE, RANK_so4_c2GVF, so4_c2GVF_dims, &so4_c2GVF_id);
    check_err(stat,__LINE__,__FILE__);

    so4_c2SFSBC_dims[0] = time_dim;
    so4_c2SFSBC_dims[1] = lat_dim;
    so4_c2SFSBC_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "so4_c2SFSBC", NC_DOUBLE, RANK_so4_c2SFSBC, so4_c2SFSBC_dims, &so4_c2SFSBC_id);
    check_err(stat,__LINE__,__FILE__);

    so4_c2SFSBS_dims[0] = time_dim;
    so4_c2SFSBS_dims[1] = lat_dim;
    so4_c2SFSBS_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "so4_c2SFSBS", NC_DOUBLE, RANK_so4_c2SFSBS, so4_c2SFSBS_dims, &so4_c2SFSBS_id);
    check_err(stat,__LINE__,__FILE__);

    so4_c2SFSIC_dims[0] = time_dim;
    so4_c2SFSIC_dims[1] = lat_dim;
    so4_c2SFSIC_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "so4_c2SFSIC", NC_DOUBLE, RANK_so4_c2SFSIC, so4_c2SFSIC_dims, &so4_c2SFSIC_id);
    check_err(stat,__LINE__,__FILE__);

    so4_c2SFSIS_dims[0] = time_dim;
    so4_c2SFSIS_dims[1] = lat_dim;
    so4_c2SFSIS_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "so4_c2SFSIS", NC_DOUBLE, RANK_so4_c2SFSIS, so4_c2SFSIS_dims, &so4_c2SFSIS_id);
    check_err(stat,__LINE__,__FILE__);

    so4_c2SFWET_dims[0] = time_dim;
    so4_c2SFWET_dims[1] = lat_dim;
    so4_c2SFWET_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "so4_c2SFWET", NC_DOUBLE, RANK_so4_c2SFWET, so4_c2SFWET_dims, &so4_c2SFWET_id);
    check_err(stat,__LINE__,__FILE__);

    so4_c2TBF_dims[0] = time_dim;
    so4_c2TBF_dims[1] = lat_dim;
    so4_c2TBF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "so4_c2TBF", NC_DOUBLE, RANK_so4_c2TBF, so4_c2TBF_dims, &so4_c2TBF_id);
    check_err(stat,__LINE__,__FILE__);

    so4_c2_sfcsiz3_dims[0] = time_dim;
    so4_c2_sfcsiz3_dims[1] = lat_dim;
    so4_c2_sfcsiz3_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "so4_c2_sfcsiz3", NC_DOUBLE, RANK_so4_c2_sfcsiz3, so4_c2_sfcsiz3_dims, &so4_c2_sfcsiz3_id);
    check_err(stat,__LINE__,__FILE__);

    so4_c2_sfcsiz4_dims[0] = time_dim;
    so4_c2_sfcsiz4_dims[1] = lat_dim;
    so4_c2_sfcsiz4_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "so4_c2_sfcsiz4", NC_DOUBLE, RANK_so4_c2_sfcsiz4, so4_c2_sfcsiz4_dims, &so4_c2_sfcsiz4_id);
    check_err(stat,__LINE__,__FILE__);

    so4_c2_sfgaex2_dims[0] = time_dim;
    so4_c2_sfgaex2_dims[1] = lat_dim;
    so4_c2_sfgaex2_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "so4_c2_sfgaex2", NC_DOUBLE, RANK_so4_c2_sfgaex2, so4_c2_sfgaex2_dims, &so4_c2_sfgaex2_id);
    check_err(stat,__LINE__,__FILE__);

    so4_c3_dims[0] = time_dim;
    so4_c3_dims[1] = lev_dim;
    so4_c3_dims[2] = lat_dim;
    so4_c3_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "so4_c3", NC_DOUBLE, RANK_so4_c3, so4_c3_dims, &so4_c3_id);
    check_err(stat,__LINE__,__FILE__);

    so4_c3AQH2SO4_dims[0] = time_dim;
    so4_c3AQH2SO4_dims[1] = lat_dim;
    so4_c3AQH2SO4_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "so4_c3AQH2SO4", NC_DOUBLE, RANK_so4_c3AQH2SO4, so4_c3AQH2SO4_dims, &so4_c3AQH2SO4_id);
    check_err(stat,__LINE__,__FILE__);

    so4_c3AQSO4_dims[0] = time_dim;
    so4_c3AQSO4_dims[1] = lat_dim;
    so4_c3AQSO4_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "so4_c3AQSO4", NC_DOUBLE, RANK_so4_c3AQSO4, so4_c3AQSO4_dims, &so4_c3AQSO4_id);
    check_err(stat,__LINE__,__FILE__);

    so4_c3DDF_dims[0] = time_dim;
    so4_c3DDF_dims[1] = lat_dim;
    so4_c3DDF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "so4_c3DDF", NC_DOUBLE, RANK_so4_c3DDF, so4_c3DDF_dims, &so4_c3DDF_id);
    check_err(stat,__LINE__,__FILE__);

    so4_c3GVF_dims[0] = time_dim;
    so4_c3GVF_dims[1] = lat_dim;
    so4_c3GVF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "so4_c3GVF", NC_DOUBLE, RANK_so4_c3GVF, so4_c3GVF_dims, &so4_c3GVF_id);
    check_err(stat,__LINE__,__FILE__);

    so4_c3SFSBC_dims[0] = time_dim;
    so4_c3SFSBC_dims[1] = lat_dim;
    so4_c3SFSBC_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "so4_c3SFSBC", NC_DOUBLE, RANK_so4_c3SFSBC, so4_c3SFSBC_dims, &so4_c3SFSBC_id);
    check_err(stat,__LINE__,__FILE__);

    so4_c3SFSBS_dims[0] = time_dim;
    so4_c3SFSBS_dims[1] = lat_dim;
    so4_c3SFSBS_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "so4_c3SFSBS", NC_DOUBLE, RANK_so4_c3SFSBS, so4_c3SFSBS_dims, &so4_c3SFSBS_id);
    check_err(stat,__LINE__,__FILE__);

    so4_c3SFSIC_dims[0] = time_dim;
    so4_c3SFSIC_dims[1] = lat_dim;
    so4_c3SFSIC_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "so4_c3SFSIC", NC_DOUBLE, RANK_so4_c3SFSIC, so4_c3SFSIC_dims, &so4_c3SFSIC_id);
    check_err(stat,__LINE__,__FILE__);

    so4_c3SFSIS_dims[0] = time_dim;
    so4_c3SFSIS_dims[1] = lat_dim;
    so4_c3SFSIS_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "so4_c3SFSIS", NC_DOUBLE, RANK_so4_c3SFSIS, so4_c3SFSIS_dims, &so4_c3SFSIS_id);
    check_err(stat,__LINE__,__FILE__);

    so4_c3SFWET_dims[0] = time_dim;
    so4_c3SFWET_dims[1] = lat_dim;
    so4_c3SFWET_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "so4_c3SFWET", NC_DOUBLE, RANK_so4_c3SFWET, so4_c3SFWET_dims, &so4_c3SFWET_id);
    check_err(stat,__LINE__,__FILE__);

    so4_c3TBF_dims[0] = time_dim;
    so4_c3TBF_dims[1] = lat_dim;
    so4_c3TBF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "so4_c3TBF", NC_DOUBLE, RANK_so4_c3TBF, so4_c3TBF_dims, &so4_c3TBF_id);
    check_err(stat,__LINE__,__FILE__);

    soa_a1_dims[0] = time_dim;
    soa_a1_dims[1] = lev_dim;
    soa_a1_dims[2] = lat_dim;
    soa_a1_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "soa_a1", NC_DOUBLE, RANK_soa_a1, soa_a1_dims, &soa_a1_id);
    check_err(stat,__LINE__,__FILE__);

    soa_a1DDF_dims[0] = time_dim;
    soa_a1DDF_dims[1] = lat_dim;
    soa_a1DDF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "soa_a1DDF", NC_DOUBLE, RANK_soa_a1DDF, soa_a1DDF_dims, &soa_a1DDF_id);
    check_err(stat,__LINE__,__FILE__);

    soa_a1GVF_dims[0] = time_dim;
    soa_a1GVF_dims[1] = lat_dim;
    soa_a1GVF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "soa_a1GVF", NC_DOUBLE, RANK_soa_a1GVF, soa_a1GVF_dims, &soa_a1GVF_id);
    check_err(stat,__LINE__,__FILE__);

    soa_a1SFSBC_dims[0] = time_dim;
    soa_a1SFSBC_dims[1] = lat_dim;
    soa_a1SFSBC_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "soa_a1SFSBC", NC_DOUBLE, RANK_soa_a1SFSBC, soa_a1SFSBC_dims, &soa_a1SFSBC_id);
    check_err(stat,__LINE__,__FILE__);

    soa_a1SFSBS_dims[0] = time_dim;
    soa_a1SFSBS_dims[1] = lat_dim;
    soa_a1SFSBS_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "soa_a1SFSBS", NC_DOUBLE, RANK_soa_a1SFSBS, soa_a1SFSBS_dims, &soa_a1SFSBS_id);
    check_err(stat,__LINE__,__FILE__);

    soa_a1SFSIC_dims[0] = time_dim;
    soa_a1SFSIC_dims[1] = lat_dim;
    soa_a1SFSIC_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "soa_a1SFSIC", NC_DOUBLE, RANK_soa_a1SFSIC, soa_a1SFSIC_dims, &soa_a1SFSIC_id);
    check_err(stat,__LINE__,__FILE__);

    soa_a1SFSIS_dims[0] = time_dim;
    soa_a1SFSIS_dims[1] = lat_dim;
    soa_a1SFSIS_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "soa_a1SFSIS", NC_DOUBLE, RANK_soa_a1SFSIS, soa_a1SFSIS_dims, &soa_a1SFSIS_id);
    check_err(stat,__LINE__,__FILE__);

    soa_a1SFWET_dims[0] = time_dim;
    soa_a1SFWET_dims[1] = lat_dim;
    soa_a1SFWET_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "soa_a1SFWET", NC_DOUBLE, RANK_soa_a1SFWET, soa_a1SFWET_dims, &soa_a1SFWET_id);
    check_err(stat,__LINE__,__FILE__);

    soa_a1TBF_dims[0] = time_dim;
    soa_a1TBF_dims[1] = lat_dim;
    soa_a1TBF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "soa_a1TBF", NC_DOUBLE, RANK_soa_a1TBF, soa_a1TBF_dims, &soa_a1TBF_id);
    check_err(stat,__LINE__,__FILE__);

    soa_a1_sfcoag1_dims[0] = time_dim;
    soa_a1_sfcoag1_dims[1] = lat_dim;
    soa_a1_sfcoag1_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "soa_a1_sfcoag1", NC_DOUBLE, RANK_soa_a1_sfcoag1, soa_a1_sfcoag1_dims, &soa_a1_sfcoag1_id);
    check_err(stat,__LINE__,__FILE__);

    soa_a1_sfcsiz3_dims[0] = time_dim;
    soa_a1_sfcsiz3_dims[1] = lat_dim;
    soa_a1_sfcsiz3_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "soa_a1_sfcsiz3", NC_DOUBLE, RANK_soa_a1_sfcsiz3, soa_a1_sfcsiz3_dims, &soa_a1_sfcsiz3_id);
    check_err(stat,__LINE__,__FILE__);

    soa_a1_sfcsiz4_dims[0] = time_dim;
    soa_a1_sfcsiz4_dims[1] = lat_dim;
    soa_a1_sfcsiz4_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "soa_a1_sfcsiz4", NC_DOUBLE, RANK_soa_a1_sfcsiz4, soa_a1_sfcsiz4_dims, &soa_a1_sfcsiz4_id);
    check_err(stat,__LINE__,__FILE__);

    soa_a1_sfgaex1_dims[0] = time_dim;
    soa_a1_sfgaex1_dims[1] = lat_dim;
    soa_a1_sfgaex1_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "soa_a1_sfgaex1", NC_DOUBLE, RANK_soa_a1_sfgaex1, soa_a1_sfgaex1_dims, &soa_a1_sfgaex1_id);
    check_err(stat,__LINE__,__FILE__);

    soa_a1_sfgaex2_dims[0] = time_dim;
    soa_a1_sfgaex2_dims[1] = lat_dim;
    soa_a1_sfgaex2_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "soa_a1_sfgaex2", NC_DOUBLE, RANK_soa_a1_sfgaex2, soa_a1_sfgaex2_dims, &soa_a1_sfgaex2_id);
    check_err(stat,__LINE__,__FILE__);

    soa_a2_dims[0] = time_dim;
    soa_a2_dims[1] = lev_dim;
    soa_a2_dims[2] = lat_dim;
    soa_a2_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "soa_a2", NC_DOUBLE, RANK_soa_a2, soa_a2_dims, &soa_a2_id);
    check_err(stat,__LINE__,__FILE__);

    soa_a2DDF_dims[0] = time_dim;
    soa_a2DDF_dims[1] = lat_dim;
    soa_a2DDF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "soa_a2DDF", NC_DOUBLE, RANK_soa_a2DDF, soa_a2DDF_dims, &soa_a2DDF_id);
    check_err(stat,__LINE__,__FILE__);

    soa_a2GVF_dims[0] = time_dim;
    soa_a2GVF_dims[1] = lat_dim;
    soa_a2GVF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "soa_a2GVF", NC_DOUBLE, RANK_soa_a2GVF, soa_a2GVF_dims, &soa_a2GVF_id);
    check_err(stat,__LINE__,__FILE__);

    soa_a2SFSBC_dims[0] = time_dim;
    soa_a2SFSBC_dims[1] = lat_dim;
    soa_a2SFSBC_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "soa_a2SFSBC", NC_DOUBLE, RANK_soa_a2SFSBC, soa_a2SFSBC_dims, &soa_a2SFSBC_id);
    check_err(stat,__LINE__,__FILE__);

    soa_a2SFSBS_dims[0] = time_dim;
    soa_a2SFSBS_dims[1] = lat_dim;
    soa_a2SFSBS_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "soa_a2SFSBS", NC_DOUBLE, RANK_soa_a2SFSBS, soa_a2SFSBS_dims, &soa_a2SFSBS_id);
    check_err(stat,__LINE__,__FILE__);

    soa_a2SFSIC_dims[0] = time_dim;
    soa_a2SFSIC_dims[1] = lat_dim;
    soa_a2SFSIC_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "soa_a2SFSIC", NC_DOUBLE, RANK_soa_a2SFSIC, soa_a2SFSIC_dims, &soa_a2SFSIC_id);
    check_err(stat,__LINE__,__FILE__);

    soa_a2SFSIS_dims[0] = time_dim;
    soa_a2SFSIS_dims[1] = lat_dim;
    soa_a2SFSIS_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "soa_a2SFSIS", NC_DOUBLE, RANK_soa_a2SFSIS, soa_a2SFSIS_dims, &soa_a2SFSIS_id);
    check_err(stat,__LINE__,__FILE__);

    soa_a2SFWET_dims[0] = time_dim;
    soa_a2SFWET_dims[1] = lat_dim;
    soa_a2SFWET_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "soa_a2SFWET", NC_DOUBLE, RANK_soa_a2SFWET, soa_a2SFWET_dims, &soa_a2SFWET_id);
    check_err(stat,__LINE__,__FILE__);

    soa_a2TBF_dims[0] = time_dim;
    soa_a2TBF_dims[1] = lat_dim;
    soa_a2TBF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "soa_a2TBF", NC_DOUBLE, RANK_soa_a2TBF, soa_a2TBF_dims, &soa_a2TBF_id);
    check_err(stat,__LINE__,__FILE__);

    soa_a2_sfcoag1_dims[0] = time_dim;
    soa_a2_sfcoag1_dims[1] = lat_dim;
    soa_a2_sfcoag1_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "soa_a2_sfcoag1", NC_DOUBLE, RANK_soa_a2_sfcoag1, soa_a2_sfcoag1_dims, &soa_a2_sfcoag1_id);
    check_err(stat,__LINE__,__FILE__);

    soa_a2_sfcsiz3_dims[0] = time_dim;
    soa_a2_sfcsiz3_dims[1] = lat_dim;
    soa_a2_sfcsiz3_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "soa_a2_sfcsiz3", NC_DOUBLE, RANK_soa_a2_sfcsiz3, soa_a2_sfcsiz3_dims, &soa_a2_sfcsiz3_id);
    check_err(stat,__LINE__,__FILE__);

    soa_a2_sfcsiz4_dims[0] = time_dim;
    soa_a2_sfcsiz4_dims[1] = lat_dim;
    soa_a2_sfcsiz4_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "soa_a2_sfcsiz4", NC_DOUBLE, RANK_soa_a2_sfcsiz4, soa_a2_sfcsiz4_dims, &soa_a2_sfcsiz4_id);
    check_err(stat,__LINE__,__FILE__);

    soa_a2_sfgaex1_dims[0] = time_dim;
    soa_a2_sfgaex1_dims[1] = lat_dim;
    soa_a2_sfgaex1_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "soa_a2_sfgaex1", NC_DOUBLE, RANK_soa_a2_sfgaex1, soa_a2_sfgaex1_dims, &soa_a2_sfgaex1_id);
    check_err(stat,__LINE__,__FILE__);

    soa_a2_sfgaex2_dims[0] = time_dim;
    soa_a2_sfgaex2_dims[1] = lat_dim;
    soa_a2_sfgaex2_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "soa_a2_sfgaex2", NC_DOUBLE, RANK_soa_a2_sfgaex2, soa_a2_sfgaex2_dims, &soa_a2_sfgaex2_id);
    check_err(stat,__LINE__,__FILE__);

    soa_c1_dims[0] = time_dim;
    soa_c1_dims[1] = lev_dim;
    soa_c1_dims[2] = lat_dim;
    soa_c1_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "soa_c1", NC_DOUBLE, RANK_soa_c1, soa_c1_dims, &soa_c1_id);
    check_err(stat,__LINE__,__FILE__);

    soa_c1DDF_dims[0] = time_dim;
    soa_c1DDF_dims[1] = lat_dim;
    soa_c1DDF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "soa_c1DDF", NC_DOUBLE, RANK_soa_c1DDF, soa_c1DDF_dims, &soa_c1DDF_id);
    check_err(stat,__LINE__,__FILE__);

    soa_c1GVF_dims[0] = time_dim;
    soa_c1GVF_dims[1] = lat_dim;
    soa_c1GVF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "soa_c1GVF", NC_DOUBLE, RANK_soa_c1GVF, soa_c1GVF_dims, &soa_c1GVF_id);
    check_err(stat,__LINE__,__FILE__);

    soa_c1SFSBC_dims[0] = time_dim;
    soa_c1SFSBC_dims[1] = lat_dim;
    soa_c1SFSBC_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "soa_c1SFSBC", NC_DOUBLE, RANK_soa_c1SFSBC, soa_c1SFSBC_dims, &soa_c1SFSBC_id);
    check_err(stat,__LINE__,__FILE__);

    soa_c1SFSBS_dims[0] = time_dim;
    soa_c1SFSBS_dims[1] = lat_dim;
    soa_c1SFSBS_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "soa_c1SFSBS", NC_DOUBLE, RANK_soa_c1SFSBS, soa_c1SFSBS_dims, &soa_c1SFSBS_id);
    check_err(stat,__LINE__,__FILE__);

    soa_c1SFSIC_dims[0] = time_dim;
    soa_c1SFSIC_dims[1] = lat_dim;
    soa_c1SFSIC_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "soa_c1SFSIC", NC_DOUBLE, RANK_soa_c1SFSIC, soa_c1SFSIC_dims, &soa_c1SFSIC_id);
    check_err(stat,__LINE__,__FILE__);

    soa_c1SFSIS_dims[0] = time_dim;
    soa_c1SFSIS_dims[1] = lat_dim;
    soa_c1SFSIS_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "soa_c1SFSIS", NC_DOUBLE, RANK_soa_c1SFSIS, soa_c1SFSIS_dims, &soa_c1SFSIS_id);
    check_err(stat,__LINE__,__FILE__);

    soa_c1SFWET_dims[0] = time_dim;
    soa_c1SFWET_dims[1] = lat_dim;
    soa_c1SFWET_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "soa_c1SFWET", NC_DOUBLE, RANK_soa_c1SFWET, soa_c1SFWET_dims, &soa_c1SFWET_id);
    check_err(stat,__LINE__,__FILE__);

    soa_c1TBF_dims[0] = time_dim;
    soa_c1TBF_dims[1] = lat_dim;
    soa_c1TBF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "soa_c1TBF", NC_DOUBLE, RANK_soa_c1TBF, soa_c1TBF_dims, &soa_c1TBF_id);
    check_err(stat,__LINE__,__FILE__);

    soa_c1_sfcsiz3_dims[0] = time_dim;
    soa_c1_sfcsiz3_dims[1] = lat_dim;
    soa_c1_sfcsiz3_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "soa_c1_sfcsiz3", NC_DOUBLE, RANK_soa_c1_sfcsiz3, soa_c1_sfcsiz3_dims, &soa_c1_sfcsiz3_id);
    check_err(stat,__LINE__,__FILE__);

    soa_c1_sfcsiz4_dims[0] = time_dim;
    soa_c1_sfcsiz4_dims[1] = lat_dim;
    soa_c1_sfcsiz4_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "soa_c1_sfcsiz4", NC_DOUBLE, RANK_soa_c1_sfcsiz4, soa_c1_sfcsiz4_dims, &soa_c1_sfcsiz4_id);
    check_err(stat,__LINE__,__FILE__);

    soa_c1_sfgaex2_dims[0] = time_dim;
    soa_c1_sfgaex2_dims[1] = lat_dim;
    soa_c1_sfgaex2_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "soa_c1_sfgaex2", NC_DOUBLE, RANK_soa_c1_sfgaex2, soa_c1_sfgaex2_dims, &soa_c1_sfgaex2_id);
    check_err(stat,__LINE__,__FILE__);

    soa_c2_dims[0] = time_dim;
    soa_c2_dims[1] = lev_dim;
    soa_c2_dims[2] = lat_dim;
    soa_c2_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "soa_c2", NC_DOUBLE, RANK_soa_c2, soa_c2_dims, &soa_c2_id);
    check_err(stat,__LINE__,__FILE__);

    soa_c2DDF_dims[0] = time_dim;
    soa_c2DDF_dims[1] = lat_dim;
    soa_c2DDF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "soa_c2DDF", NC_DOUBLE, RANK_soa_c2DDF, soa_c2DDF_dims, &soa_c2DDF_id);
    check_err(stat,__LINE__,__FILE__);

    soa_c2GVF_dims[0] = time_dim;
    soa_c2GVF_dims[1] = lat_dim;
    soa_c2GVF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "soa_c2GVF", NC_DOUBLE, RANK_soa_c2GVF, soa_c2GVF_dims, &soa_c2GVF_id);
    check_err(stat,__LINE__,__FILE__);

    soa_c2SFSBC_dims[0] = time_dim;
    soa_c2SFSBC_dims[1] = lat_dim;
    soa_c2SFSBC_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "soa_c2SFSBC", NC_DOUBLE, RANK_soa_c2SFSBC, soa_c2SFSBC_dims, &soa_c2SFSBC_id);
    check_err(stat,__LINE__,__FILE__);

    soa_c2SFSBS_dims[0] = time_dim;
    soa_c2SFSBS_dims[1] = lat_dim;
    soa_c2SFSBS_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "soa_c2SFSBS", NC_DOUBLE, RANK_soa_c2SFSBS, soa_c2SFSBS_dims, &soa_c2SFSBS_id);
    check_err(stat,__LINE__,__FILE__);

    soa_c2SFSIC_dims[0] = time_dim;
    soa_c2SFSIC_dims[1] = lat_dim;
    soa_c2SFSIC_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "soa_c2SFSIC", NC_DOUBLE, RANK_soa_c2SFSIC, soa_c2SFSIC_dims, &soa_c2SFSIC_id);
    check_err(stat,__LINE__,__FILE__);

    soa_c2SFSIS_dims[0] = time_dim;
    soa_c2SFSIS_dims[1] = lat_dim;
    soa_c2SFSIS_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "soa_c2SFSIS", NC_DOUBLE, RANK_soa_c2SFSIS, soa_c2SFSIS_dims, &soa_c2SFSIS_id);
    check_err(stat,__LINE__,__FILE__);

    soa_c2SFWET_dims[0] = time_dim;
    soa_c2SFWET_dims[1] = lat_dim;
    soa_c2SFWET_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "soa_c2SFWET", NC_DOUBLE, RANK_soa_c2SFWET, soa_c2SFWET_dims, &soa_c2SFWET_id);
    check_err(stat,__LINE__,__FILE__);

    soa_c2TBF_dims[0] = time_dim;
    soa_c2TBF_dims[1] = lat_dim;
    soa_c2TBF_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "soa_c2TBF", NC_DOUBLE, RANK_soa_c2TBF, soa_c2TBF_dims, &soa_c2TBF_id);
    check_err(stat,__LINE__,__FILE__);

    soa_c2_sfcsiz3_dims[0] = time_dim;
    soa_c2_sfcsiz3_dims[1] = lat_dim;
    soa_c2_sfcsiz3_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "soa_c2_sfcsiz3", NC_DOUBLE, RANK_soa_c2_sfcsiz3, soa_c2_sfcsiz3_dims, &soa_c2_sfcsiz3_id);
    check_err(stat,__LINE__,__FILE__);

    soa_c2_sfcsiz4_dims[0] = time_dim;
    soa_c2_sfcsiz4_dims[1] = lat_dim;
    soa_c2_sfcsiz4_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "soa_c2_sfcsiz4", NC_DOUBLE, RANK_soa_c2_sfcsiz4, soa_c2_sfcsiz4_dims, &soa_c2_sfcsiz4_id);
    check_err(stat,__LINE__,__FILE__);

    soa_c2_sfgaex2_dims[0] = time_dim;
    soa_c2_sfgaex2_dims[1] = lat_dim;
    soa_c2_sfgaex2_dims[2] = lon_dim;
    stat = nc_def_var(ncid, "soa_c2_sfgaex2", NC_DOUBLE, RANK_soa_c2_sfgaex2, soa_c2_sfgaex2_dims, &soa_c2_sfgaex2_id);
    check_err(stat,__LINE__,__FILE__);

    wat_a1_dims[0] = time_dim;
    wat_a1_dims[1] = lev_dim;
    wat_a1_dims[2] = lat_dim;
    wat_a1_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "wat_a1", NC_DOUBLE, RANK_wat_a1, wat_a1_dims, &wat_a1_id);
    check_err(stat,__LINE__,__FILE__);

    wat_a2_dims[0] = time_dim;
    wat_a2_dims[1] = lev_dim;
    wat_a2_dims[2] = lat_dim;
    wat_a2_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "wat_a2", NC_DOUBLE, RANK_wat_a2, wat_a2_dims, &wat_a2_id);
    check_err(stat,__LINE__,__FILE__);

    wat_a3_dims[0] = time_dim;
    wat_a3_dims[1] = lev_dim;
    wat_a3_dims[2] = lat_dim;
    wat_a3_dims[3] = lon_dim;
    stat = nc_def_var(ncid, "wat_a3", NC_DOUBLE, RANK_wat_a3, wat_a3_dims, &wat_a3_id);
    check_err(stat,__LINE__,__FILE__);

    /* assign global attributes */
    { /* Conventions */
    stat = nc_put_att_text(ncid, NC_GLOBAL, "Conventions", 6, "CF-1.0");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* source */
    stat = nc_put_att_text(ncid, NC_GLOBAL, "source", 3, "CAM");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* case */
    stat = nc_put_att_text(ncid, NC_GLOBAL, "case", 6, "camrun");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* title */
    stat = nc_put_att_text(ncid, NC_GLOBAL, "title", 1, "\000");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* logname */
    stat = nc_put_att_text(ncid, NC_GLOBAL, "logname", 8, "jedwards");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* host */
    stat = nc_put_att_text(ncid, NC_GLOBAL, "host", 1, "\000");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* Version */
    stat = nc_put_att_text(ncid, NC_GLOBAL, "Version", 9, "$Name:  $");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* revision_Id */
    stat = nc_put_att_text(ncid, NC_GLOBAL, "revision_Id", 54, "$Id: ref_camrun.cdl,v 1.1 2010/05/17 14:43:11 ed Exp $");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* initial_file */
    stat = nc_put_att_text(ncid, NC_GLOBAL, "initial_file", 81, "/fs/cgd/csm/inputdata/atm/cam/inic/fv/cami-mam3_0000-01-01_1.9x2.5_L30_c090306.nc");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* topography_file */
    stat = nc_put_att_text(ncid, NC_GLOBAL, "topography_file", 72, "/fs/cgd/csm/inputdata/atm/cam/topo/USGS-gtopo30_1.9x2.5_remap_c050602.nc");
    check_err(stat,__LINE__,__FILE__);
    }


    /* assign per-variable attributes */
    { /* long_name */
    stat = nc_put_att_text(ncid, P0_id, "long_name", 18, "reference pressure");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, P0_id, "units", 2, "Pa");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, lat_id, "long_name", 8, "latitude");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, lat_id, "units", 13, "degrees_north");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, lon_id, "long_name", 9, "longitude");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, lon_id, "units", 12, "degrees_east");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, slat_id, "long_name", 18, "staggered latitude");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, slat_id, "units", 13, "degrees_north");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, slon_id, "long_name", 19, "staggered longitude");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, slon_id, "units", 12, "degrees_east");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, w_stag_id, "long_name", 26, "staggered latitude weights");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, lev_id, "long_name", 38, "hybrid level at midpoints (1000*(A+B))");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, lev_id, "units", 5, "level");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* positive */
    stat = nc_put_att_text(ncid, lev_id, "positive", 4, "down");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* standard_name */
    stat = nc_put_att_text(ncid, lev_id, "standard_name", 43, "atmosphere_hybrid_sigma_pressure_coordinate");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* formula_terms */
    stat = nc_put_att_text(ncid, lev_id, "formula_terms", 29, "a: hyam b: hybm p0: P0 ps: PS");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, ilev_id, "long_name", 39, "hybrid level at interfaces (1000*(A+B))");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, ilev_id, "units", 5, "level");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* positive */
    stat = nc_put_att_text(ncid, ilev_id, "positive", 4, "down");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* standard_name */
    stat = nc_put_att_text(ncid, ilev_id, "standard_name", 43, "atmosphere_hybrid_sigma_pressure_coordinate");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* formula_terms */
    stat = nc_put_att_text(ncid, ilev_id, "formula_terms", 29, "a: hyai b: hybi p0: P0 ps: PS");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, isccp_prs_id, "long_name", 19, "Mean ISCCP pressure");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, isccp_prs_id, "units", 2, "mb");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* isccp_prs_bnds */
    static const double isccp_prs_isccp_prs_bnds_att[8] = {0, 180, 310, 440, 560, 680, 800, 1000} ;
    stat = nc_put_att_double(ncid, isccp_prs_id, "isccp_prs_bnds", NC_DOUBLE, 8, isccp_prs_isccp_prs_bnds_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, isccp_tau_id, "long_name", 24, "Mean ISCCP optical depth");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, isccp_tau_id, "units", 8, "unitless");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* isccp_tau_bnds */
    static const double isccp_tau_isccp_tau_bnds_att[8] = {0, 0.3, 1.3, 3.6, 9.4, 23, 60, 379} ;
    stat = nc_put_att_double(ncid, isccp_tau_id, "isccp_tau_bnds", NC_DOUBLE, 8, isccp_tau_isccp_tau_bnds_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, isccp_prstau_id, "long_name", 53, "Mean pressure (mb).mean optical depth (unitless)/1000");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, isccp_prstau_id, "units", 5, "mixed");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, time_id, "long_name", 4, "time");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, time_id, "units", 30, "days since 0000-01-01 00:00:00");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* calendar */
    stat = nc_put_att_text(ncid, time_id, "calendar", 6, "noleap");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* bounds */
    stat = nc_put_att_text(ncid, time_id, "bounds", 9, "time_bnds");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, time_bnds_id, "long_name", 23, "time interval endpoints");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, ntrm_id, "long_name", 31, "spectral truncation parameter M");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, ntrn_id, "long_name", 31, "spectral truncation parameter N");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, ntrk_id, "long_name", 31, "spectral truncation parameter K");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, ndbase_id, "long_name", 8, "base day");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, nsbase_id, "long_name", 19, "seconds of base day");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, nbdate_id, "long_name", 20, "base date (YYYYMMDD)");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, nbsec_id, "long_name", 20, "seconds of base date");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, mdt_id, "long_name", 8, "timestep");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, mdt_id, "units", 1, "s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, nlon_id, "long_name", 20, "number of longitudes");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, wnummax_id, "long_name", 25, "cutoff Fourier wavenumber");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, hyai_id, "long_name", 40, "hybrid A coefficient at layer interfaces");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, hybi_id, "long_name", 40, "hybrid B coefficient at layer interfaces");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, hyam_id, "long_name", 39, "hybrid A coefficient at layer midpoints");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, hybm_id, "long_name", 39, "hybrid B coefficient at layer midpoints");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, gw_id, "long_name", 13, "gauss weights");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, ndcur_id, "long_name", 27, "current day (from base day)");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, nscur_id, "long_name", 30, "current seconds of current day");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, date_id, "long_name", 23, "current date (YYYYMMDD)");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, co2vmr_id, "long_name", 23, "co2 volume mixing ratio");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, ch4vmr_id, "long_name", 23, "ch4 volume mixing ratio");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, n2ovmr_id, "long_name", 23, "n2o volume mixing ratio");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, f11vmr_id, "long_name", 23, "f11 volume mixing ratio");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, f12vmr_id, "long_name", 23, "f12 volume mixing ratio");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, sol_tsi_id, "long_name", 22, "total solar irradiance");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, sol_tsi_id, "units", 4, "W/m2");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, datesec_id, "long_name", 31, "current seconds of current date");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, nsteph_id, "long_name", 16, "current timestep");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _FillValue */
    static const double ABSORB_FillValue_att[1] = {1e+36} ;
    stat = nc_put_att_double(ncid, ABSORB_id, "_FillValue", NC_DOUBLE, 1, ABSORB_FillValue_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* missing_value */
    static const double ABSORB_missing_value_att[1] = {1e+36} ;
    stat = nc_put_att_double(ncid, ABSORB_id, "missing_value", NC_DOUBLE, 1, ABSORB_missing_value_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, ABSORB_id, "units", 2, "/m");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, ABSORB_id, "long_name", 18, "Aerosol absorption");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, ABSORB_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _FillValue */
    static const double AEROD_v_FillValue_att[1] = {1e+36} ;
    stat = nc_put_att_double(ncid, AEROD_v_id, "_FillValue", NC_DOUBLE, 1, AEROD_v_FillValue_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* missing_value */
    static const double AEROD_v_missing_value_att[1] = {1e+36} ;
    stat = nc_put_att_double(ncid, AEROD_v_id, "missing_value", NC_DOUBLE, 1, AEROD_v_missing_value_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, AEROD_v_id, "units", 1, "1");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, AEROD_v_id, "long_name", 43, "Total Aerosol Optical Depth in visible band");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, AEROD_v_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _FillValue */
    static const double AODABS_FillValue_att[1] = {1e+36} ;
    stat = nc_put_att_double(ncid, AODABS_id, "_FillValue", NC_DOUBLE, 1, AODABS_FillValue_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* missing_value */
    static const double AODABS_missing_value_att[1] = {1e+36} ;
    stat = nc_put_att_double(ncid, AODABS_id, "missing_value", NC_DOUBLE, 1, AODABS_missing_value_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, AODABS_id, "units", 1, "\000");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, AODABS_id, "long_name", 39, "Aerosol absorption optical depth 550 nm");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, AODABS_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _FillValue */
    static const double AODDUST1_FillValue_att[1] = {1e+36} ;
    stat = nc_put_att_double(ncid, AODDUST1_id, "_FillValue", NC_DOUBLE, 1, AODDUST1_FillValue_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* missing_value */
    static const double AODDUST1_missing_value_att[1] = {1e+36} ;
    stat = nc_put_att_double(ncid, AODDUST1_id, "missing_value", NC_DOUBLE, 1, AODDUST1_missing_value_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, AODDUST1_id, "units", 1, "\000");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, AODDUST1_id, "long_name", 46, "Aerosol optical depth 550 nm model 1 from dust");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, AODDUST1_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _FillValue */
    static const double AODDUST2_FillValue_att[1] = {1e+36} ;
    stat = nc_put_att_double(ncid, AODDUST2_id, "_FillValue", NC_DOUBLE, 1, AODDUST2_FillValue_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* missing_value */
    static const double AODDUST2_missing_value_att[1] = {1e+36} ;
    stat = nc_put_att_double(ncid, AODDUST2_id, "missing_value", NC_DOUBLE, 1, AODDUST2_missing_value_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, AODDUST2_id, "units", 1, "\000");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, AODDUST2_id, "long_name", 46, "Aerosol optical depth 550 nm model 2 from dust");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, AODDUST2_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _FillValue */
    static const double AODDUST3_FillValue_att[1] = {1e+36} ;
    stat = nc_put_att_double(ncid, AODDUST3_id, "_FillValue", NC_DOUBLE, 1, AODDUST3_FillValue_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* missing_value */
    static const double AODDUST3_missing_value_att[1] = {1e+36} ;
    stat = nc_put_att_double(ncid, AODDUST3_id, "missing_value", NC_DOUBLE, 1, AODDUST3_missing_value_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, AODDUST3_id, "units", 1, "\000");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, AODDUST3_id, "long_name", 46, "Aerosol optical depth 550 nm model 3 from dust");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, AODDUST3_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _FillValue */
    static const double AODMODE1_FillValue_att[1] = {1e+36} ;
    stat = nc_put_att_double(ncid, AODMODE1_id, "_FillValue", NC_DOUBLE, 1, AODMODE1_FillValue_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* missing_value */
    static const double AODMODE1_missing_value_att[1] = {1e+36} ;
    stat = nc_put_att_double(ncid, AODMODE1_id, "missing_value", NC_DOUBLE, 1, AODMODE1_missing_value_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, AODMODE1_id, "units", 1, "\000");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, AODMODE1_id, "long_name", 35, "Aerosol optical depth 550 nm mode 1");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, AODMODE1_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _FillValue */
    static const double AODMODE2_FillValue_att[1] = {1e+36} ;
    stat = nc_put_att_double(ncid, AODMODE2_id, "_FillValue", NC_DOUBLE, 1, AODMODE2_FillValue_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* missing_value */
    static const double AODMODE2_missing_value_att[1] = {1e+36} ;
    stat = nc_put_att_double(ncid, AODMODE2_id, "missing_value", NC_DOUBLE, 1, AODMODE2_missing_value_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, AODMODE2_id, "units", 1, "\000");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, AODMODE2_id, "long_name", 35, "Aerosol optical depth 550 nm mode 2");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, AODMODE2_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _FillValue */
    static const double AODMODE3_FillValue_att[1] = {1e+36} ;
    stat = nc_put_att_double(ncid, AODMODE3_id, "_FillValue", NC_DOUBLE, 1, AODMODE3_FillValue_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* missing_value */
    static const double AODMODE3_missing_value_att[1] = {1e+36} ;
    stat = nc_put_att_double(ncid, AODMODE3_id, "missing_value", NC_DOUBLE, 1, AODMODE3_missing_value_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, AODMODE3_id, "units", 1, "\000");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, AODMODE3_id, "long_name", 35, "Aerosol optical depth 550 nm mode 3");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, AODMODE3_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _FillValue */
    static const double AODVIS_FillValue_att[1] = {1e+36} ;
    stat = nc_put_att_double(ncid, AODVIS_id, "_FillValue", NC_DOUBLE, 1, AODVIS_FillValue_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* missing_value */
    static const double AODVIS_missing_value_att[1] = {1e+36} ;
    stat = nc_put_att_double(ncid, AODVIS_id, "missing_value", NC_DOUBLE, 1, AODVIS_missing_value_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, AODVIS_id, "units", 1, "\000");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, AODVIS_id, "long_name", 28, "Aerosol optical depth 550 nm");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, AODVIS_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, AQSO4_H2O2_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, AQSO4_H2O2_id, "long_name", 39, "SO4 aqueous phase chemistry due to H2O2");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, AQSO4_H2O2_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, AQSO4_O3_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, AQSO4_O3_id, "long_name", 37, "SO4 aqueous phase chemistry due to O3");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, AQSO4_O3_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, AQ_DMS_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, AQ_DMS_id, "long_name", 39, "DMS aqueous chemistry (for gas species)");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, AQ_DMS_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, AQ_H2O2_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, AQ_H2O2_id, "long_name", 40, "H2O2 aqueous chemistry (for gas species)");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, AQ_H2O2_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, AQ_H2SO4_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, AQ_H2SO4_id, "long_name", 41, "H2SO4 aqueous chemistry (for gas species)");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, AQ_H2SO4_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, AQ_SO2_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, AQ_SO2_id, "long_name", 39, "SO2 aqueous chemistry (for gas species)");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, AQ_SO2_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, AQ_SOAG_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, AQ_SOAG_id, "long_name", 40, "SOAG aqueous chemistry (for gas species)");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, AQ_SOAG_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, AQ_bc_a1_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, AQ_bc_a1_id, "long_name", 41, "bc_a1 aqueous chemistry (for gas species)");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, AQ_bc_a1_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, AQ_dst_a1_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, AQ_dst_a1_id, "long_name", 42, "dst_a1 aqueous chemistry (for gas species)");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, AQ_dst_a1_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, AQ_dst_a3_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, AQ_dst_a3_id, "long_name", 42, "dst_a3 aqueous chemistry (for gas species)");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, AQ_dst_a3_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, AQ_ncl_a1_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, AQ_ncl_a1_id, "long_name", 42, "ncl_a1 aqueous chemistry (for gas species)");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, AQ_ncl_a1_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, AQ_ncl_a2_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, AQ_ncl_a2_id, "long_name", 42, "ncl_a2 aqueous chemistry (for gas species)");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, AQ_ncl_a2_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, AQ_ncl_a3_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, AQ_ncl_a3_id, "long_name", 42, "ncl_a3 aqueous chemistry (for gas species)");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, AQ_ncl_a3_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, AQ_num_a1_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, AQ_num_a1_id, "long_name", 42, "num_a1 aqueous chemistry (for gas species)");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, AQ_num_a1_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, AQ_num_a2_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, AQ_num_a2_id, "long_name", 42, "num_a2 aqueous chemistry (for gas species)");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, AQ_num_a2_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, AQ_num_a3_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, AQ_num_a3_id, "long_name", 42, "num_a3 aqueous chemistry (for gas species)");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, AQ_num_a3_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, AQ_pom_a1_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, AQ_pom_a1_id, "long_name", 42, "pom_a1 aqueous chemistry (for gas species)");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, AQ_pom_a1_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, AQ_so4_a1_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, AQ_so4_a1_id, "long_name", 42, "so4_a1 aqueous chemistry (for gas species)");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, AQ_so4_a1_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, AQ_so4_a2_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, AQ_so4_a2_id, "long_name", 42, "so4_a2 aqueous chemistry (for gas species)");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, AQ_so4_a2_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, AQ_so4_a3_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, AQ_so4_a3_id, "long_name", 42, "so4_a3 aqueous chemistry (for gas species)");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, AQ_so4_a3_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, AQ_soa_a1_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, AQ_soa_a1_id, "long_name", 42, "soa_a1 aqueous chemistry (for gas species)");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, AQ_soa_a1_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, AQ_soa_a2_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, AQ_soa_a2_id, "long_name", 42, "soa_a2 aqueous chemistry (for gas species)");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, AQ_soa_a2_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, BPROD_id, "units", 5, "M2/S3");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, BPROD_id, "long_name", 19, "Buoyancy Production");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, BPROD_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _FillValue */
    static const double BURDEN1_FillValue_att[1] = {1e+36} ;
    stat = nc_put_att_double(ncid, BURDEN1_id, "_FillValue", NC_DOUBLE, 1, BURDEN1_FillValue_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* missing_value */
    static const double BURDEN1_missing_value_att[1] = {1e+36} ;
    stat = nc_put_att_double(ncid, BURDEN1_id, "missing_value", NC_DOUBLE, 1, BURDEN1_missing_value_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, BURDEN1_id, "units", 5, "kg/m2");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, BURDEN1_id, "long_name", 21, "Aerosol burden mode 1");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, BURDEN1_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _FillValue */
    static const double BURDEN2_FillValue_att[1] = {1e+36} ;
    stat = nc_put_att_double(ncid, BURDEN2_id, "_FillValue", NC_DOUBLE, 1, BURDEN2_FillValue_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* missing_value */
    static const double BURDEN2_missing_value_att[1] = {1e+36} ;
    stat = nc_put_att_double(ncid, BURDEN2_id, "missing_value", NC_DOUBLE, 1, BURDEN2_missing_value_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, BURDEN2_id, "units", 5, "kg/m2");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, BURDEN2_id, "long_name", 21, "Aerosol burden mode 2");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, BURDEN2_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _FillValue */
    static const double BURDEN3_FillValue_att[1] = {1e+36} ;
    stat = nc_put_att_double(ncid, BURDEN3_id, "_FillValue", NC_DOUBLE, 1, BURDEN3_FillValue_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* missing_value */
    static const double BURDEN3_missing_value_att[1] = {1e+36} ;
    stat = nc_put_att_double(ncid, BURDEN3_id, "missing_value", NC_DOUBLE, 1, BURDEN3_missing_value_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, BURDEN3_id, "units", 5, "kg/m2");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, BURDEN3_id, "long_name", 21, "Aerosol burden mode 3");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, BURDEN3_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, CCN1_id, "units", 5, "#/cm3");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, CCN1_id, "long_name", 28, "CCN concentration at S=0.02%");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, CCN1_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, CCN2_id, "units", 5, "#/cm3");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, CCN2_id, "long_name", 28, "CCN concentration at S=0.05%");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, CCN2_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, CCN3_id, "units", 5, "#/cm3");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, CCN3_id, "long_name", 27, "CCN concentration at S=0.1%");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, CCN3_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, CCN4_id, "units", 5, "#/cm3");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, CCN4_id, "long_name", 27, "CCN concentration at S=0.2%");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, CCN4_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, CCN5_id, "units", 5, "#/cm3");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, CCN5_id, "long_name", 27, "CCN concentration at S=0.5%");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, CCN5_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, CCN6_id, "units", 5, "#/cm3");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, CCN6_id, "long_name", 27, "CCN concentration at S=1.0%");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, CCN6_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, CLDHGH_id, "units", 8, "fraction");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, CLDHGH_id, "long_name", 32, "Vertically-integrated high cloud");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, CLDHGH_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, CLDICE_id, "units", 5, "kg/kg");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, CLDICE_id, "long_name", 34, "Grid box averaged cloud ice amount");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, CLDICE_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, CLDLIQ_id, "units", 5, "kg/kg");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, CLDLIQ_id, "long_name", 37, "Grid box averaged cloud liquid amount");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, CLDLIQ_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, CLDLOW_id, "units", 8, "fraction");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, CLDLOW_id, "long_name", 31, "Vertically-integrated low cloud");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, CLDLOW_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, CLDMED_id, "units", 8, "fraction");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, CLDMED_id, "long_name", 37, "Vertically-integrated mid-level cloud");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, CLDMED_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, CLDTOT_id, "units", 8, "fraction");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, CLDTOT_id, "long_name", 33, "Vertically-integrated total cloud");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, CLDTOT_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, CLOUD_id, "units", 8, "fraction");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, CLOUD_id, "long_name", 14, "Cloud fraction");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, CLOUD_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, CMFDQ_id, "units", 7, "kg/kg/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, CMFDQ_id, "long_name", 32, "QV tendency - shallow convection");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, CMFDQ_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, CMFDQR_id, "units", 7, "kg/kg/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, CMFDQR_id, "long_name", 39, "Q tendency - shallow convection rainout");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, CMFDQR_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, CMFDT_id, "units", 3, "K/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, CMFDT_id, "long_name", 31, "T tendency - shallow convection");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, CMFDT_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, CMFMC_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, CMFMC_id, "long_name", 34, "Moist shallow convection mass flux");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, CMFMC_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, CMFMCDZM_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, CMFMCDZM_id, "long_name", 33, "Convection mass flux from ZM deep");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, CMFMCDZM_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, CONCLD_id, "units", 8, "fraction");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, CONCLD_id, "long_name", 22, "Convective cloud cover");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, CONCLD_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, DCQ_id, "units", 7, "kg/kg/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, DCQ_id, "long_name", 33, "Q tendency due to moist processes");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, DCQ_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, DMS_id, "units", 5, "kg/kg");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, DMS_id, "long_name", 3, "DMS");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, DMS_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, DSTODXC_id, "units", 3, "Tau");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, DSTODXC_id, "long_name", 29, "Optical depth for diagnostics");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, DSTODXC_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, DSTSFDRY_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, DSTSFDRY_id, "long_name", 30, "Dry deposition flux at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, DSTSFDRY_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, DSTSFMBL_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, DSTSFMBL_id, "long_name", 28, "Mobilization flux at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, DSTSFMBL_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, DSTSFWET_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, DSTSFWET_id, "long_name", 30, "Wet deposition flux at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, DSTSFWET_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, DTCOND_id, "units", 3, "K/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, DTCOND_id, "long_name", 28, "T tendency - moist processes");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, DTCOND_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, DTV_id, "units", 3, "K/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, DTV_id, "long_name", 20, "T vertical diffusion");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, DTV_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _FillValue */
    static const double EXTINCT_FillValue_att[1] = {1e+36} ;
    stat = nc_put_att_double(ncid, EXTINCT_id, "_FillValue", NC_DOUBLE, 1, EXTINCT_FillValue_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* missing_value */
    static const double EXTINCT_missing_value_att[1] = {1e+36} ;
    stat = nc_put_att_double(ncid, EXTINCT_id, "missing_value", NC_DOUBLE, 1, EXTINCT_missing_value_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, EXTINCT_id, "units", 2, "/m");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, EXTINCT_id, "long_name", 18, "Aerosol extinction");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, EXTINCT_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, FICE_id, "units", 8, "fraction");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, FICE_id, "long_name", 35, "Fractional ice content within cloud");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, FICE_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* Sampling_Sequence */
    stat = nc_put_att_text(ncid, FLDS_id, "Sampling_Sequence", 8, "rad_lwsw");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, FLDS_id, "units", 4, "W/m2");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, FLDS_id, "long_name", 36, "Downwelling longwave flux at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, FLDS_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* Sampling_Sequence */
    stat = nc_put_att_text(ncid, FLNS_id, "Sampling_Sequence", 8, "rad_lwsw");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, FLNS_id, "units", 4, "W/m2");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, FLNS_id, "long_name", 28, "Net longwave flux at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, FLNS_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* Sampling_Sequence */
    stat = nc_put_att_text(ncid, FLNSC_id, "Sampling_Sequence", 8, "rad_lwsw");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, FLNSC_id, "units", 4, "W/m2");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, FLNSC_id, "long_name", 37, "Clearsky net longwave flux at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, FLNSC_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* Sampling_Sequence */
    stat = nc_put_att_text(ncid, FLNT_id, "Sampling_Sequence", 8, "rad_lwsw");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, FLNT_id, "units", 4, "W/m2");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, FLNT_id, "long_name", 33, "Net longwave flux at top of model");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, FLNT_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* Sampling_Sequence */
    stat = nc_put_att_text(ncid, FLNTC_id, "Sampling_Sequence", 8, "rad_lwsw");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, FLNTC_id, "units", 4, "W/m2");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, FLNTC_id, "long_name", 42, "Clearsky net longwave flux at top of model");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, FLNTC_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* Sampling_Sequence */
    stat = nc_put_att_text(ncid, FLUT_id, "Sampling_Sequence", 8, "rad_lwsw");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, FLUT_id, "units", 4, "W/m2");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, FLUT_id, "long_name", 39, "Upwelling longwave flux at top of model");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, FLUT_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* Sampling_Sequence */
    stat = nc_put_att_text(ncid, FLUTC_id, "Sampling_Sequence", 8, "rad_lwsw");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, FLUTC_id, "units", 4, "W/m2");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, FLUTC_id, "long_name", 48, "Clearsky upwelling longwave flux at top of model");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, FLUTC_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, FREQSH_id, "units", 8, "fraction");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, FREQSH_id, "long_name", 42, "Fractional occurance of shallow convection");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, FREQSH_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, FREQZM_id, "units", 8, "fraction");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, FREQZM_id, "long_name", 37, "Fractional occurance of ZM convection");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, FREQZM_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* Sampling_Sequence */
    stat = nc_put_att_text(ncid, FSDS_id, "Sampling_Sequence", 8, "rad_lwsw");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, FSDS_id, "units", 4, "W/m2");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, FSDS_id, "long_name", 33, "Downwelling solar flux at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, FSDS_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* Sampling_Sequence */
    stat = nc_put_att_text(ncid, FSDSC_id, "Sampling_Sequence", 8, "rad_lwsw");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, FSDSC_id, "units", 4, "W/m2");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, FSDSC_id, "long_name", 42, "Clearsky downwelling solar flux at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, FSDSC_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* Sampling_Sequence */
    stat = nc_put_att_text(ncid, FSNS_id, "Sampling_Sequence", 8, "rad_lwsw");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, FSNS_id, "units", 4, "W/m2");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, FSNS_id, "long_name", 25, "Net solar flux at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, FSNS_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* Sampling_Sequence */
    stat = nc_put_att_text(ncid, FSNSC_id, "Sampling_Sequence", 8, "rad_lwsw");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, FSNSC_id, "units", 4, "W/m2");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, FSNSC_id, "long_name", 34, "Clearsky net solar flux at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, FSNSC_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* Sampling_Sequence */
    stat = nc_put_att_text(ncid, FSNT_id, "Sampling_Sequence", 8, "rad_lwsw");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, FSNT_id, "units", 4, "W/m2");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, FSNT_id, "long_name", 30, "Net solar flux at top of model");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, FSNT_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* Sampling_Sequence */
    stat = nc_put_att_text(ncid, FSNTC_id, "Sampling_Sequence", 8, "rad_lwsw");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, FSNTC_id, "units", 4, "W/m2");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, FSNTC_id, "long_name", 39, "Clearsky net solar flux at top of model");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, FSNTC_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* Sampling_Sequence */
    stat = nc_put_att_text(ncid, FSNTOA_id, "Sampling_Sequence", 8, "rad_lwsw");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, FSNTOA_id, "units", 4, "W/m2");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, FSNTOA_id, "long_name", 35, "Net solar flux at top of atmosphere");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, FSNTOA_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* Sampling_Sequence */
    stat = nc_put_att_text(ncid, FSNTOAC_id, "Sampling_Sequence", 8, "rad_lwsw");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, FSNTOAC_id, "units", 4, "W/m2");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, FSNTOAC_id, "long_name", 44, "Clearsky net solar flux at top of atmosphere");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, FSNTOAC_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* Sampling_Sequence */
    stat = nc_put_att_text(ncid, FSUTOA_id, "Sampling_Sequence", 8, "rad_lwsw");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, FSUTOA_id, "units", 4, "W/m2");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, FSUTOA_id, "long_name", 41, "Upwelling solar flux at top of atmosphere");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, FSUTOA_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, GS_DMS_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, GS_DMS_id, "long_name", 47, "DMS gas chemistry/wet removal (for gas species)");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, GS_DMS_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, GS_H2O2_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, GS_H2O2_id, "long_name", 48, "H2O2 gas chemistry/wet removal (for gas species)");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, GS_H2O2_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, GS_H2SO4_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, GS_H2SO4_id, "long_name", 49, "H2SO4 gas chemistry/wet removal (for gas species)");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, GS_H2SO4_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, GS_SO2_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, GS_SO2_id, "long_name", 47, "SO2 gas chemistry/wet removal (for gas species)");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, GS_SO2_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, GS_SOAG_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, GS_SOAG_id, "long_name", 48, "SOAG gas chemistry/wet removal (for gas species)");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, GS_SOAG_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, GS_bc_a1_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, GS_bc_a1_id, "long_name", 49, "bc_a1 gas chemistry/wet removal (for gas species)");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, GS_bc_a1_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, GS_dst_a1_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, GS_dst_a1_id, "long_name", 50, "dst_a1 gas chemistry/wet removal (for gas species)");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, GS_dst_a1_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, GS_dst_a3_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, GS_dst_a3_id, "long_name", 50, "dst_a3 gas chemistry/wet removal (for gas species)");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, GS_dst_a3_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, GS_ncl_a1_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, GS_ncl_a1_id, "long_name", 50, "ncl_a1 gas chemistry/wet removal (for gas species)");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, GS_ncl_a1_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, GS_ncl_a2_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, GS_ncl_a2_id, "long_name", 50, "ncl_a2 gas chemistry/wet removal (for gas species)");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, GS_ncl_a2_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, GS_ncl_a3_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, GS_ncl_a3_id, "long_name", 50, "ncl_a3 gas chemistry/wet removal (for gas species)");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, GS_ncl_a3_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, GS_num_a1_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, GS_num_a1_id, "long_name", 50, "num_a1 gas chemistry/wet removal (for gas species)");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, GS_num_a1_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, GS_num_a2_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, GS_num_a2_id, "long_name", 50, "num_a2 gas chemistry/wet removal (for gas species)");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, GS_num_a2_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, GS_num_a3_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, GS_num_a3_id, "long_name", 50, "num_a3 gas chemistry/wet removal (for gas species)");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, GS_num_a3_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, GS_pom_a1_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, GS_pom_a1_id, "long_name", 50, "pom_a1 gas chemistry/wet removal (for gas species)");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, GS_pom_a1_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, GS_so4_a1_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, GS_so4_a1_id, "long_name", 50, "so4_a1 gas chemistry/wet removal (for gas species)");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, GS_so4_a1_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, GS_so4_a2_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, GS_so4_a2_id, "long_name", 50, "so4_a2 gas chemistry/wet removal (for gas species)");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, GS_so4_a2_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, GS_so4_a3_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, GS_so4_a3_id, "long_name", 50, "so4_a3 gas chemistry/wet removal (for gas species)");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, GS_so4_a3_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, GS_soa_a1_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, GS_soa_a1_id, "long_name", 50, "soa_a1 gas chemistry/wet removal (for gas species)");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, GS_soa_a1_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, GS_soa_a2_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, GS_soa_a2_id, "long_name", 50, "soa_a2 gas chemistry/wet removal (for gas species)");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, GS_soa_a2_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, H2O2_id, "units", 5, "kg/kg");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, H2O2_id, "long_name", 4, "H2O2");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, H2O2_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, H2SO4_id, "units", 5, "kg/kg");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, H2SO4_id, "long_name", 5, "H2SO4");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, H2SO4_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, H2SO4_sfgaex1_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, H2SO4_sfgaex1_id, "long_name", 50, "H2SO4 gas-aerosol-exchange primary column tendency");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, H2SO4_sfgaex1_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, H2SO4_sfnnuc1_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, H2SO4_sfnnuc1_id, "long_name", 56, "H2SO4 modal_aero new particle nucleation column tendency");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, H2SO4_sfnnuc1_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, ICEFRAC_id, "units", 8, "fraction");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, ICEFRAC_id, "long_name", 39, "Fraction of sfc area covered by sea-ice");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, ICEFRAC_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, ICIMR_id, "units", 5, "kg/kg");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, ICIMR_id, "long_name", 36, "Prognostic in-cloud ice mixing ratio");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, ICIMR_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, ICWMR_id, "units", 5, "kg/kg");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, ICWMR_id, "long_name", 38, "Prognostic in-cloud water mixing ratio");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, ICWMR_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, KVH_id, "units", 4, "m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, KVH_id, "long_name", 48, "Vertical diffusion diffusivities (heat/moisture)");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, KVH_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, KVM_id, "units", 4, "m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, KVM_id, "long_name", 43, "Vertical diffusion diffusivities (momentum)");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, KVM_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, LANDFRAC_id, "units", 8, "fraction");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, LANDFRAC_id, "long_name", 36, "Fraction of sfc area covered by land");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, LANDFRAC_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, LCLOUD_id, "units", 1, "\000");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, LCLOUD_id, "long_name", 21, "Liquid cloud fraction");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, LCLOUD_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, LHFLX_id, "units", 4, "W/m2");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, LHFLX_id, "long_name", 24, "Surface latent heat flux");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, LHFLX_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, LND_MBL_id, "units", 4, "frac");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, LND_MBL_id, "long_name", 23, "Soil erodibility factor");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, LND_MBL_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* Sampling_Sequence */
    stat = nc_put_att_text(ncid, LWCF_id, "Sampling_Sequence", 8, "rad_lwsw");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, LWCF_id, "units", 4, "W/m2");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, LWCF_id, "long_name", 22, "Longwave cloud forcing");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, LWCF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, NDROPCOL_id, "units", 4, "#/m2");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, NDROPCOL_id, "long_name", 21, "Column droplet number");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, NDROPCOL_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, NDROPMIX_id, "units", 6, "#/kg/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, NDROPMIX_id, "long_name", 21, "Droplet number mixing");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, NDROPMIX_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, NDROPSNK_id, "units", 6, "#/kg/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, NDROPSNK_id, "long_name", 35, "Droplet number loss by microphysics");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, NDROPSNK_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, NDROPSRC_id, "units", 6, "#/kg/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, NDROPSRC_id, "long_name", 21, "Droplet number source");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, NDROPSRC_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, NUMICE_id, "units", 5, "kg/kg");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, NUMICE_id, "long_name", 34, "Grid box averaged cloud ice number");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, NUMICE_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, NUMLIQ_id, "units", 5, "kg/kg");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, NUMLIQ_id, "long_name", 37, "Grid box averaged cloud liquid number");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, NUMLIQ_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, OCNFRAC_id, "units", 8, "fraction");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, OCNFRAC_id, "long_name", 37, "Fraction of sfc area covered by ocean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, OCNFRAC_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _FillValue */
    static const double ODV_bc_a1_FillValue_att[1] = {1e+36} ;
    stat = nc_put_att_double(ncid, ODV_bc_a1_id, "_FillValue", NC_DOUBLE, 1, ODV_bc_a1_FillValue_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* missing_value */
    static const double ODV_bc_a1_missing_value_att[1] = {1e+36} ;
    stat = nc_put_att_double(ncid, ODV_bc_a1_id, "missing_value", NC_DOUBLE, 1, ODV_bc_a1_missing_value_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, ODV_bc_a1_id, "units", 1, "1");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, ODV_bc_a1_id, "long_name", 35, "bc_a1 optical depth in visible band");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, ODV_bc_a1_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _FillValue */
    static const double ODV_dst_a1_FillValue_att[1] = {1e+36} ;
    stat = nc_put_att_double(ncid, ODV_dst_a1_id, "_FillValue", NC_DOUBLE, 1, ODV_dst_a1_FillValue_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* missing_value */
    static const double ODV_dst_a1_missing_value_att[1] = {1e+36} ;
    stat = nc_put_att_double(ncid, ODV_dst_a1_id, "missing_value", NC_DOUBLE, 1, ODV_dst_a1_missing_value_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, ODV_dst_a1_id, "units", 1, "1");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, ODV_dst_a1_id, "long_name", 36, "dst_a1 optical depth in visible band");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, ODV_dst_a1_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _FillValue */
    static const double ODV_dst_a3_FillValue_att[1] = {1e+36} ;
    stat = nc_put_att_double(ncid, ODV_dst_a3_id, "_FillValue", NC_DOUBLE, 1, ODV_dst_a3_FillValue_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* missing_value */
    static const double ODV_dst_a3_missing_value_att[1] = {1e+36} ;
    stat = nc_put_att_double(ncid, ODV_dst_a3_id, "missing_value", NC_DOUBLE, 1, ODV_dst_a3_missing_value_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, ODV_dst_a3_id, "units", 1, "1");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, ODV_dst_a3_id, "long_name", 36, "dst_a3 optical depth in visible band");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, ODV_dst_a3_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _FillValue */
    static const double ODV_ncl_a1_FillValue_att[1] = {1e+36} ;
    stat = nc_put_att_double(ncid, ODV_ncl_a1_id, "_FillValue", NC_DOUBLE, 1, ODV_ncl_a1_FillValue_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* missing_value */
    static const double ODV_ncl_a1_missing_value_att[1] = {1e+36} ;
    stat = nc_put_att_double(ncid, ODV_ncl_a1_id, "missing_value", NC_DOUBLE, 1, ODV_ncl_a1_missing_value_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, ODV_ncl_a1_id, "units", 1, "1");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, ODV_ncl_a1_id, "long_name", 36, "ncl_a1 optical depth in visible band");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, ODV_ncl_a1_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _FillValue */
    static const double ODV_ncl_a3_FillValue_att[1] = {1e+36} ;
    stat = nc_put_att_double(ncid, ODV_ncl_a3_id, "_FillValue", NC_DOUBLE, 1, ODV_ncl_a3_FillValue_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* missing_value */
    static const double ODV_ncl_a3_missing_value_att[1] = {1e+36} ;
    stat = nc_put_att_double(ncid, ODV_ncl_a3_id, "missing_value", NC_DOUBLE, 1, ODV_ncl_a3_missing_value_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, ODV_ncl_a3_id, "units", 1, "1");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, ODV_ncl_a3_id, "long_name", 36, "ncl_a3 optical depth in visible band");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, ODV_ncl_a3_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _FillValue */
    static const double ODV_pom_a1_FillValue_att[1] = {1e+36} ;
    stat = nc_put_att_double(ncid, ODV_pom_a1_id, "_FillValue", NC_DOUBLE, 1, ODV_pom_a1_FillValue_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* missing_value */
    static const double ODV_pom_a1_missing_value_att[1] = {1e+36} ;
    stat = nc_put_att_double(ncid, ODV_pom_a1_id, "missing_value", NC_DOUBLE, 1, ODV_pom_a1_missing_value_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, ODV_pom_a1_id, "units", 1, "1");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, ODV_pom_a1_id, "long_name", 36, "pom_a1 optical depth in visible band");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, ODV_pom_a1_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _FillValue */
    static const double ODV_so4_a1_FillValue_att[1] = {1e+36} ;
    stat = nc_put_att_double(ncid, ODV_so4_a1_id, "_FillValue", NC_DOUBLE, 1, ODV_so4_a1_FillValue_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* missing_value */
    static const double ODV_so4_a1_missing_value_att[1] = {1e+36} ;
    stat = nc_put_att_double(ncid, ODV_so4_a1_id, "missing_value", NC_DOUBLE, 1, ODV_so4_a1_missing_value_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, ODV_so4_a1_id, "units", 1, "1");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, ODV_so4_a1_id, "long_name", 36, "so4_a1 optical depth in visible band");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, ODV_so4_a1_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _FillValue */
    static const double ODV_soa_a1_FillValue_att[1] = {1e+36} ;
    stat = nc_put_att_double(ncid, ODV_soa_a1_id, "_FillValue", NC_DOUBLE, 1, ODV_soa_a1_FillValue_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* missing_value */
    static const double ODV_soa_a1_missing_value_att[1] = {1e+36} ;
    stat = nc_put_att_double(ncid, ODV_soa_a1_id, "missing_value", NC_DOUBLE, 1, ODV_soa_a1_missing_value_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, ODV_soa_a1_id, "units", 1, "1");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, ODV_soa_a1_id, "long_name", 36, "soa_a1 optical depth in visible band");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, ODV_soa_a1_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, OMEGA_id, "units", 4, "Pa/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, OMEGA_id, "long_name", 28, "Vertical velocity (pressure)");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, OMEGA_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, OMEGAT_id, "units", 6, "K Pa/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, OMEGAT_id, "long_name", 18, "Vertical heat flux");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, OMEGAT_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, ORO_id, "units", 4, "frac");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, ORO_id, "long_name", 3, "ORO");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, ORO_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, PBLH_id, "units", 1, "m");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, PBLH_id, "long_name", 10, "PBL height");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, PBLH_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, PCONVB_id, "units", 2, "Pa");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, PCONVB_id, "long_name", 24, "convection base pressure");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, PCONVB_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, PCONVT_id, "units", 2, "Pa");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, PCONVT_id, "long_name", 24, "convection top  pressure");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, PCONVT_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, PHIS_id, "units", 5, "m2/s2");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, PHIS_id, "long_name", 20, "Surface geopotential");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, PRECC_id, "units", 3, "m/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, PRECC_id, "long_name", 41, "Convective precipitation rate (liq + ice)");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, PRECC_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, PRECCDZM_id, "units", 3, "m/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, PRECCDZM_id, "long_name", 42, "Convective precipitation rate from ZM deep");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, PRECCDZM_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, PRECL_id, "units", 3, "m/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, PRECL_id, "long_name", 51, "Large-scale (stable) precipitation rate (liq + ice)");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, PRECL_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, PRECSC_id, "units", 3, "m/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, PRECSC_id, "long_name", 39, "Convective snow rate (water equivalent)");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, PRECSC_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, PRECSH_id, "units", 3, "m/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, PRECSH_id, "long_name", 37, "Shallow Convection precipitation rate");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, PRECSH_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, PRECSL_id, "units", 3, "m/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, PRECSL_id, "long_name", 49, "Large-scale (stable) snow rate (water equivalent)");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, PRECSL_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, PRECT_id, "units", 3, "m/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, PRECT_id, "long_name", 65, "Total (convective and large-scale) precipitation rate (liq + ice)");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, PRECT_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, PS_id, "units", 2, "Pa");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, PS_id, "long_name", 16, "Surface pressure");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, PS_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, PSL_id, "units", 2, "Pa");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, PSL_id, "long_name", 18, "Sea level pressure");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, PSL_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, Q_id, "units", 5, "kg/kg");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, Q_id, "long_name", 17, "Specific humidity");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, Q_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, QC_id, "units", 7, "kg/kg/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, QC_id, "long_name", 41, "Q tendency - shallow convection LW export");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, QC_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, QFLX_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, QFLX_id, "long_name", 18, "Surface water flux");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, QFLX_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, QREFHT_id, "units", 5, "kg/kg");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, QREFHT_id, "long_name", 25, "Reference height humidity");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, QREFHT_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* Sampling_Sequence */
    stat = nc_put_att_text(ncid, QRL_id, "Sampling_Sequence", 8, "rad_lwsw");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, QRL_id, "units", 3, "K/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, QRL_id, "long_name", 21, "Longwave heating rate");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, QRL_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* Sampling_Sequence */
    stat = nc_put_att_text(ncid, QRS_id, "Sampling_Sequence", 8, "rad_lwsw");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, QRS_id, "units", 3, "K/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, QRS_id, "long_name", 18, "Solar heating rate");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, QRS_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, QT_id, "units", 5, "kg/kg");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, QT_id, "long_name", 24, "Total water mixing ratio");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, QT_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, QTFLX_id, "units", 4, "W/m2");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, QTFLX_id, "long_name", 16, "Total water flux");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, QTFLX_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, RAM1_id, "units", 4, "frac");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, RAM1_id, "long_name", 4, "RAM1");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, RAM1_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, RELHUM_id, "units", 7, "percent");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, RELHUM_id, "long_name", 17, "Relative humidity");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, RELHUM_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, RHREFHT_id, "units", 8, "fraction");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, RHREFHT_id, "long_name", 34, "Reference height relative humidity");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, RHREFHT_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, SFCLDICE_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, SFCLDICE_id, "long_name", 19, "CLDICE surface flux");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, SFCLDICE_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, SFCLDLIQ_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, SFCLDLIQ_id, "long_name", 19, "CLDLIQ surface flux");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, SFCLDLIQ_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, SFI_id, "units", 8, "FRACTION");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, SFI_id, "long_name", 24, "Interface-layer sat frac");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, SFI_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, SFNUMICE_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, SFNUMICE_id, "long_name", 19, "NUMICE surface flux");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, SFNUMICE_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, SFNUMLIQ_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, SFNUMLIQ_id, "long_name", 19, "NUMLIQ surface flux");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, SFNUMLIQ_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, SHFLX_id, "units", 4, "W/m2");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, SHFLX_id, "long_name", 26, "Surface sensible heat flux");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, SHFLX_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, SL_id, "units", 4, "J/kg");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, SL_id, "long_name", 26, "Liquid water static energy");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, SL_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, SLFLX_id, "units", 4, "W/m2");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, SLFLX_id, "long_name", 25, "Liquid static energy flux");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, SLFLX_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, SLV_id, "units", 4, "J/kg");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, SLV_id, "long_name", 29, "Liq wat virtual static energy");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, SLV_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, SNOWHICE_id, "units", 1, "m");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, SNOWHICE_id, "long_name", 27, "Water equivalent snow depth");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, SNOWHICE_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, SNOWHLND_id, "units", 1, "m");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, SNOWHLND_id, "long_name", 27, "Water equivalent snow depth");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, SNOWHLND_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, SO2_id, "units", 5, "kg/kg");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, SO2_id, "long_name", 3, "SO2");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, SO2_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, SO2_CLXF_id, "units", 11, "molec/cm2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, SO2_CLXF_id, "long_name", 47, "vertically intergrated external forcing for SO2");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, SO2_CLXF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, SO2_XFRC_id, "units", 11, "molec/cm3/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, SO2_XFRC_id, "long_name", 24, "external forcing for SO2");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, SO2_XFRC_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, SOAG_id, "units", 5, "kg/kg");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, SOAG_id, "long_name", 4, "SOAG");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, SOAG_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, SOAG_sfgaex1_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, SOAG_sfgaex1_id, "long_name", 49, "SOAG gas-aerosol-exchange primary column tendency");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, SOAG_sfgaex1_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* Sampling_Sequence */
    stat = nc_put_att_text(ncid, SOLIN_id, "Sampling_Sequence", 8, "rad_lwsw");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, SOLIN_id, "units", 4, "W/m2");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, SOLIN_id, "long_name", 16, "Solar insolation");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, SOLIN_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, SPROD_id, "units", 5, "M2/S3");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, SPROD_id, "long_name", 16, "Shear Production");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, SPROD_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, SRFRAD_id, "units", 4, "W/m2");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, SRFRAD_id, "long_name", 29, "Net radiative flux at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, SRFRAD_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _FillValue */
    static const double SSAVIS_FillValue_att[1] = {1e+36} ;
    stat = nc_put_att_double(ncid, SSAVIS_id, "_FillValue", NC_DOUBLE, 1, SSAVIS_FillValue_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* missing_value */
    static const double SSAVIS_missing_value_att[1] = {1e+36} ;
    stat = nc_put_att_double(ncid, SSAVIS_id, "missing_value", NC_DOUBLE, 1, SSAVIS_missing_value_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, SSAVIS_id, "units", 1, "\000");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, SSAVIS_id, "long_name", 29, "Aerosol singel-scatter albedo");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, SSAVIS_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, SSTODXC_id, "units", 3, "Tau");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, SSTODXC_id, "long_name", 29, "Optical depth for diagnostics");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, SSTODXC_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, SSTSFDRY_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, SSTSFDRY_id, "long_name", 30, "Dry deposition flux at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, SSTSFDRY_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, SSTSFMBL_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, SSTSFMBL_id, "long_name", 28, "Mobilization flux at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, SSTSFMBL_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, SSTSFWET_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, SSTSFWET_id, "long_name", 30, "Wet deposition flux at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, SSTSFWET_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* Sampling_Sequence */
    stat = nc_put_att_text(ncid, SWCF_id, "Sampling_Sequence", 8, "rad_lwsw");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, SWCF_id, "units", 4, "W/m2");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, SWCF_id, "long_name", 23, "Shortwave cloud forcing");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, SWCF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, T_id, "units", 1, "K");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, T_id, "long_name", 11, "Temperature");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, T_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, TAUTMSX_id, "units", 4, "N/m2");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, TAUTMSX_id, "long_name", 44, "Zonal      turbulent mountain surface stress");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, TAUTMSX_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, TAUTMSY_id, "units", 4, "N/m2");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, TAUTMSY_id, "long_name", 44, "Meridional turbulent mountain surface stress");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, TAUTMSY_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, TAUX_id, "units", 4, "N/m2");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, TAUX_id, "long_name", 20, "Zonal surface stress");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, TAUX_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, TAUY_id, "units", 4, "N/m2");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, TAUY_id, "long_name", 25, "Meridional surface stress");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, TAUY_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, TGCLDCWP_id, "units", 5, "kg/m2");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, TGCLDCWP_id, "long_name", 48, "Total grid-box cloud water path (liquid and ice)");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, TGCLDCWP_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, TGCLDIWP_id, "units", 5, "kg/m2");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, TGCLDIWP_id, "long_name", 35, "Total grid-box cloud ice water path");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, TGCLDIWP_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, TGCLDLWP_id, "units", 5, "kg/m2");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, TGCLDLWP_id, "long_name", 38, "Total grid-box cloud liquid water path");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, TGCLDLWP_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, TKE_id, "units", 5, "m2/s2");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, TKE_id, "long_name", 24, "Turbulent Kinetic Energy");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, TKE_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, TMQ_id, "units", 5, "kg/m2");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, TMQ_id, "long_name", 50, "Total (vertically integrated) precipitatable water");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, TMQ_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, TREFHT_id, "units", 1, "K");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, TREFHT_id, "long_name", 28, "Reference height temperature");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, TREFHT_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, TREFMNAV_id, "units", 1, "K");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, TREFMNAV_id, "long_name", 31, "Average of TREFHT daily minimum");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, TREFMNAV_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, TREFMXAV_id, "units", 1, "K");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, TREFMXAV_id, "long_name", 31, "Average of TREFHT daily maximum");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, TREFMXAV_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, TROP_FD_id, "units", 11, "probability");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, TROP_FD_id, "long_name", 16, "Tropopause Found");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, TROP_FD_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _FillValue */
    static const double TROP_P_FillValue_att[1] = {1e+36} ;
    stat = nc_put_att_double(ncid, TROP_P_id, "_FillValue", NC_DOUBLE, 1, TROP_P_FillValue_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* missing_value */
    static const double TROP_P_missing_value_att[1] = {1e+36} ;
    stat = nc_put_att_double(ncid, TROP_P_id, "missing_value", NC_DOUBLE, 1, TROP_P_missing_value_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, TROP_P_id, "units", 2, "Pa");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, TROP_P_id, "long_name", 19, "Tropopause Pressure");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, TROP_P_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, TROP_PD_id, "units", 11, "probability");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, TROP_PD_id, "long_name", 21, "Tropopause Probabilty");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, TROP_PD_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _FillValue */
    static const double TROP_T_FillValue_att[1] = {1e+36} ;
    stat = nc_put_att_double(ncid, TROP_T_id, "_FillValue", NC_DOUBLE, 1, TROP_T_FillValue_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* missing_value */
    static const double TROP_T_missing_value_att[1] = {1e+36} ;
    stat = nc_put_att_double(ncid, TROP_T_id, "missing_value", NC_DOUBLE, 1, TROP_T_missing_value_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, TROP_T_id, "units", 1, "K");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, TROP_T_id, "long_name", 22, "Tropopause Temperature");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, TROP_T_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _FillValue */
    static const double TROP_Z_FillValue_att[1] = {1e+36} ;
    stat = nc_put_att_double(ncid, TROP_Z_id, "_FillValue", NC_DOUBLE, 1, TROP_Z_FillValue_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* missing_value */
    static const double TROP_Z_missing_value_att[1] = {1e+36} ;
    stat = nc_put_att_double(ncid, TROP_Z_id, "missing_value", NC_DOUBLE, 1, TROP_Z_missing_value_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, TROP_Z_id, "units", 1, "m");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, TROP_Z_id, "long_name", 17, "Tropopause Height");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, TROP_Z_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, TS_id, "units", 1, "K");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, TS_id, "long_name", 31, "Surface temperature (radiative)");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, TS_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, TSMN_id, "units", 1, "K");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, TSMN_id, "long_name", 46, "Minimum surface temperature over output period");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, TSMN_id, "cell_methods", 13, "time: minimum");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, TSMX_id, "units", 1, "K");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, TSMX_id, "long_name", 46, "Maximum surface temperature over output period");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, TSMX_id, "cell_methods", 13, "time: maximum");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, U_id, "units", 3, "m/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, U_id, "long_name", 10, "Zonal wind");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, U_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, UFLX_id, "units", 4, "W/m2");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, UFLX_id, "long_name", 19, "Zonal momentum flux");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, UFLX_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, US_id, "units", 3, "m/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, US_id, "long_name", 21, "Zonal wind, staggered");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, US_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, UU_id, "units", 5, "m2/s2");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, UU_id, "long_name", 22, "Zonal velocity squared");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, UU_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, V_id, "units", 3, "m/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, V_id, "long_name", 15, "Meridional wind");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, V_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, VD01_id, "units", 7, "kg/kg/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, VD01_id, "long_name", 23, "Vertical diffusion of Q");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, VD01_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, VFLX_id, "units", 4, "W/m2");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, VFLX_id, "long_name", 23, "Meridional momentm flux");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, VFLX_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, VQ_id, "units", 8, "m/skg/kg");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, VQ_id, "long_name", 26, "Meridional water transport");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, VQ_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, VS_id, "units", 3, "m/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, VS_id, "long_name", 26, "Meridional wind, staggered");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, VS_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, VT_id, "units", 5, "K m/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, VT_id, "long_name", 25, "Meridional heat transport");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, VT_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, VU_id, "units", 5, "m2/s2");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, VU_id, "long_name", 33, "Meridional flux of zonal momentum");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, VU_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, VV_id, "units", 5, "m2/s2");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, VV_id, "long_name", 27, "Meridional velocity squared");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, VV_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, WGUSTD_id, "units", 3, "m/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, WGUSTD_id, "long_name", 26, "wind gusts from turbulence");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, WGUSTD_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, WTKE_id, "units", 3, "m/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, WTKE_id, "long_name", 38, "Standard deviation of updraft velocity");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, WTKE_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, XPH_LWC_id, "units", 5, "kg/kg");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, XPH_LWC_id, "long_name", 26, "pH value multiplied by lwc");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, XPH_LWC_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, Z3_id, "units", 1, "m");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, Z3_id, "long_name", 37, "Geopotential Height (above sea level)");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, Z3_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, airFV_id, "units", 4, "frac");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, airFV_id, "long_name", 2, "FV");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, airFV_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, bc_a1_id, "units", 5, "kg/kg");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, bc_a1_id, "long_name", 5, "bc_a1");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, bc_a1_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, bc_a1DDF_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, bc_a1DDF_id, "long_name", 49, "bc_a1 dry deposition flux at bottom (grav + turb)");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, bc_a1DDF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, bc_a1GVF_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, bc_a1GVF_id, "long_name", 39, "bc_a1 gravitational dry deposition flux");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, bc_a1GVF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, bc_a1SFSBC_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, bc_a1SFSBC_id, "long_name", 55, "Wet deposition flux (belowcloud, convective) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, bc_a1SFSBC_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, bc_a1SFSBS_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, bc_a1SFSBS_id, "long_name", 55, "Wet deposition flux (belowcloud, stratiform) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, bc_a1SFSBS_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, bc_a1SFSIC_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, bc_a1SFSIC_id, "long_name", 52, "Wet deposition flux (incloud, convective) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, bc_a1SFSIC_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, bc_a1SFSIS_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, bc_a1SFSIS_id, "long_name", 52, "Wet deposition flux (incloud, stratiform) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, bc_a1SFSIS_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, bc_a1SFWET_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, bc_a1SFWET_id, "long_name", 30, "Wet deposition flux at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, bc_a1SFWET_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, bc_a1TBF_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, bc_a1TBF_id, "long_name", 35, "bc_a1 turbulent dry deposition flux");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, bc_a1TBF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, bc_a1_CLXF_id, "units", 11, "molec/cm2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, bc_a1_CLXF_id, "long_name", 49, "vertically intergrated external forcing for bc_a1");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, bc_a1_CLXF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, bc_a1_XFRC_id, "units", 11, "molec/cm3/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, bc_a1_XFRC_id, "long_name", 26, "external forcing for bc_a1");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, bc_a1_XFRC_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, bc_c1_id, "units", 5, "kg/kg");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, bc_c1_id, "long_name", 20, "bc_c1 in cloud water");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, bc_c1_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, bc_c1DDF_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, bc_c1DDF_id, "long_name", 49, "bc_c1 dry deposition flux at bottom (grav + turb)");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, bc_c1DDF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, bc_c1GVF_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, bc_c1GVF_id, "long_name", 39, "bc_c1 gravitational dry deposition flux");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, bc_c1GVF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, bc_c1SFSBC_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, bc_c1SFSBC_id, "long_name", 61, "bc_c1 wet deposition flux (belowcloud, convective) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, bc_c1SFSBC_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, bc_c1SFSBS_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, bc_c1SFSBS_id, "long_name", 61, "bc_c1 wet deposition flux (belowcloud, stratiform) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, bc_c1SFSBS_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, bc_c1SFSIC_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, bc_c1SFSIC_id, "long_name", 58, "bc_c1 wet deposition flux (incloud, convective) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, bc_c1SFSIC_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, bc_c1SFSIS_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, bc_c1SFSIS_id, "long_name", 58, "bc_c1 wet deposition flux (incloud, stratiform) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, bc_c1SFSIS_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, bc_c1SFWET_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, bc_c1SFWET_id, "long_name", 36, "bc_c1 wet deposition flux at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, bc_c1SFWET_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, bc_c1TBF_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, bc_c1TBF_id, "long_name", 35, "bc_c1 turbulent dry deposition flux");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, bc_c1TBF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, chem_trop_id, "units", 22, "fraction of model time");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, chem_trop_id, "long_name", 41, "Lowest level with stratospheric chemsitry");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, chem_trop_tropop_id, "units", 22, "fraction of model time");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, chem_trop_tropop_id, "long_name", 44, "Troposphere boundary calculated in chemistry");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, dgnd_a01_id, "units", 1, "m");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, dgnd_a01_id, "long_name", 32, "dry dgnum, interstitial, mode 01");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, dgnd_a01_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, dgnd_a02_id, "units", 1, "m");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, dgnd_a02_id, "long_name", 32, "dry dgnum, interstitial, mode 02");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, dgnd_a02_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, dgnd_a03_id, "units", 1, "m");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, dgnd_a03_id, "long_name", 32, "dry dgnum, interstitial, mode 03");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, dgnd_a03_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, dgnw_a01_id, "units", 1, "m");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, dgnw_a01_id, "long_name", 32, "wet dgnum, interstitial, mode 01");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, dgnw_a01_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, dgnw_a02_id, "units", 1, "m");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, dgnw_a02_id, "long_name", 32, "wet dgnum, interstitial, mode 02");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, dgnw_a02_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, dgnw_a03_id, "units", 1, "m");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, dgnw_a03_id, "long_name", 32, "wet dgnum, interstitial, mode 03");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, dgnw_a03_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, dst_a1_id, "units", 5, "kg/kg");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, dst_a1_id, "long_name", 6, "dst_a1");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, dst_a1_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, dst_a1DDF_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, dst_a1DDF_id, "long_name", 50, "dst_a1 dry deposition flux at bottom (grav + turb)");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, dst_a1DDF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, dst_a1GVF_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, dst_a1GVF_id, "long_name", 40, "dst_a1 gravitational dry deposition flux");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, dst_a1GVF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, dst_a1SF_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, dst_a1SF_id, "long_name", 28, "dst_a1 dust surface emission");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, dst_a1SF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, dst_a1SFSBC_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, dst_a1SFSBC_id, "long_name", 55, "Wet deposition flux (belowcloud, convective) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, dst_a1SFSBC_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, dst_a1SFSBS_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, dst_a1SFSBS_id, "long_name", 55, "Wet deposition flux (belowcloud, stratiform) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, dst_a1SFSBS_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, dst_a1SFSIC_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, dst_a1SFSIC_id, "long_name", 52, "Wet deposition flux (incloud, convective) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, dst_a1SFSIC_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, dst_a1SFSIS_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, dst_a1SFSIS_id, "long_name", 52, "Wet deposition flux (incloud, stratiform) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, dst_a1SFSIS_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, dst_a1SFWET_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, dst_a1SFWET_id, "long_name", 30, "Wet deposition flux at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, dst_a1SFWET_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, dst_a1TBF_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, dst_a1TBF_id, "long_name", 36, "dst_a1 turbulent dry deposition flux");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, dst_a1TBF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, dst_a3_id, "units", 5, "kg/kg");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, dst_a3_id, "long_name", 6, "dst_a3");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, dst_a3_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, dst_a3DDF_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, dst_a3DDF_id, "long_name", 50, "dst_a3 dry deposition flux at bottom (grav + turb)");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, dst_a3DDF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, dst_a3GVF_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, dst_a3GVF_id, "long_name", 40, "dst_a3 gravitational dry deposition flux");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, dst_a3GVF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, dst_a3SF_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, dst_a3SF_id, "long_name", 28, "dst_a3 dust surface emission");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, dst_a3SF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, dst_a3SFSBC_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, dst_a3SFSBC_id, "long_name", 55, "Wet deposition flux (belowcloud, convective) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, dst_a3SFSBC_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, dst_a3SFSBS_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, dst_a3SFSBS_id, "long_name", 55, "Wet deposition flux (belowcloud, stratiform) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, dst_a3SFSBS_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, dst_a3SFSIC_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, dst_a3SFSIC_id, "long_name", 52, "Wet deposition flux (incloud, convective) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, dst_a3SFSIC_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, dst_a3SFSIS_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, dst_a3SFSIS_id, "long_name", 52, "Wet deposition flux (incloud, stratiform) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, dst_a3SFSIS_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, dst_a3SFWET_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, dst_a3SFWET_id, "long_name", 30, "Wet deposition flux at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, dst_a3SFWET_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, dst_a3TBF_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, dst_a3TBF_id, "long_name", 36, "dst_a3 turbulent dry deposition flux");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, dst_a3TBF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, dst_c1_id, "units", 5, "kg/kg");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, dst_c1_id, "long_name", 21, "dst_c1 in cloud water");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, dst_c1_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, dst_c1DDF_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, dst_c1DDF_id, "long_name", 50, "dst_c1 dry deposition flux at bottom (grav + turb)");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, dst_c1DDF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, dst_c1GVF_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, dst_c1GVF_id, "long_name", 40, "dst_c1 gravitational dry deposition flux");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, dst_c1GVF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, dst_c1SFSBC_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, dst_c1SFSBC_id, "long_name", 62, "dst_c1 wet deposition flux (belowcloud, convective) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, dst_c1SFSBC_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, dst_c1SFSBS_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, dst_c1SFSBS_id, "long_name", 62, "dst_c1 wet deposition flux (belowcloud, stratiform) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, dst_c1SFSBS_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, dst_c1SFSIC_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, dst_c1SFSIC_id, "long_name", 59, "dst_c1 wet deposition flux (incloud, convective) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, dst_c1SFSIC_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, dst_c1SFSIS_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, dst_c1SFSIS_id, "long_name", 59, "dst_c1 wet deposition flux (incloud, stratiform) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, dst_c1SFSIS_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, dst_c1SFWET_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, dst_c1SFWET_id, "long_name", 37, "dst_c1 wet deposition flux at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, dst_c1SFWET_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, dst_c1TBF_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, dst_c1TBF_id, "long_name", 36, "dst_c1 turbulent dry deposition flux");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, dst_c1TBF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, dst_c3_id, "units", 5, "kg/kg");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, dst_c3_id, "long_name", 21, "dst_c3 in cloud water");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, dst_c3_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, dst_c3DDF_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, dst_c3DDF_id, "long_name", 50, "dst_c3 dry deposition flux at bottom (grav + turb)");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, dst_c3DDF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, dst_c3GVF_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, dst_c3GVF_id, "long_name", 40, "dst_c3 gravitational dry deposition flux");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, dst_c3GVF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, dst_c3SFSBC_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, dst_c3SFSBC_id, "long_name", 62, "dst_c3 wet deposition flux (belowcloud, convective) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, dst_c3SFSBC_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, dst_c3SFSBS_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, dst_c3SFSBS_id, "long_name", 62, "dst_c3 wet deposition flux (belowcloud, stratiform) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, dst_c3SFSBS_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, dst_c3SFSIC_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, dst_c3SFSIC_id, "long_name", 59, "dst_c3 wet deposition flux (incloud, convective) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, dst_c3SFSIC_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, dst_c3SFSIS_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, dst_c3SFSIS_id, "long_name", 59, "dst_c3 wet deposition flux (incloud, stratiform) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, dst_c3SFSIS_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, dst_c3SFWET_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, dst_c3SFWET_id, "long_name", 37, "dst_c3 wet deposition flux at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, dst_c3SFWET_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, dst_c3TBF_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, dst_c3TBF_id, "long_name", 36, "dst_c3 turbulent dry deposition flux");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, dst_c3TBF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, ncl_a1_id, "units", 5, "kg/kg");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, ncl_a1_id, "long_name", 6, "ncl_a1");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, ncl_a1_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, ncl_a1DDF_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, ncl_a1DDF_id, "long_name", 50, "ncl_a1 dry deposition flux at bottom (grav + turb)");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, ncl_a1DDF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, ncl_a1GVF_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, ncl_a1GVF_id, "long_name", 40, "ncl_a1 gravitational dry deposition flux");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, ncl_a1GVF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, ncl_a1SF_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, ncl_a1SF_id, "long_name", 36, "ncl_a1 progseasalts surface emission");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, ncl_a1SF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, ncl_a1SFSBC_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, ncl_a1SFSBC_id, "long_name", 55, "Wet deposition flux (belowcloud, convective) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, ncl_a1SFSBC_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, ncl_a1SFSBS_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, ncl_a1SFSBS_id, "long_name", 55, "Wet deposition flux (belowcloud, stratiform) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, ncl_a1SFSBS_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, ncl_a1SFSIC_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, ncl_a1SFSIC_id, "long_name", 52, "Wet deposition flux (incloud, convective) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, ncl_a1SFSIC_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, ncl_a1SFSIS_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, ncl_a1SFSIS_id, "long_name", 52, "Wet deposition flux (incloud, stratiform) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, ncl_a1SFSIS_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, ncl_a1SFWET_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, ncl_a1SFWET_id, "long_name", 30, "Wet deposition flux at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, ncl_a1SFWET_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, ncl_a1TBF_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, ncl_a1TBF_id, "long_name", 36, "ncl_a1 turbulent dry deposition flux");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, ncl_a1TBF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, ncl_a1_sfcoag1_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, ncl_a1_sfcoag1_id, "long_name", 45, "ncl_a1 modal_aero coagulation column tendency");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, ncl_a1_sfcoag1_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, ncl_a1_sfcsiz3_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, ncl_a1_sfcsiz3_id, "long_name", 54, "ncl_a1 calcsize aitken-to-accum adjust column tendency");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, ncl_a1_sfcsiz3_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, ncl_a1_sfcsiz4_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, ncl_a1_sfcsiz4_id, "long_name", 54, "ncl_a1 calcsize accum-to-aitken adjust column tendency");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, ncl_a1_sfcsiz4_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, ncl_a1_sfgaex2_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, ncl_a1_sfgaex2_id, "long_name", 52, "ncl_a1 gas-aerosol-exchange renaming column tendency");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, ncl_a1_sfgaex2_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, ncl_a2_id, "units", 5, "kg/kg");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, ncl_a2_id, "long_name", 6, "ncl_a2");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, ncl_a2_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, ncl_a2DDF_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, ncl_a2DDF_id, "long_name", 50, "ncl_a2 dry deposition flux at bottom (grav + turb)");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, ncl_a2DDF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, ncl_a2GVF_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, ncl_a2GVF_id, "long_name", 40, "ncl_a2 gravitational dry deposition flux");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, ncl_a2GVF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, ncl_a2SF_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, ncl_a2SF_id, "long_name", 36, "ncl_a2 progseasalts surface emission");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, ncl_a2SF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, ncl_a2SFSBC_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, ncl_a2SFSBC_id, "long_name", 55, "Wet deposition flux (belowcloud, convective) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, ncl_a2SFSBC_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, ncl_a2SFSBS_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, ncl_a2SFSBS_id, "long_name", 55, "Wet deposition flux (belowcloud, stratiform) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, ncl_a2SFSBS_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, ncl_a2SFSIC_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, ncl_a2SFSIC_id, "long_name", 52, "Wet deposition flux (incloud, convective) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, ncl_a2SFSIC_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, ncl_a2SFSIS_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, ncl_a2SFSIS_id, "long_name", 52, "Wet deposition flux (incloud, stratiform) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, ncl_a2SFSIS_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, ncl_a2SFWET_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, ncl_a2SFWET_id, "long_name", 30, "Wet deposition flux at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, ncl_a2SFWET_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, ncl_a2TBF_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, ncl_a2TBF_id, "long_name", 36, "ncl_a2 turbulent dry deposition flux");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, ncl_a2TBF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, ncl_a2_sfcoag1_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, ncl_a2_sfcoag1_id, "long_name", 45, "ncl_a2 modal_aero coagulation column tendency");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, ncl_a2_sfcoag1_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, ncl_a2_sfcsiz3_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, ncl_a2_sfcsiz3_id, "long_name", 54, "ncl_a2 calcsize aitken-to-accum adjust column tendency");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, ncl_a2_sfcsiz3_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, ncl_a2_sfcsiz4_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, ncl_a2_sfcsiz4_id, "long_name", 54, "ncl_a2 calcsize accum-to-aitken adjust column tendency");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, ncl_a2_sfcsiz4_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, ncl_a2_sfgaex2_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, ncl_a2_sfgaex2_id, "long_name", 52, "ncl_a2 gas-aerosol-exchange renaming column tendency");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, ncl_a2_sfgaex2_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, ncl_a3_id, "units", 5, "kg/kg");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, ncl_a3_id, "long_name", 6, "ncl_a3");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, ncl_a3_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, ncl_a3DDF_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, ncl_a3DDF_id, "long_name", 50, "ncl_a3 dry deposition flux at bottom (grav + turb)");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, ncl_a3DDF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, ncl_a3GVF_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, ncl_a3GVF_id, "long_name", 40, "ncl_a3 gravitational dry deposition flux");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, ncl_a3GVF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, ncl_a3SF_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, ncl_a3SF_id, "long_name", 36, "ncl_a3 progseasalts surface emission");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, ncl_a3SF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, ncl_a3SFSBC_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, ncl_a3SFSBC_id, "long_name", 55, "Wet deposition flux (belowcloud, convective) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, ncl_a3SFSBC_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, ncl_a3SFSBS_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, ncl_a3SFSBS_id, "long_name", 55, "Wet deposition flux (belowcloud, stratiform) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, ncl_a3SFSBS_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, ncl_a3SFSIC_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, ncl_a3SFSIC_id, "long_name", 52, "Wet deposition flux (incloud, convective) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, ncl_a3SFSIC_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, ncl_a3SFSIS_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, ncl_a3SFSIS_id, "long_name", 52, "Wet deposition flux (incloud, stratiform) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, ncl_a3SFSIS_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, ncl_a3SFWET_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, ncl_a3SFWET_id, "long_name", 30, "Wet deposition flux at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, ncl_a3SFWET_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, ncl_a3TBF_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, ncl_a3TBF_id, "long_name", 36, "ncl_a3 turbulent dry deposition flux");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, ncl_a3TBF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, ncl_c1_id, "units", 5, "kg/kg");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, ncl_c1_id, "long_name", 21, "ncl_c1 in cloud water");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, ncl_c1_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, ncl_c1DDF_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, ncl_c1DDF_id, "long_name", 50, "ncl_c1 dry deposition flux at bottom (grav + turb)");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, ncl_c1DDF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, ncl_c1GVF_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, ncl_c1GVF_id, "long_name", 40, "ncl_c1 gravitational dry deposition flux");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, ncl_c1GVF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, ncl_c1SFSBC_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, ncl_c1SFSBC_id, "long_name", 62, "ncl_c1 wet deposition flux (belowcloud, convective) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, ncl_c1SFSBC_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, ncl_c1SFSBS_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, ncl_c1SFSBS_id, "long_name", 62, "ncl_c1 wet deposition flux (belowcloud, stratiform) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, ncl_c1SFSBS_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, ncl_c1SFSIC_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, ncl_c1SFSIC_id, "long_name", 59, "ncl_c1 wet deposition flux (incloud, convective) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, ncl_c1SFSIC_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, ncl_c1SFSIS_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, ncl_c1SFSIS_id, "long_name", 59, "ncl_c1 wet deposition flux (incloud, stratiform) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, ncl_c1SFSIS_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, ncl_c1SFWET_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, ncl_c1SFWET_id, "long_name", 37, "ncl_c1 wet deposition flux at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, ncl_c1SFWET_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, ncl_c1TBF_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, ncl_c1TBF_id, "long_name", 36, "ncl_c1 turbulent dry deposition flux");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, ncl_c1TBF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, ncl_c1_sfcsiz3_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, ncl_c1_sfcsiz3_id, "long_name", 54, "ncl_c1 calcsize aitken-to-accum adjust column tendency");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, ncl_c1_sfcsiz3_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, ncl_c1_sfcsiz4_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, ncl_c1_sfcsiz4_id, "long_name", 54, "ncl_c1 calcsize accum-to-aitken adjust column tendency");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, ncl_c1_sfcsiz4_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, ncl_c1_sfgaex2_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, ncl_c1_sfgaex2_id, "long_name", 52, "ncl_c1 gas-aerosol-exchange renaming column tendency");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, ncl_c1_sfgaex2_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, ncl_c2_id, "units", 5, "kg/kg");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, ncl_c2_id, "long_name", 21, "ncl_c2 in cloud water");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, ncl_c2_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, ncl_c2DDF_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, ncl_c2DDF_id, "long_name", 50, "ncl_c2 dry deposition flux at bottom (grav + turb)");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, ncl_c2DDF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, ncl_c2GVF_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, ncl_c2GVF_id, "long_name", 40, "ncl_c2 gravitational dry deposition flux");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, ncl_c2GVF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, ncl_c2SFSBC_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, ncl_c2SFSBC_id, "long_name", 62, "ncl_c2 wet deposition flux (belowcloud, convective) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, ncl_c2SFSBC_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, ncl_c2SFSBS_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, ncl_c2SFSBS_id, "long_name", 62, "ncl_c2 wet deposition flux (belowcloud, stratiform) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, ncl_c2SFSBS_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, ncl_c2SFSIC_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, ncl_c2SFSIC_id, "long_name", 59, "ncl_c2 wet deposition flux (incloud, convective) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, ncl_c2SFSIC_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, ncl_c2SFSIS_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, ncl_c2SFSIS_id, "long_name", 59, "ncl_c2 wet deposition flux (incloud, stratiform) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, ncl_c2SFSIS_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, ncl_c2SFWET_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, ncl_c2SFWET_id, "long_name", 37, "ncl_c2 wet deposition flux at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, ncl_c2SFWET_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, ncl_c2TBF_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, ncl_c2TBF_id, "long_name", 36, "ncl_c2 turbulent dry deposition flux");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, ncl_c2TBF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, ncl_c2_sfcsiz3_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, ncl_c2_sfcsiz3_id, "long_name", 54, "ncl_c2 calcsize aitken-to-accum adjust column tendency");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, ncl_c2_sfcsiz3_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, ncl_c2_sfcsiz4_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, ncl_c2_sfcsiz4_id, "long_name", 54, "ncl_c2 calcsize accum-to-aitken adjust column tendency");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, ncl_c2_sfcsiz4_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, ncl_c2_sfgaex2_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, ncl_c2_sfgaex2_id, "long_name", 52, "ncl_c2 gas-aerosol-exchange renaming column tendency");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, ncl_c2_sfgaex2_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, ncl_c3_id, "units", 5, "kg/kg");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, ncl_c3_id, "long_name", 21, "ncl_c3 in cloud water");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, ncl_c3_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, ncl_c3DDF_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, ncl_c3DDF_id, "long_name", 50, "ncl_c3 dry deposition flux at bottom (grav + turb)");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, ncl_c3DDF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, ncl_c3GVF_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, ncl_c3GVF_id, "long_name", 40, "ncl_c3 gravitational dry deposition flux");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, ncl_c3GVF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, ncl_c3SFSBC_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, ncl_c3SFSBC_id, "long_name", 62, "ncl_c3 wet deposition flux (belowcloud, convective) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, ncl_c3SFSBC_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, ncl_c3SFSBS_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, ncl_c3SFSBS_id, "long_name", 62, "ncl_c3 wet deposition flux (belowcloud, stratiform) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, ncl_c3SFSBS_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, ncl_c3SFSIC_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, ncl_c3SFSIC_id, "long_name", 59, "ncl_c3 wet deposition flux (incloud, convective) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, ncl_c3SFSIC_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, ncl_c3SFSIS_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, ncl_c3SFSIS_id, "long_name", 59, "ncl_c3 wet deposition flux (incloud, stratiform) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, ncl_c3SFSIS_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, ncl_c3SFWET_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, ncl_c3SFWET_id, "long_name", 37, "ncl_c3 wet deposition flux at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, ncl_c3SFWET_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, ncl_c3TBF_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, ncl_c3TBF_id, "long_name", 36, "ncl_c3 turbulent dry deposition flux");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, ncl_c3TBF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, num_a1_id, "units", 5, "kg/kg");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, num_a1_id, "long_name", 6, "num_a1");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, num_a1_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, num_a1DDF_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, num_a1DDF_id, "long_name", 50, "num_a1 dry deposition flux at bottom (grav + turb)");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, num_a1DDF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, num_a1GVF_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, num_a1GVF_id, "long_name", 40, "num_a1 gravitational dry deposition flux");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, num_a1GVF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, num_a1SFSBC_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, num_a1SFSBC_id, "long_name", 55, "Wet deposition flux (belowcloud, convective) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, num_a1SFSBC_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, num_a1SFSBS_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, num_a1SFSBS_id, "long_name", 55, "Wet deposition flux (belowcloud, stratiform) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, num_a1SFSBS_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, num_a1SFSIC_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, num_a1SFSIC_id, "long_name", 52, "Wet deposition flux (incloud, convective) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, num_a1SFSIC_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, num_a1SFSIS_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, num_a1SFSIS_id, "long_name", 52, "Wet deposition flux (incloud, stratiform) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, num_a1SFSIS_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, num_a1SFWET_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, num_a1SFWET_id, "long_name", 30, "Wet deposition flux at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, num_a1SFWET_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, num_a1TBF_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, num_a1TBF_id, "long_name", 36, "num_a1 turbulent dry deposition flux");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, num_a1TBF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, num_a1_CLXF_id, "units", 11, "molec/cm2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, num_a1_CLXF_id, "long_name", 50, "vertically intergrated external forcing for num_a1");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, num_a1_CLXF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, num_a1_XFRC_id, "units", 11, "molec/cm3/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, num_a1_XFRC_id, "long_name", 27, "external forcing for num_a1");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, num_a1_XFRC_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, num_a1_sfcoag1_id, "units", 6, "#/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, num_a1_sfcoag1_id, "long_name", 45, "num_a1 modal_aero coagulation column tendency");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, num_a1_sfcoag1_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, num_a1_sfcsiz1_id, "units", 6, "#/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, num_a1_sfcsiz1_id, "long_name", 43, "num_a1 calcsize number-adjust column source");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, num_a1_sfcsiz1_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, num_a1_sfcsiz2_id, "units", 6, "#/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, num_a1_sfcsiz2_id, "long_name", 41, "num_a1 calcsize number-adjust column sink");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, num_a1_sfcsiz2_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, num_a1_sfcsiz3_id, "units", 6, "#/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, num_a1_sfcsiz3_id, "long_name", 54, "num_a1 calcsize aitken-to-accum adjust column tendency");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, num_a1_sfcsiz3_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, num_a1_sfcsiz4_id, "units", 6, "#/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, num_a1_sfcsiz4_id, "long_name", 54, "num_a1 calcsize accum-to-aitken adjust column tendency");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, num_a1_sfcsiz4_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, num_a1_sfgaex2_id, "units", 6, "#/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, num_a1_sfgaex2_id, "long_name", 52, "num_a1 gas-aerosol-exchange renaming column tendency");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, num_a1_sfgaex2_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, num_a2_id, "units", 5, "kg/kg");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, num_a2_id, "long_name", 6, "num_a2");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, num_a2_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, num_a2DDF_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, num_a2DDF_id, "long_name", 50, "num_a2 dry deposition flux at bottom (grav + turb)");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, num_a2DDF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, num_a2GVF_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, num_a2GVF_id, "long_name", 40, "num_a2 gravitational dry deposition flux");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, num_a2GVF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, num_a2SFSBC_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, num_a2SFSBC_id, "long_name", 55, "Wet deposition flux (belowcloud, convective) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, num_a2SFSBC_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, num_a2SFSBS_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, num_a2SFSBS_id, "long_name", 55, "Wet deposition flux (belowcloud, stratiform) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, num_a2SFSBS_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, num_a2SFSIC_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, num_a2SFSIC_id, "long_name", 52, "Wet deposition flux (incloud, convective) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, num_a2SFSIC_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, num_a2SFSIS_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, num_a2SFSIS_id, "long_name", 52, "Wet deposition flux (incloud, stratiform) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, num_a2SFSIS_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, num_a2SFWET_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, num_a2SFWET_id, "long_name", 30, "Wet deposition flux at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, num_a2SFWET_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, num_a2TBF_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, num_a2TBF_id, "long_name", 36, "num_a2 turbulent dry deposition flux");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, num_a2TBF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, num_a2_CLXF_id, "units", 11, "molec/cm2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, num_a2_CLXF_id, "long_name", 50, "vertically intergrated external forcing for num_a2");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, num_a2_CLXF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, num_a2_XFRC_id, "units", 11, "molec/cm3/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, num_a2_XFRC_id, "long_name", 27, "external forcing for num_a2");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, num_a2_XFRC_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, num_a2_sfcoag1_id, "units", 6, "#/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, num_a2_sfcoag1_id, "long_name", 45, "num_a2 modal_aero coagulation column tendency");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, num_a2_sfcoag1_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, num_a2_sfcsiz1_id, "units", 6, "#/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, num_a2_sfcsiz1_id, "long_name", 43, "num_a2 calcsize number-adjust column source");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, num_a2_sfcsiz1_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, num_a2_sfcsiz2_id, "units", 6, "#/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, num_a2_sfcsiz2_id, "long_name", 41, "num_a2 calcsize number-adjust column sink");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, num_a2_sfcsiz2_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, num_a2_sfcsiz3_id, "units", 6, "#/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, num_a2_sfcsiz3_id, "long_name", 54, "num_a2 calcsize aitken-to-accum adjust column tendency");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, num_a2_sfcsiz3_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, num_a2_sfcsiz4_id, "units", 6, "#/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, num_a2_sfcsiz4_id, "long_name", 54, "num_a2 calcsize accum-to-aitken adjust column tendency");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, num_a2_sfcsiz4_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, num_a2_sfgaex2_id, "units", 6, "#/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, num_a2_sfgaex2_id, "long_name", 52, "num_a2 gas-aerosol-exchange renaming column tendency");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, num_a2_sfgaex2_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, num_a2_sfnnuc1_id, "units", 6, "#/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, num_a2_sfnnuc1_id, "long_name", 57, "num_a2 modal_aero new particle nucleation column tendency");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, num_a2_sfnnuc1_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, num_a3_id, "units", 5, "kg/kg");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, num_a3_id, "long_name", 6, "num_a3");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, num_a3_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, num_a3DDF_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, num_a3DDF_id, "long_name", 50, "num_a3 dry deposition flux at bottom (grav + turb)");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, num_a3DDF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, num_a3GVF_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, num_a3GVF_id, "long_name", 40, "num_a3 gravitational dry deposition flux");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, num_a3GVF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, num_a3SFSBC_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, num_a3SFSBC_id, "long_name", 55, "Wet deposition flux (belowcloud, convective) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, num_a3SFSBC_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, num_a3SFSBS_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, num_a3SFSBS_id, "long_name", 55, "Wet deposition flux (belowcloud, stratiform) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, num_a3SFSBS_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, num_a3SFSIC_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, num_a3SFSIC_id, "long_name", 52, "Wet deposition flux (incloud, convective) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, num_a3SFSIC_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, num_a3SFSIS_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, num_a3SFSIS_id, "long_name", 52, "Wet deposition flux (incloud, stratiform) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, num_a3SFSIS_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, num_a3SFWET_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, num_a3SFWET_id, "long_name", 30, "Wet deposition flux at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, num_a3SFWET_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, num_a3TBF_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, num_a3TBF_id, "long_name", 36, "num_a3 turbulent dry deposition flux");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, num_a3TBF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, num_a3_sfcsiz1_id, "units", 6, "#/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, num_a3_sfcsiz1_id, "long_name", 43, "num_a3 calcsize number-adjust column source");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, num_a3_sfcsiz1_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, num_a3_sfcsiz2_id, "units", 6, "#/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, num_a3_sfcsiz2_id, "long_name", 41, "num_a3 calcsize number-adjust column sink");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, num_a3_sfcsiz2_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, num_c1_id, "units", 5, "kg/kg");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, num_c1_id, "long_name", 21, "num_c1 in cloud water");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, num_c1_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, num_c1DDF_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, num_c1DDF_id, "long_name", 50, "num_c1 dry deposition flux at bottom (grav + turb)");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, num_c1DDF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, num_c1GVF_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, num_c1GVF_id, "long_name", 40, "num_c1 gravitational dry deposition flux");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, num_c1GVF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, num_c1SFSBC_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, num_c1SFSBC_id, "long_name", 62, "num_c1 wet deposition flux (belowcloud, convective) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, num_c1SFSBC_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, num_c1SFSBS_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, num_c1SFSBS_id, "long_name", 62, "num_c1 wet deposition flux (belowcloud, stratiform) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, num_c1SFSBS_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, num_c1SFSIC_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, num_c1SFSIC_id, "long_name", 59, "num_c1 wet deposition flux (incloud, convective) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, num_c1SFSIC_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, num_c1SFSIS_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, num_c1SFSIS_id, "long_name", 59, "num_c1 wet deposition flux (incloud, stratiform) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, num_c1SFSIS_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, num_c1SFWET_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, num_c1SFWET_id, "long_name", 37, "num_c1 wet deposition flux at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, num_c1SFWET_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, num_c1TBF_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, num_c1TBF_id, "long_name", 36, "num_c1 turbulent dry deposition flux");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, num_c1TBF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, num_c1_sfcsiz1_id, "units", 6, "#/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, num_c1_sfcsiz1_id, "long_name", 43, "num_c1 calcsize number-adjust column source");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, num_c1_sfcsiz1_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, num_c1_sfcsiz2_id, "units", 6, "#/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, num_c1_sfcsiz2_id, "long_name", 41, "num_c1 calcsize number-adjust column sink");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, num_c1_sfcsiz2_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, num_c1_sfcsiz3_id, "units", 6, "#/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, num_c1_sfcsiz3_id, "long_name", 54, "num_c1 calcsize aitken-to-accum adjust column tendency");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, num_c1_sfcsiz3_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, num_c1_sfcsiz4_id, "units", 6, "#/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, num_c1_sfcsiz4_id, "long_name", 54, "num_c1 calcsize accum-to-aitken adjust column tendency");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, num_c1_sfcsiz4_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, num_c1_sfgaex2_id, "units", 6, "#/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, num_c1_sfgaex2_id, "long_name", 52, "num_c1 gas-aerosol-exchange renaming column tendency");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, num_c1_sfgaex2_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, num_c2_id, "units", 5, "kg/kg");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, num_c2_id, "long_name", 21, "num_c2 in cloud water");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, num_c2_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, num_c2DDF_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, num_c2DDF_id, "long_name", 50, "num_c2 dry deposition flux at bottom (grav + turb)");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, num_c2DDF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, num_c2GVF_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, num_c2GVF_id, "long_name", 40, "num_c2 gravitational dry deposition flux");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, num_c2GVF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, num_c2SFSBC_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, num_c2SFSBC_id, "long_name", 62, "num_c2 wet deposition flux (belowcloud, convective) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, num_c2SFSBC_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, num_c2SFSBS_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, num_c2SFSBS_id, "long_name", 62, "num_c2 wet deposition flux (belowcloud, stratiform) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, num_c2SFSBS_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, num_c2SFSIC_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, num_c2SFSIC_id, "long_name", 59, "num_c2 wet deposition flux (incloud, convective) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, num_c2SFSIC_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, num_c2SFSIS_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, num_c2SFSIS_id, "long_name", 59, "num_c2 wet deposition flux (incloud, stratiform) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, num_c2SFSIS_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, num_c2SFWET_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, num_c2SFWET_id, "long_name", 37, "num_c2 wet deposition flux at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, num_c2SFWET_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, num_c2TBF_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, num_c2TBF_id, "long_name", 36, "num_c2 turbulent dry deposition flux");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, num_c2TBF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, num_c2_sfcsiz1_id, "units", 6, "#/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, num_c2_sfcsiz1_id, "long_name", 43, "num_c2 calcsize number-adjust column source");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, num_c2_sfcsiz1_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, num_c2_sfcsiz2_id, "units", 6, "#/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, num_c2_sfcsiz2_id, "long_name", 41, "num_c2 calcsize number-adjust column sink");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, num_c2_sfcsiz2_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, num_c2_sfcsiz3_id, "units", 6, "#/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, num_c2_sfcsiz3_id, "long_name", 54, "num_c2 calcsize aitken-to-accum adjust column tendency");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, num_c2_sfcsiz3_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, num_c2_sfcsiz4_id, "units", 6, "#/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, num_c2_sfcsiz4_id, "long_name", 54, "num_c2 calcsize accum-to-aitken adjust column tendency");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, num_c2_sfcsiz4_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, num_c2_sfgaex2_id, "units", 6, "#/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, num_c2_sfgaex2_id, "long_name", 52, "num_c2 gas-aerosol-exchange renaming column tendency");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, num_c2_sfgaex2_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, num_c3_id, "units", 5, "kg/kg");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, num_c3_id, "long_name", 21, "num_c3 in cloud water");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, num_c3_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, num_c3DDF_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, num_c3DDF_id, "long_name", 50, "num_c3 dry deposition flux at bottom (grav + turb)");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, num_c3DDF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, num_c3GVF_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, num_c3GVF_id, "long_name", 40, "num_c3 gravitational dry deposition flux");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, num_c3GVF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, num_c3SFSBC_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, num_c3SFSBC_id, "long_name", 62, "num_c3 wet deposition flux (belowcloud, convective) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, num_c3SFSBC_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, num_c3SFSBS_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, num_c3SFSBS_id, "long_name", 62, "num_c3 wet deposition flux (belowcloud, stratiform) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, num_c3SFSBS_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, num_c3SFSIC_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, num_c3SFSIC_id, "long_name", 59, "num_c3 wet deposition flux (incloud, convective) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, num_c3SFSIC_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, num_c3SFSIS_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, num_c3SFSIS_id, "long_name", 59, "num_c3 wet deposition flux (incloud, stratiform) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, num_c3SFSIS_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, num_c3SFWET_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, num_c3SFWET_id, "long_name", 37, "num_c3 wet deposition flux at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, num_c3SFWET_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, num_c3TBF_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, num_c3TBF_id, "long_name", 36, "num_c3 turbulent dry deposition flux");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, num_c3TBF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, num_c3_sfcsiz1_id, "units", 6, "#/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, num_c3_sfcsiz1_id, "long_name", 43, "num_c3 calcsize number-adjust column source");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, num_c3_sfcsiz1_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, num_c3_sfcsiz2_id, "units", 6, "#/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, num_c3_sfcsiz2_id, "long_name", 41, "num_c3 calcsize number-adjust column sink");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, num_c3_sfcsiz2_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, pom_a1_id, "units", 5, "kg/kg");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, pom_a1_id, "long_name", 6, "pom_a1");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, pom_a1_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, pom_a1DDF_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, pom_a1DDF_id, "long_name", 50, "pom_a1 dry deposition flux at bottom (grav + turb)");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, pom_a1DDF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, pom_a1GVF_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, pom_a1GVF_id, "long_name", 40, "pom_a1 gravitational dry deposition flux");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, pom_a1GVF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, pom_a1SFSBC_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, pom_a1SFSBC_id, "long_name", 55, "Wet deposition flux (belowcloud, convective) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, pom_a1SFSBC_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, pom_a1SFSBS_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, pom_a1SFSBS_id, "long_name", 55, "Wet deposition flux (belowcloud, stratiform) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, pom_a1SFSBS_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, pom_a1SFSIC_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, pom_a1SFSIC_id, "long_name", 52, "Wet deposition flux (incloud, convective) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, pom_a1SFSIC_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, pom_a1SFSIS_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, pom_a1SFSIS_id, "long_name", 52, "Wet deposition flux (incloud, stratiform) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, pom_a1SFSIS_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, pom_a1SFWET_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, pom_a1SFWET_id, "long_name", 30, "Wet deposition flux at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, pom_a1SFWET_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, pom_a1TBF_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, pom_a1TBF_id, "long_name", 36, "pom_a1 turbulent dry deposition flux");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, pom_a1TBF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, pom_a1_CLXF_id, "units", 11, "molec/cm2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, pom_a1_CLXF_id, "long_name", 50, "vertically intergrated external forcing for pom_a1");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, pom_a1_CLXF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, pom_a1_XFRC_id, "units", 11, "molec/cm3/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, pom_a1_XFRC_id, "long_name", 27, "external forcing for pom_a1");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, pom_a1_XFRC_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, pom_c1_id, "units", 5, "kg/kg");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, pom_c1_id, "long_name", 21, "pom_c1 in cloud water");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, pom_c1_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, pom_c1DDF_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, pom_c1DDF_id, "long_name", 50, "pom_c1 dry deposition flux at bottom (grav + turb)");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, pom_c1DDF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, pom_c1GVF_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, pom_c1GVF_id, "long_name", 40, "pom_c1 gravitational dry deposition flux");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, pom_c1GVF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, pom_c1SFSBC_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, pom_c1SFSBC_id, "long_name", 62, "pom_c1 wet deposition flux (belowcloud, convective) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, pom_c1SFSBC_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, pom_c1SFSBS_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, pom_c1SFSBS_id, "long_name", 62, "pom_c1 wet deposition flux (belowcloud, stratiform) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, pom_c1SFSBS_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, pom_c1SFSIC_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, pom_c1SFSIC_id, "long_name", 59, "pom_c1 wet deposition flux (incloud, convective) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, pom_c1SFSIC_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, pom_c1SFSIS_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, pom_c1SFSIS_id, "long_name", 59, "pom_c1 wet deposition flux (incloud, stratiform) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, pom_c1SFSIS_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, pom_c1SFWET_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, pom_c1SFWET_id, "long_name", 37, "pom_c1 wet deposition flux at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, pom_c1SFWET_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, pom_c1TBF_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, pom_c1TBF_id, "long_name", 36, "pom_c1 turbulent dry deposition flux");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, pom_c1TBF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, so4_a1_id, "units", 5, "kg/kg");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, so4_a1_id, "long_name", 6, "so4_a1");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, so4_a1_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, so4_a1DDF_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, so4_a1DDF_id, "long_name", 50, "so4_a1 dry deposition flux at bottom (grav + turb)");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, so4_a1DDF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, so4_a1GVF_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, so4_a1GVF_id, "long_name", 40, "so4_a1 gravitational dry deposition flux");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, so4_a1GVF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, so4_a1SFSBC_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, so4_a1SFSBC_id, "long_name", 55, "Wet deposition flux (belowcloud, convective) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, so4_a1SFSBC_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, so4_a1SFSBS_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, so4_a1SFSBS_id, "long_name", 55, "Wet deposition flux (belowcloud, stratiform) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, so4_a1SFSBS_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, so4_a1SFSIC_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, so4_a1SFSIC_id, "long_name", 52, "Wet deposition flux (incloud, convective) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, so4_a1SFSIC_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, so4_a1SFSIS_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, so4_a1SFSIS_id, "long_name", 52, "Wet deposition flux (incloud, stratiform) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, so4_a1SFSIS_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, so4_a1SFWET_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, so4_a1SFWET_id, "long_name", 30, "Wet deposition flux at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, so4_a1SFWET_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, so4_a1TBF_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, so4_a1TBF_id, "long_name", 36, "so4_a1 turbulent dry deposition flux");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, so4_a1TBF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, so4_a1_CLXF_id, "units", 11, "molec/cm2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, so4_a1_CLXF_id, "long_name", 50, "vertically intergrated external forcing for so4_a1");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, so4_a1_CLXF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, so4_a1_XFRC_id, "units", 11, "molec/cm3/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, so4_a1_XFRC_id, "long_name", 27, "external forcing for so4_a1");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, so4_a1_XFRC_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, so4_a1_sfcoag1_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, so4_a1_sfcoag1_id, "long_name", 45, "so4_a1 modal_aero coagulation column tendency");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, so4_a1_sfcoag1_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, so4_a1_sfcsiz3_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, so4_a1_sfcsiz3_id, "long_name", 54, "so4_a1 calcsize aitken-to-accum adjust column tendency");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, so4_a1_sfcsiz3_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, so4_a1_sfcsiz4_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, so4_a1_sfcsiz4_id, "long_name", 54, "so4_a1 calcsize accum-to-aitken adjust column tendency");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, so4_a1_sfcsiz4_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, so4_a1_sfgaex1_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, so4_a1_sfgaex1_id, "long_name", 51, "so4_a1 gas-aerosol-exchange primary column tendency");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, so4_a1_sfgaex1_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, so4_a1_sfgaex2_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, so4_a1_sfgaex2_id, "long_name", 52, "so4_a1 gas-aerosol-exchange renaming column tendency");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, so4_a1_sfgaex2_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, so4_a2_id, "units", 5, "kg/kg");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, so4_a2_id, "long_name", 6, "so4_a2");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, so4_a2_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, so4_a2DDF_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, so4_a2DDF_id, "long_name", 50, "so4_a2 dry deposition flux at bottom (grav + turb)");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, so4_a2DDF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, so4_a2GVF_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, so4_a2GVF_id, "long_name", 40, "so4_a2 gravitational dry deposition flux");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, so4_a2GVF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, so4_a2SFSBC_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, so4_a2SFSBC_id, "long_name", 55, "Wet deposition flux (belowcloud, convective) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, so4_a2SFSBC_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, so4_a2SFSBS_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, so4_a2SFSBS_id, "long_name", 55, "Wet deposition flux (belowcloud, stratiform) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, so4_a2SFSBS_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, so4_a2SFSIC_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, so4_a2SFSIC_id, "long_name", 52, "Wet deposition flux (incloud, convective) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, so4_a2SFSIC_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, so4_a2SFSIS_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, so4_a2SFSIS_id, "long_name", 52, "Wet deposition flux (incloud, stratiform) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, so4_a2SFSIS_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, so4_a2SFWET_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, so4_a2SFWET_id, "long_name", 30, "Wet deposition flux at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, so4_a2SFWET_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, so4_a2TBF_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, so4_a2TBF_id, "long_name", 36, "so4_a2 turbulent dry deposition flux");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, so4_a2TBF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, so4_a2_CLXF_id, "units", 11, "molec/cm2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, so4_a2_CLXF_id, "long_name", 50, "vertically intergrated external forcing for so4_a2");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, so4_a2_CLXF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, so4_a2_XFRC_id, "units", 11, "molec/cm3/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, so4_a2_XFRC_id, "long_name", 27, "external forcing for so4_a2");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, so4_a2_XFRC_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, so4_a2_sfcoag1_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, so4_a2_sfcoag1_id, "long_name", 45, "so4_a2 modal_aero coagulation column tendency");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, so4_a2_sfcoag1_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, so4_a2_sfcsiz3_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, so4_a2_sfcsiz3_id, "long_name", 54, "so4_a2 calcsize aitken-to-accum adjust column tendency");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, so4_a2_sfcsiz3_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, so4_a2_sfcsiz4_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, so4_a2_sfcsiz4_id, "long_name", 54, "so4_a2 calcsize accum-to-aitken adjust column tendency");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, so4_a2_sfcsiz4_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, so4_a2_sfgaex1_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, so4_a2_sfgaex1_id, "long_name", 51, "so4_a2 gas-aerosol-exchange primary column tendency");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, so4_a2_sfgaex1_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, so4_a2_sfgaex2_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, so4_a2_sfgaex2_id, "long_name", 52, "so4_a2 gas-aerosol-exchange renaming column tendency");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, so4_a2_sfgaex2_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, so4_a2_sfnnuc1_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, so4_a2_sfnnuc1_id, "long_name", 57, "so4_a2 modal_aero new particle nucleation column tendency");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, so4_a2_sfnnuc1_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, so4_a3_id, "units", 5, "kg/kg");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, so4_a3_id, "long_name", 6, "so4_a3");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, so4_a3_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, so4_a3DDF_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, so4_a3DDF_id, "long_name", 50, "so4_a3 dry deposition flux at bottom (grav + turb)");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, so4_a3DDF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, so4_a3GVF_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, so4_a3GVF_id, "long_name", 40, "so4_a3 gravitational dry deposition flux");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, so4_a3GVF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, so4_a3SFSBC_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, so4_a3SFSBC_id, "long_name", 55, "Wet deposition flux (belowcloud, convective) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, so4_a3SFSBC_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, so4_a3SFSBS_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, so4_a3SFSBS_id, "long_name", 55, "Wet deposition flux (belowcloud, stratiform) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, so4_a3SFSBS_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, so4_a3SFSIC_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, so4_a3SFSIC_id, "long_name", 52, "Wet deposition flux (incloud, convective) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, so4_a3SFSIC_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, so4_a3SFSIS_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, so4_a3SFSIS_id, "long_name", 52, "Wet deposition flux (incloud, stratiform) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, so4_a3SFSIS_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, so4_a3SFWET_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, so4_a3SFWET_id, "long_name", 30, "Wet deposition flux at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, so4_a3SFWET_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, so4_a3TBF_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, so4_a3TBF_id, "long_name", 36, "so4_a3 turbulent dry deposition flux");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, so4_a3TBF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, so4_a3_sfgaex1_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, so4_a3_sfgaex1_id, "long_name", 51, "so4_a3 gas-aerosol-exchange primary column tendency");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, so4_a3_sfgaex1_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, so4_c1_id, "units", 5, "kg/kg");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, so4_c1_id, "long_name", 21, "so4_c1 in cloud water");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, so4_c1_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, so4_c1AQH2SO4_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, so4_c1AQH2SO4_id, "long_name", 30, "so4_c1 aqueous phase chemistry");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, so4_c1AQH2SO4_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, so4_c1AQSO4_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, so4_c1AQSO4_id, "long_name", 30, "so4_c1 aqueous phase chemistry");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, so4_c1AQSO4_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, so4_c1DDF_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, so4_c1DDF_id, "long_name", 50, "so4_c1 dry deposition flux at bottom (grav + turb)");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, so4_c1DDF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, so4_c1GVF_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, so4_c1GVF_id, "long_name", 40, "so4_c1 gravitational dry deposition flux");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, so4_c1GVF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, so4_c1SFSBC_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, so4_c1SFSBC_id, "long_name", 62, "so4_c1 wet deposition flux (belowcloud, convective) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, so4_c1SFSBC_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, so4_c1SFSBS_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, so4_c1SFSBS_id, "long_name", 62, "so4_c1 wet deposition flux (belowcloud, stratiform) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, so4_c1SFSBS_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, so4_c1SFSIC_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, so4_c1SFSIC_id, "long_name", 59, "so4_c1 wet deposition flux (incloud, convective) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, so4_c1SFSIC_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, so4_c1SFSIS_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, so4_c1SFSIS_id, "long_name", 59, "so4_c1 wet deposition flux (incloud, stratiform) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, so4_c1SFSIS_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, so4_c1SFWET_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, so4_c1SFWET_id, "long_name", 37, "so4_c1 wet deposition flux at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, so4_c1SFWET_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, so4_c1TBF_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, so4_c1TBF_id, "long_name", 36, "so4_c1 turbulent dry deposition flux");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, so4_c1TBF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, so4_c1_sfcsiz3_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, so4_c1_sfcsiz3_id, "long_name", 54, "so4_c1 calcsize aitken-to-accum adjust column tendency");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, so4_c1_sfcsiz3_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, so4_c1_sfcsiz4_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, so4_c1_sfcsiz4_id, "long_name", 54, "so4_c1 calcsize accum-to-aitken adjust column tendency");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, so4_c1_sfcsiz4_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, so4_c1_sfgaex2_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, so4_c1_sfgaex2_id, "long_name", 52, "so4_c1 gas-aerosol-exchange renaming column tendency");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, so4_c1_sfgaex2_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, so4_c2_id, "units", 5, "kg/kg");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, so4_c2_id, "long_name", 21, "so4_c2 in cloud water");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, so4_c2_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, so4_c2AQH2SO4_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, so4_c2AQH2SO4_id, "long_name", 30, "so4_c2 aqueous phase chemistry");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, so4_c2AQH2SO4_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, so4_c2AQSO4_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, so4_c2AQSO4_id, "long_name", 30, "so4_c2 aqueous phase chemistry");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, so4_c2AQSO4_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, so4_c2DDF_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, so4_c2DDF_id, "long_name", 50, "so4_c2 dry deposition flux at bottom (grav + turb)");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, so4_c2DDF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, so4_c2GVF_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, so4_c2GVF_id, "long_name", 40, "so4_c2 gravitational dry deposition flux");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, so4_c2GVF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, so4_c2SFSBC_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, so4_c2SFSBC_id, "long_name", 62, "so4_c2 wet deposition flux (belowcloud, convective) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, so4_c2SFSBC_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, so4_c2SFSBS_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, so4_c2SFSBS_id, "long_name", 62, "so4_c2 wet deposition flux (belowcloud, stratiform) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, so4_c2SFSBS_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, so4_c2SFSIC_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, so4_c2SFSIC_id, "long_name", 59, "so4_c2 wet deposition flux (incloud, convective) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, so4_c2SFSIC_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, so4_c2SFSIS_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, so4_c2SFSIS_id, "long_name", 59, "so4_c2 wet deposition flux (incloud, stratiform) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, so4_c2SFSIS_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, so4_c2SFWET_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, so4_c2SFWET_id, "long_name", 37, "so4_c2 wet deposition flux at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, so4_c2SFWET_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, so4_c2TBF_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, so4_c2TBF_id, "long_name", 36, "so4_c2 turbulent dry deposition flux");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, so4_c2TBF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, so4_c2_sfcsiz3_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, so4_c2_sfcsiz3_id, "long_name", 54, "so4_c2 calcsize aitken-to-accum adjust column tendency");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, so4_c2_sfcsiz3_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, so4_c2_sfcsiz4_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, so4_c2_sfcsiz4_id, "long_name", 54, "so4_c2 calcsize accum-to-aitken adjust column tendency");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, so4_c2_sfcsiz4_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, so4_c2_sfgaex2_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, so4_c2_sfgaex2_id, "long_name", 52, "so4_c2 gas-aerosol-exchange renaming column tendency");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, so4_c2_sfgaex2_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, so4_c3_id, "units", 5, "kg/kg");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, so4_c3_id, "long_name", 21, "so4_c3 in cloud water");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, so4_c3_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, so4_c3AQH2SO4_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, so4_c3AQH2SO4_id, "long_name", 30, "so4_c3 aqueous phase chemistry");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, so4_c3AQH2SO4_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, so4_c3AQSO4_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, so4_c3AQSO4_id, "long_name", 30, "so4_c3 aqueous phase chemistry");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, so4_c3AQSO4_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, so4_c3DDF_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, so4_c3DDF_id, "long_name", 50, "so4_c3 dry deposition flux at bottom (grav + turb)");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, so4_c3DDF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, so4_c3GVF_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, so4_c3GVF_id, "long_name", 40, "so4_c3 gravitational dry deposition flux");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, so4_c3GVF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, so4_c3SFSBC_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, so4_c3SFSBC_id, "long_name", 62, "so4_c3 wet deposition flux (belowcloud, convective) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, so4_c3SFSBC_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, so4_c3SFSBS_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, so4_c3SFSBS_id, "long_name", 62, "so4_c3 wet deposition flux (belowcloud, stratiform) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, so4_c3SFSBS_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, so4_c3SFSIC_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, so4_c3SFSIC_id, "long_name", 59, "so4_c3 wet deposition flux (incloud, convective) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, so4_c3SFSIC_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, so4_c3SFSIS_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, so4_c3SFSIS_id, "long_name", 59, "so4_c3 wet deposition flux (incloud, stratiform) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, so4_c3SFSIS_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, so4_c3SFWET_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, so4_c3SFWET_id, "long_name", 37, "so4_c3 wet deposition flux at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, so4_c3SFWET_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, so4_c3TBF_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, so4_c3TBF_id, "long_name", 36, "so4_c3 turbulent dry deposition flux");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, so4_c3TBF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, soa_a1_id, "units", 5, "kg/kg");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, soa_a1_id, "long_name", 6, "soa_a1");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, soa_a1_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, soa_a1DDF_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, soa_a1DDF_id, "long_name", 50, "soa_a1 dry deposition flux at bottom (grav + turb)");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, soa_a1DDF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, soa_a1GVF_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, soa_a1GVF_id, "long_name", 40, "soa_a1 gravitational dry deposition flux");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, soa_a1GVF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, soa_a1SFSBC_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, soa_a1SFSBC_id, "long_name", 55, "Wet deposition flux (belowcloud, convective) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, soa_a1SFSBC_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, soa_a1SFSBS_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, soa_a1SFSBS_id, "long_name", 55, "Wet deposition flux (belowcloud, stratiform) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, soa_a1SFSBS_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, soa_a1SFSIC_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, soa_a1SFSIC_id, "long_name", 52, "Wet deposition flux (incloud, convective) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, soa_a1SFSIC_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, soa_a1SFSIS_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, soa_a1SFSIS_id, "long_name", 52, "Wet deposition flux (incloud, stratiform) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, soa_a1SFSIS_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, soa_a1SFWET_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, soa_a1SFWET_id, "long_name", 30, "Wet deposition flux at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, soa_a1SFWET_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, soa_a1TBF_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, soa_a1TBF_id, "long_name", 36, "soa_a1 turbulent dry deposition flux");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, soa_a1TBF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, soa_a1_sfcoag1_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, soa_a1_sfcoag1_id, "long_name", 45, "soa_a1 modal_aero coagulation column tendency");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, soa_a1_sfcoag1_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, soa_a1_sfcsiz3_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, soa_a1_sfcsiz3_id, "long_name", 54, "soa_a1 calcsize aitken-to-accum adjust column tendency");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, soa_a1_sfcsiz3_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, soa_a1_sfcsiz4_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, soa_a1_sfcsiz4_id, "long_name", 54, "soa_a1 calcsize accum-to-aitken adjust column tendency");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, soa_a1_sfcsiz4_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, soa_a1_sfgaex1_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, soa_a1_sfgaex1_id, "long_name", 51, "soa_a1 gas-aerosol-exchange primary column tendency");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, soa_a1_sfgaex1_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, soa_a1_sfgaex2_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, soa_a1_sfgaex2_id, "long_name", 52, "soa_a1 gas-aerosol-exchange renaming column tendency");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, soa_a1_sfgaex2_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, soa_a2_id, "units", 5, "kg/kg");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, soa_a2_id, "long_name", 6, "soa_a2");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, soa_a2_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, soa_a2DDF_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, soa_a2DDF_id, "long_name", 50, "soa_a2 dry deposition flux at bottom (grav + turb)");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, soa_a2DDF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, soa_a2GVF_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, soa_a2GVF_id, "long_name", 40, "soa_a2 gravitational dry deposition flux");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, soa_a2GVF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, soa_a2SFSBC_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, soa_a2SFSBC_id, "long_name", 55, "Wet deposition flux (belowcloud, convective) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, soa_a2SFSBC_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, soa_a2SFSBS_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, soa_a2SFSBS_id, "long_name", 55, "Wet deposition flux (belowcloud, stratiform) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, soa_a2SFSBS_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, soa_a2SFSIC_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, soa_a2SFSIC_id, "long_name", 52, "Wet deposition flux (incloud, convective) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, soa_a2SFSIC_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, soa_a2SFSIS_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, soa_a2SFSIS_id, "long_name", 52, "Wet deposition flux (incloud, stratiform) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, soa_a2SFSIS_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, soa_a2SFWET_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, soa_a2SFWET_id, "long_name", 30, "Wet deposition flux at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, soa_a2SFWET_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, soa_a2TBF_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, soa_a2TBF_id, "long_name", 36, "soa_a2 turbulent dry deposition flux");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, soa_a2TBF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, soa_a2_sfcoag1_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, soa_a2_sfcoag1_id, "long_name", 45, "soa_a2 modal_aero coagulation column tendency");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, soa_a2_sfcoag1_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, soa_a2_sfcsiz3_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, soa_a2_sfcsiz3_id, "long_name", 54, "soa_a2 calcsize aitken-to-accum adjust column tendency");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, soa_a2_sfcsiz3_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, soa_a2_sfcsiz4_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, soa_a2_sfcsiz4_id, "long_name", 54, "soa_a2 calcsize accum-to-aitken adjust column tendency");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, soa_a2_sfcsiz4_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, soa_a2_sfgaex1_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, soa_a2_sfgaex1_id, "long_name", 51, "soa_a2 gas-aerosol-exchange primary column tendency");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, soa_a2_sfgaex1_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, soa_a2_sfgaex2_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, soa_a2_sfgaex2_id, "long_name", 52, "soa_a2 gas-aerosol-exchange renaming column tendency");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, soa_a2_sfgaex2_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, soa_c1_id, "units", 5, "kg/kg");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, soa_c1_id, "long_name", 21, "soa_c1 in cloud water");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, soa_c1_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, soa_c1DDF_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, soa_c1DDF_id, "long_name", 50, "soa_c1 dry deposition flux at bottom (grav + turb)");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, soa_c1DDF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, soa_c1GVF_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, soa_c1GVF_id, "long_name", 40, "soa_c1 gravitational dry deposition flux");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, soa_c1GVF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, soa_c1SFSBC_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, soa_c1SFSBC_id, "long_name", 62, "soa_c1 wet deposition flux (belowcloud, convective) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, soa_c1SFSBC_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, soa_c1SFSBS_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, soa_c1SFSBS_id, "long_name", 62, "soa_c1 wet deposition flux (belowcloud, stratiform) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, soa_c1SFSBS_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, soa_c1SFSIC_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, soa_c1SFSIC_id, "long_name", 59, "soa_c1 wet deposition flux (incloud, convective) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, soa_c1SFSIC_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, soa_c1SFSIS_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, soa_c1SFSIS_id, "long_name", 59, "soa_c1 wet deposition flux (incloud, stratiform) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, soa_c1SFSIS_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, soa_c1SFWET_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, soa_c1SFWET_id, "long_name", 37, "soa_c1 wet deposition flux at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, soa_c1SFWET_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, soa_c1TBF_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, soa_c1TBF_id, "long_name", 36, "soa_c1 turbulent dry deposition flux");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, soa_c1TBF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, soa_c1_sfcsiz3_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, soa_c1_sfcsiz3_id, "long_name", 54, "soa_c1 calcsize aitken-to-accum adjust column tendency");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, soa_c1_sfcsiz3_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, soa_c1_sfcsiz4_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, soa_c1_sfcsiz4_id, "long_name", 54, "soa_c1 calcsize accum-to-aitken adjust column tendency");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, soa_c1_sfcsiz4_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, soa_c1_sfgaex2_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, soa_c1_sfgaex2_id, "long_name", 52, "soa_c1 gas-aerosol-exchange renaming column tendency");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, soa_c1_sfgaex2_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, soa_c2_id, "units", 5, "kg/kg");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, soa_c2_id, "long_name", 21, "soa_c2 in cloud water");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, soa_c2_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, soa_c2DDF_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, soa_c2DDF_id, "long_name", 50, "soa_c2 dry deposition flux at bottom (grav + turb)");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, soa_c2DDF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, soa_c2GVF_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, soa_c2GVF_id, "long_name", 40, "soa_c2 gravitational dry deposition flux");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, soa_c2GVF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, soa_c2SFSBC_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, soa_c2SFSBC_id, "long_name", 62, "soa_c2 wet deposition flux (belowcloud, convective) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, soa_c2SFSBC_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, soa_c2SFSBS_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, soa_c2SFSBS_id, "long_name", 62, "soa_c2 wet deposition flux (belowcloud, stratiform) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, soa_c2SFSBS_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, soa_c2SFSIC_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, soa_c2SFSIC_id, "long_name", 59, "soa_c2 wet deposition flux (incloud, convective) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, soa_c2SFSIC_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, soa_c2SFSIS_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, soa_c2SFSIS_id, "long_name", 59, "soa_c2 wet deposition flux (incloud, stratiform) at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, soa_c2SFSIS_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, soa_c2SFWET_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, soa_c2SFWET_id, "long_name", 37, "soa_c2 wet deposition flux at surface");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, soa_c2SFWET_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, soa_c2TBF_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, soa_c2TBF_id, "long_name", 36, "soa_c2 turbulent dry deposition flux");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, soa_c2TBF_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, soa_c2_sfcsiz3_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, soa_c2_sfcsiz3_id, "long_name", 54, "soa_c2 calcsize aitken-to-accum adjust column tendency");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, soa_c2_sfcsiz3_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, soa_c2_sfcsiz4_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, soa_c2_sfcsiz4_id, "long_name", 54, "soa_c2 calcsize accum-to-aitken adjust column tendency");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, soa_c2_sfcsiz4_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, soa_c2_sfgaex2_id, "units", 7, "kg/m2/s");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, soa_c2_sfgaex2_id, "long_name", 52, "soa_c2 gas-aerosol-exchange renaming column tendency");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, soa_c2_sfgaex2_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, wat_a1_id, "units", 1, "m");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, wat_a1_id, "long_name", 36, "aerosol water, interstitial, mode 01");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, wat_a1_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, wat_a2_id, "units", 1, "m");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, wat_a2_id, "long_name", 36, "aerosol water, interstitial, mode 02");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, wat_a2_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* units */
    stat = nc_put_att_text(ncid, wat_a3_id, "units", 1, "m");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* long_name */
    stat = nc_put_att_text(ncid, wat_a3_id, "long_name", 36, "aerosol water, interstitial, mode 03");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* cell_methods */
    stat = nc_put_att_text(ncid, wat_a3_id, "cell_methods", 10, "time: mean");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _Storage */
    stat = nc_put_att_text(ncid, lat_id, "_Storage", 10, "contiguous");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _Storage */
    stat = nc_put_att_text(ncid, lon_id, "_Storage", 10, "contiguous");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _Storage */
    stat = nc_put_att_text(ncid, slat_id, "_Storage", 10, "contiguous");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _Storage */
    stat = nc_put_att_text(ncid, slon_id, "_Storage", 10, "contiguous");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _Storage */
    stat = nc_put_att_text(ncid, w_stag_id, "_Storage", 10, "contiguous");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _Storage */
    stat = nc_put_att_text(ncid, lev_id, "_Storage", 10, "contiguous");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _Storage */
    stat = nc_put_att_text(ncid, ilev_id, "_Storage", 10, "contiguous");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _Storage */
    stat = nc_put_att_text(ncid, isccp_prs_id, "_Storage", 10, "contiguous");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _Storage */
    stat = nc_put_att_text(ncid, isccp_tau_id, "_Storage", 10, "contiguous");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _Storage */
    stat = nc_put_att_text(ncid, isccp_prstau_id, "_Storage", 10, "contiguous");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int time_ChunkSizes_att[1] = {1} ;
    stat = nc_put_att_int(ncid, time_id, "_ChunkSizes", NC_INT, 1, time_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int time_bnds_ChunkSizes_att[2] = {1, 2} ;
    stat = nc_put_att_int(ncid, time_bnds_id, "_ChunkSizes", NC_INT, 2, time_bnds_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int date_written_ChunkSizes_att[2] = {1, 8} ;
    stat = nc_put_att_int(ncid, date_written_id, "_ChunkSizes", NC_INT, 2, date_written_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int time_written_ChunkSizes_att[2] = {1, 8} ;
    stat = nc_put_att_int(ncid, time_written_id, "_ChunkSizes", NC_INT, 2, time_written_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _Endianness */
    stat = nc_put_att_text(ncid, ntrm_id, "_Endianness", 3, "big");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _Endianness */
    stat = nc_put_att_text(ncid, ntrn_id, "_Endianness", 3, "big");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _Endianness */
    stat = nc_put_att_text(ncid, ntrk_id, "_Endianness", 3, "big");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _Endianness */
    stat = nc_put_att_text(ncid, ndbase_id, "_Endianness", 3, "big");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _Endianness */
    stat = nc_put_att_text(ncid, nsbase_id, "_Endianness", 3, "big");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _Endianness */
    stat = nc_put_att_text(ncid, nbdate_id, "_Endianness", 3, "big");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _Endianness */
    stat = nc_put_att_text(ncid, nbsec_id, "_Endianness", 3, "big");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _Endianness */
    stat = nc_put_att_text(ncid, mdt_id, "_Endianness", 3, "big");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _Storage */
    stat = nc_put_att_text(ncid, nlon_id, "_Storage", 10, "contiguous");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _Endianness */
    stat = nc_put_att_text(ncid, nlon_id, "_Endianness", 3, "big");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _Storage */
    stat = nc_put_att_text(ncid, wnummax_id, "_Storage", 10, "contiguous");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _Endianness */
    stat = nc_put_att_text(ncid, wnummax_id, "_Endianness", 3, "big");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _Storage */
    stat = nc_put_att_text(ncid, hyai_id, "_Storage", 10, "contiguous");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _Storage */
    stat = nc_put_att_text(ncid, hybi_id, "_Storage", 10, "contiguous");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _Storage */
    stat = nc_put_att_text(ncid, hyam_id, "_Storage", 10, "contiguous");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _Storage */
    stat = nc_put_att_text(ncid, hybm_id, "_Storage", 10, "contiguous");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _Storage */
    stat = nc_put_att_text(ncid, gw_id, "_Storage", 10, "contiguous");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int ndcur_ChunkSizes_att[1] = {1} ;
    stat = nc_put_att_int(ncid, ndcur_id, "_ChunkSizes", NC_INT, 1, ndcur_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _Endianness */
    stat = nc_put_att_text(ncid, ndcur_id, "_Endianness", 3, "big");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int nscur_ChunkSizes_att[1] = {1} ;
    stat = nc_put_att_int(ncid, nscur_id, "_ChunkSizes", NC_INT, 1, nscur_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _Endianness */
    stat = nc_put_att_text(ncid, nscur_id, "_Endianness", 3, "big");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int date_ChunkSizes_att[1] = {1} ;
    stat = nc_put_att_int(ncid, date_id, "_ChunkSizes", NC_INT, 1, date_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _Endianness */
    stat = nc_put_att_text(ncid, date_id, "_Endianness", 3, "big");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int co2vmr_ChunkSizes_att[1] = {1} ;
    stat = nc_put_att_int(ncid, co2vmr_id, "_ChunkSizes", NC_INT, 1, co2vmr_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int ch4vmr_ChunkSizes_att[1] = {1} ;
    stat = nc_put_att_int(ncid, ch4vmr_id, "_ChunkSizes", NC_INT, 1, ch4vmr_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int n2ovmr_ChunkSizes_att[1] = {1} ;
    stat = nc_put_att_int(ncid, n2ovmr_id, "_ChunkSizes", NC_INT, 1, n2ovmr_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int f11vmr_ChunkSizes_att[1] = {1} ;
    stat = nc_put_att_int(ncid, f11vmr_id, "_ChunkSizes", NC_INT, 1, f11vmr_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int f12vmr_ChunkSizes_att[1] = {1} ;
    stat = nc_put_att_int(ncid, f12vmr_id, "_ChunkSizes", NC_INT, 1, f12vmr_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int sol_tsi_ChunkSizes_att[1] = {1} ;
    stat = nc_put_att_int(ncid, sol_tsi_id, "_ChunkSizes", NC_INT, 1, sol_tsi_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int datesec_ChunkSizes_att[1] = {1} ;
    stat = nc_put_att_int(ncid, datesec_id, "_ChunkSizes", NC_INT, 1, datesec_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _Endianness */
    stat = nc_put_att_text(ncid, datesec_id, "_Endianness", 3, "big");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int nsteph_ChunkSizes_att[1] = {1} ;
    stat = nc_put_att_int(ncid, nsteph_id, "_ChunkSizes", NC_INT, 1, nsteph_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _Endianness */
    stat = nc_put_att_text(ncid, nsteph_id, "_Endianness", 3, "big");
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int ABSORB_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, ABSORB_id, "_ChunkSizes", NC_INT, 4, ABSORB_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int AEROD_v_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, AEROD_v_id, "_ChunkSizes", NC_INT, 3, AEROD_v_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int AODABS_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, AODABS_id, "_ChunkSizes", NC_INT, 3, AODABS_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int AODDUST1_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, AODDUST1_id, "_ChunkSizes", NC_INT, 3, AODDUST1_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int AODDUST2_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, AODDUST2_id, "_ChunkSizes", NC_INT, 3, AODDUST2_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int AODDUST3_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, AODDUST3_id, "_ChunkSizes", NC_INT, 3, AODDUST3_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int AODMODE1_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, AODMODE1_id, "_ChunkSizes", NC_INT, 3, AODMODE1_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int AODMODE2_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, AODMODE2_id, "_ChunkSizes", NC_INT, 3, AODMODE2_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int AODMODE3_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, AODMODE3_id, "_ChunkSizes", NC_INT, 3, AODMODE3_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int AODVIS_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, AODVIS_id, "_ChunkSizes", NC_INT, 3, AODVIS_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int AQSO4_H2O2_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, AQSO4_H2O2_id, "_ChunkSizes", NC_INT, 3, AQSO4_H2O2_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int AQSO4_O3_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, AQSO4_O3_id, "_ChunkSizes", NC_INT, 3, AQSO4_O3_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int AQ_DMS_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, AQ_DMS_id, "_ChunkSizes", NC_INT, 3, AQ_DMS_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int AQ_H2O2_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, AQ_H2O2_id, "_ChunkSizes", NC_INT, 3, AQ_H2O2_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int AQ_H2SO4_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, AQ_H2SO4_id, "_ChunkSizes", NC_INT, 3, AQ_H2SO4_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int AQ_SO2_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, AQ_SO2_id, "_ChunkSizes", NC_INT, 3, AQ_SO2_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int AQ_SOAG_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, AQ_SOAG_id, "_ChunkSizes", NC_INT, 3, AQ_SOAG_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int AQ_bc_a1_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, AQ_bc_a1_id, "_ChunkSizes", NC_INT, 3, AQ_bc_a1_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int AQ_dst_a1_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, AQ_dst_a1_id, "_ChunkSizes", NC_INT, 3, AQ_dst_a1_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int AQ_dst_a3_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, AQ_dst_a3_id, "_ChunkSizes", NC_INT, 3, AQ_dst_a3_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int AQ_ncl_a1_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, AQ_ncl_a1_id, "_ChunkSizes", NC_INT, 3, AQ_ncl_a1_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int AQ_ncl_a2_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, AQ_ncl_a2_id, "_ChunkSizes", NC_INT, 3, AQ_ncl_a2_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int AQ_ncl_a3_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, AQ_ncl_a3_id, "_ChunkSizes", NC_INT, 3, AQ_ncl_a3_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int AQ_num_a1_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, AQ_num_a1_id, "_ChunkSizes", NC_INT, 3, AQ_num_a1_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int AQ_num_a2_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, AQ_num_a2_id, "_ChunkSizes", NC_INT, 3, AQ_num_a2_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int AQ_num_a3_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, AQ_num_a3_id, "_ChunkSizes", NC_INT, 3, AQ_num_a3_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int AQ_pom_a1_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, AQ_pom_a1_id, "_ChunkSizes", NC_INT, 3, AQ_pom_a1_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int AQ_so4_a1_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, AQ_so4_a1_id, "_ChunkSizes", NC_INT, 3, AQ_so4_a1_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int AQ_so4_a2_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, AQ_so4_a2_id, "_ChunkSizes", NC_INT, 3, AQ_so4_a2_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int AQ_so4_a3_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, AQ_so4_a3_id, "_ChunkSizes", NC_INT, 3, AQ_so4_a3_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int AQ_soa_a1_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, AQ_soa_a1_id, "_ChunkSizes", NC_INT, 3, AQ_soa_a1_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int AQ_soa_a2_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, AQ_soa_a2_id, "_ChunkSizes", NC_INT, 3, AQ_soa_a2_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int BPROD_ChunkSizes_att[4] = {1, 31, 96, 144} ;
    stat = nc_put_att_int(ncid, BPROD_id, "_ChunkSizes", NC_INT, 4, BPROD_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int BURDEN1_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, BURDEN1_id, "_ChunkSizes", NC_INT, 3, BURDEN1_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int BURDEN2_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, BURDEN2_id, "_ChunkSizes", NC_INT, 3, BURDEN2_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int BURDEN3_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, BURDEN3_id, "_ChunkSizes", NC_INT, 3, BURDEN3_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int CCN1_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, CCN1_id, "_ChunkSizes", NC_INT, 4, CCN1_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int CCN2_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, CCN2_id, "_ChunkSizes", NC_INT, 4, CCN2_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int CCN3_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, CCN3_id, "_ChunkSizes", NC_INT, 4, CCN3_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int CCN4_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, CCN4_id, "_ChunkSizes", NC_INT, 4, CCN4_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int CCN5_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, CCN5_id, "_ChunkSizes", NC_INT, 4, CCN5_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int CCN6_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, CCN6_id, "_ChunkSizes", NC_INT, 4, CCN6_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int CLDHGH_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, CLDHGH_id, "_ChunkSizes", NC_INT, 3, CLDHGH_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int CLDICE_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, CLDICE_id, "_ChunkSizes", NC_INT, 4, CLDICE_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int CLDLIQ_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, CLDLIQ_id, "_ChunkSizes", NC_INT, 4, CLDLIQ_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int CLDLOW_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, CLDLOW_id, "_ChunkSizes", NC_INT, 3, CLDLOW_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int CLDMED_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, CLDMED_id, "_ChunkSizes", NC_INT, 3, CLDMED_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int CLDTOT_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, CLDTOT_id, "_ChunkSizes", NC_INT, 3, CLDTOT_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int CLOUD_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, CLOUD_id, "_ChunkSizes", NC_INT, 4, CLOUD_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int CMFDQ_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, CMFDQ_id, "_ChunkSizes", NC_INT, 4, CMFDQ_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int CMFDQR_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, CMFDQR_id, "_ChunkSizes", NC_INT, 4, CMFDQR_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int CMFDT_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, CMFDT_id, "_ChunkSizes", NC_INT, 4, CMFDT_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int CMFMC_ChunkSizes_att[4] = {1, 31, 96, 144} ;
    stat = nc_put_att_int(ncid, CMFMC_id, "_ChunkSizes", NC_INT, 4, CMFMC_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int CMFMCDZM_ChunkSizes_att[4] = {1, 31, 96, 144} ;
    stat = nc_put_att_int(ncid, CMFMCDZM_id, "_ChunkSizes", NC_INT, 4, CMFMCDZM_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int CONCLD_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, CONCLD_id, "_ChunkSizes", NC_INT, 4, CONCLD_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int DCQ_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, DCQ_id, "_ChunkSizes", NC_INT, 4, DCQ_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int DMS_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, DMS_id, "_ChunkSizes", NC_INT, 4, DMS_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int DSTODXC_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, DSTODXC_id, "_ChunkSizes", NC_INT, 3, DSTODXC_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int DSTSFDRY_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, DSTSFDRY_id, "_ChunkSizes", NC_INT, 3, DSTSFDRY_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int DSTSFMBL_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, DSTSFMBL_id, "_ChunkSizes", NC_INT, 3, DSTSFMBL_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int DSTSFWET_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, DSTSFWET_id, "_ChunkSizes", NC_INT, 3, DSTSFWET_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int DTCOND_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, DTCOND_id, "_ChunkSizes", NC_INT, 4, DTCOND_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int DTV_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, DTV_id, "_ChunkSizes", NC_INT, 4, DTV_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int EXTINCT_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, EXTINCT_id, "_ChunkSizes", NC_INT, 4, EXTINCT_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int FICE_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, FICE_id, "_ChunkSizes", NC_INT, 4, FICE_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int FLDS_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, FLDS_id, "_ChunkSizes", NC_INT, 3, FLDS_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int FLNS_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, FLNS_id, "_ChunkSizes", NC_INT, 3, FLNS_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int FLNSC_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, FLNSC_id, "_ChunkSizes", NC_INT, 3, FLNSC_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int FLNT_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, FLNT_id, "_ChunkSizes", NC_INT, 3, FLNT_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int FLNTC_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, FLNTC_id, "_ChunkSizes", NC_INT, 3, FLNTC_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int FLUT_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, FLUT_id, "_ChunkSizes", NC_INT, 3, FLUT_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int FLUTC_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, FLUTC_id, "_ChunkSizes", NC_INT, 3, FLUTC_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int FREQSH_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, FREQSH_id, "_ChunkSizes", NC_INT, 3, FREQSH_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int FREQZM_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, FREQZM_id, "_ChunkSizes", NC_INT, 3, FREQZM_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int FSDS_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, FSDS_id, "_ChunkSizes", NC_INT, 3, FSDS_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int FSDSC_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, FSDSC_id, "_ChunkSizes", NC_INT, 3, FSDSC_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int FSNS_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, FSNS_id, "_ChunkSizes", NC_INT, 3, FSNS_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int FSNSC_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, FSNSC_id, "_ChunkSizes", NC_INT, 3, FSNSC_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int FSNT_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, FSNT_id, "_ChunkSizes", NC_INT, 3, FSNT_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int FSNTC_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, FSNTC_id, "_ChunkSizes", NC_INT, 3, FSNTC_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int FSNTOA_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, FSNTOA_id, "_ChunkSizes", NC_INT, 3, FSNTOA_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int FSNTOAC_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, FSNTOAC_id, "_ChunkSizes", NC_INT, 3, FSNTOAC_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int FSUTOA_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, FSUTOA_id, "_ChunkSizes", NC_INT, 3, FSUTOA_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int GS_DMS_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, GS_DMS_id, "_ChunkSizes", NC_INT, 3, GS_DMS_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int GS_H2O2_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, GS_H2O2_id, "_ChunkSizes", NC_INT, 3, GS_H2O2_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int GS_H2SO4_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, GS_H2SO4_id, "_ChunkSizes", NC_INT, 3, GS_H2SO4_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int GS_SO2_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, GS_SO2_id, "_ChunkSizes", NC_INT, 3, GS_SO2_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int GS_SOAG_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, GS_SOAG_id, "_ChunkSizes", NC_INT, 3, GS_SOAG_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int GS_bc_a1_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, GS_bc_a1_id, "_ChunkSizes", NC_INT, 3, GS_bc_a1_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int GS_dst_a1_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, GS_dst_a1_id, "_ChunkSizes", NC_INT, 3, GS_dst_a1_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int GS_dst_a3_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, GS_dst_a3_id, "_ChunkSizes", NC_INT, 3, GS_dst_a3_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int GS_ncl_a1_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, GS_ncl_a1_id, "_ChunkSizes", NC_INT, 3, GS_ncl_a1_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int GS_ncl_a2_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, GS_ncl_a2_id, "_ChunkSizes", NC_INT, 3, GS_ncl_a2_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int GS_ncl_a3_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, GS_ncl_a3_id, "_ChunkSizes", NC_INT, 3, GS_ncl_a3_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int GS_num_a1_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, GS_num_a1_id, "_ChunkSizes", NC_INT, 3, GS_num_a1_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int GS_num_a2_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, GS_num_a2_id, "_ChunkSizes", NC_INT, 3, GS_num_a2_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int GS_num_a3_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, GS_num_a3_id, "_ChunkSizes", NC_INT, 3, GS_num_a3_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int GS_pom_a1_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, GS_pom_a1_id, "_ChunkSizes", NC_INT, 3, GS_pom_a1_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int GS_so4_a1_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, GS_so4_a1_id, "_ChunkSizes", NC_INT, 3, GS_so4_a1_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int GS_so4_a2_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, GS_so4_a2_id, "_ChunkSizes", NC_INT, 3, GS_so4_a2_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int GS_so4_a3_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, GS_so4_a3_id, "_ChunkSizes", NC_INT, 3, GS_so4_a3_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int GS_soa_a1_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, GS_soa_a1_id, "_ChunkSizes", NC_INT, 3, GS_soa_a1_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int GS_soa_a2_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, GS_soa_a2_id, "_ChunkSizes", NC_INT, 3, GS_soa_a2_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int H2O2_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, H2O2_id, "_ChunkSizes", NC_INT, 4, H2O2_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int H2SO4_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, H2SO4_id, "_ChunkSizes", NC_INT, 4, H2SO4_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int H2SO4_sfgaex1_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, H2SO4_sfgaex1_id, "_ChunkSizes", NC_INT, 3, H2SO4_sfgaex1_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int H2SO4_sfnnuc1_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, H2SO4_sfnnuc1_id, "_ChunkSizes", NC_INT, 3, H2SO4_sfnnuc1_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int ICEFRAC_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, ICEFRAC_id, "_ChunkSizes", NC_INT, 3, ICEFRAC_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int ICIMR_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, ICIMR_id, "_ChunkSizes", NC_INT, 4, ICIMR_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int ICWMR_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, ICWMR_id, "_ChunkSizes", NC_INT, 4, ICWMR_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int KVH_ChunkSizes_att[4] = {1, 31, 96, 144} ;
    stat = nc_put_att_int(ncid, KVH_id, "_ChunkSizes", NC_INT, 4, KVH_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int KVM_ChunkSizes_att[4] = {1, 31, 96, 144} ;
    stat = nc_put_att_int(ncid, KVM_id, "_ChunkSizes", NC_INT, 4, KVM_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int LANDFRAC_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, LANDFRAC_id, "_ChunkSizes", NC_INT, 3, LANDFRAC_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int LCLOUD_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, LCLOUD_id, "_ChunkSizes", NC_INT, 4, LCLOUD_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int LHFLX_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, LHFLX_id, "_ChunkSizes", NC_INT, 3, LHFLX_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int LND_MBL_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, LND_MBL_id, "_ChunkSizes", NC_INT, 3, LND_MBL_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int LWCF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, LWCF_id, "_ChunkSizes", NC_INT, 3, LWCF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int NDROPCOL_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, NDROPCOL_id, "_ChunkSizes", NC_INT, 3, NDROPCOL_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int NDROPMIX_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, NDROPMIX_id, "_ChunkSizes", NC_INT, 4, NDROPMIX_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int NDROPSNK_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, NDROPSNK_id, "_ChunkSizes", NC_INT, 4, NDROPSNK_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int NDROPSRC_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, NDROPSRC_id, "_ChunkSizes", NC_INT, 4, NDROPSRC_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int NUMICE_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, NUMICE_id, "_ChunkSizes", NC_INT, 4, NUMICE_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int NUMLIQ_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, NUMLIQ_id, "_ChunkSizes", NC_INT, 4, NUMLIQ_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int OCNFRAC_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, OCNFRAC_id, "_ChunkSizes", NC_INT, 3, OCNFRAC_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int ODV_bc_a1_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, ODV_bc_a1_id, "_ChunkSizes", NC_INT, 3, ODV_bc_a1_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int ODV_dst_a1_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, ODV_dst_a1_id, "_ChunkSizes", NC_INT, 3, ODV_dst_a1_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int ODV_dst_a3_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, ODV_dst_a3_id, "_ChunkSizes", NC_INT, 3, ODV_dst_a3_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int ODV_ncl_a1_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, ODV_ncl_a1_id, "_ChunkSizes", NC_INT, 3, ODV_ncl_a1_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int ODV_ncl_a3_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, ODV_ncl_a3_id, "_ChunkSizes", NC_INT, 3, ODV_ncl_a3_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int ODV_pom_a1_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, ODV_pom_a1_id, "_ChunkSizes", NC_INT, 3, ODV_pom_a1_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int ODV_so4_a1_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, ODV_so4_a1_id, "_ChunkSizes", NC_INT, 3, ODV_so4_a1_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int ODV_soa_a1_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, ODV_soa_a1_id, "_ChunkSizes", NC_INT, 3, ODV_soa_a1_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int OMEGA_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, OMEGA_id, "_ChunkSizes", NC_INT, 4, OMEGA_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int OMEGAT_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, OMEGAT_id, "_ChunkSizes", NC_INT, 4, OMEGAT_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int ORO_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, ORO_id, "_ChunkSizes", NC_INT, 3, ORO_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int PBLH_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, PBLH_id, "_ChunkSizes", NC_INT, 3, PBLH_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int PCONVB_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, PCONVB_id, "_ChunkSizes", NC_INT, 3, PCONVB_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int PCONVT_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, PCONVT_id, "_ChunkSizes", NC_INT, 3, PCONVT_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int PHIS_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, PHIS_id, "_ChunkSizes", NC_INT, 3, PHIS_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int PRECC_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, PRECC_id, "_ChunkSizes", NC_INT, 3, PRECC_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int PRECCDZM_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, PRECCDZM_id, "_ChunkSizes", NC_INT, 3, PRECCDZM_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int PRECL_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, PRECL_id, "_ChunkSizes", NC_INT, 3, PRECL_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int PRECSC_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, PRECSC_id, "_ChunkSizes", NC_INT, 3, PRECSC_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int PRECSH_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, PRECSH_id, "_ChunkSizes", NC_INT, 3, PRECSH_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int PRECSL_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, PRECSL_id, "_ChunkSizes", NC_INT, 3, PRECSL_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int PRECT_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, PRECT_id, "_ChunkSizes", NC_INT, 3, PRECT_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int PS_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, PS_id, "_ChunkSizes", NC_INT, 3, PS_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int PSL_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, PSL_id, "_ChunkSizes", NC_INT, 3, PSL_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int Q_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, Q_id, "_ChunkSizes", NC_INT, 4, Q_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int QC_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, QC_id, "_ChunkSizes", NC_INT, 4, QC_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int QFLX_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, QFLX_id, "_ChunkSizes", NC_INT, 3, QFLX_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int QREFHT_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, QREFHT_id, "_ChunkSizes", NC_INT, 3, QREFHT_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int QRL_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, QRL_id, "_ChunkSizes", NC_INT, 4, QRL_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int QRS_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, QRS_id, "_ChunkSizes", NC_INT, 4, QRS_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int QT_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, QT_id, "_ChunkSizes", NC_INT, 4, QT_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int QTFLX_ChunkSizes_att[4] = {1, 31, 96, 144} ;
    stat = nc_put_att_int(ncid, QTFLX_id, "_ChunkSizes", NC_INT, 4, QTFLX_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int RAM1_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, RAM1_id, "_ChunkSizes", NC_INT, 3, RAM1_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int RELHUM_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, RELHUM_id, "_ChunkSizes", NC_INT, 4, RELHUM_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int RHREFHT_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, RHREFHT_id, "_ChunkSizes", NC_INT, 3, RHREFHT_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int SFCLDICE_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, SFCLDICE_id, "_ChunkSizes", NC_INT, 3, SFCLDICE_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int SFCLDLIQ_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, SFCLDLIQ_id, "_ChunkSizes", NC_INT, 3, SFCLDLIQ_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int SFI_ChunkSizes_att[4] = {1, 31, 96, 144} ;
    stat = nc_put_att_int(ncid, SFI_id, "_ChunkSizes", NC_INT, 4, SFI_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int SFNUMICE_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, SFNUMICE_id, "_ChunkSizes", NC_INT, 3, SFNUMICE_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int SFNUMLIQ_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, SFNUMLIQ_id, "_ChunkSizes", NC_INT, 3, SFNUMLIQ_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int SHFLX_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, SHFLX_id, "_ChunkSizes", NC_INT, 3, SHFLX_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int SL_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, SL_id, "_ChunkSizes", NC_INT, 4, SL_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int SLFLX_ChunkSizes_att[4] = {1, 31, 96, 144} ;
    stat = nc_put_att_int(ncid, SLFLX_id, "_ChunkSizes", NC_INT, 4, SLFLX_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int SLV_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, SLV_id, "_ChunkSizes", NC_INT, 4, SLV_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int SNOWHICE_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, SNOWHICE_id, "_ChunkSizes", NC_INT, 3, SNOWHICE_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int SNOWHLND_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, SNOWHLND_id, "_ChunkSizes", NC_INT, 3, SNOWHLND_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int SO2_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, SO2_id, "_ChunkSizes", NC_INT, 4, SO2_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int SO2_CLXF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, SO2_CLXF_id, "_ChunkSizes", NC_INT, 3, SO2_CLXF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int SO2_XFRC_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, SO2_XFRC_id, "_ChunkSizes", NC_INT, 4, SO2_XFRC_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int SOAG_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, SOAG_id, "_ChunkSizes", NC_INT, 4, SOAG_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int SOAG_sfgaex1_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, SOAG_sfgaex1_id, "_ChunkSizes", NC_INT, 3, SOAG_sfgaex1_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int SOLIN_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, SOLIN_id, "_ChunkSizes", NC_INT, 3, SOLIN_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int SPROD_ChunkSizes_att[4] = {1, 31, 96, 144} ;
    stat = nc_put_att_int(ncid, SPROD_id, "_ChunkSizes", NC_INT, 4, SPROD_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int SRFRAD_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, SRFRAD_id, "_ChunkSizes", NC_INT, 3, SRFRAD_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int SSAVIS_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, SSAVIS_id, "_ChunkSizes", NC_INT, 3, SSAVIS_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int SSTODXC_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, SSTODXC_id, "_ChunkSizes", NC_INT, 3, SSTODXC_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int SSTSFDRY_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, SSTSFDRY_id, "_ChunkSizes", NC_INT, 3, SSTSFDRY_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int SSTSFMBL_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, SSTSFMBL_id, "_ChunkSizes", NC_INT, 3, SSTSFMBL_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int SSTSFWET_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, SSTSFWET_id, "_ChunkSizes", NC_INT, 3, SSTSFWET_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int SWCF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, SWCF_id, "_ChunkSizes", NC_INT, 3, SWCF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int T_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, T_id, "_ChunkSizes", NC_INT, 4, T_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int TAUTMSX_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, TAUTMSX_id, "_ChunkSizes", NC_INT, 3, TAUTMSX_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int TAUTMSY_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, TAUTMSY_id, "_ChunkSizes", NC_INT, 3, TAUTMSY_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int TAUX_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, TAUX_id, "_ChunkSizes", NC_INT, 3, TAUX_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int TAUY_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, TAUY_id, "_ChunkSizes", NC_INT, 3, TAUY_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int TGCLDCWP_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, TGCLDCWP_id, "_ChunkSizes", NC_INT, 3, TGCLDCWP_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int TGCLDIWP_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, TGCLDIWP_id, "_ChunkSizes", NC_INT, 3, TGCLDIWP_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int TGCLDLWP_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, TGCLDLWP_id, "_ChunkSizes", NC_INT, 3, TGCLDLWP_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int TKE_ChunkSizes_att[4] = {1, 31, 96, 144} ;
    stat = nc_put_att_int(ncid, TKE_id, "_ChunkSizes", NC_INT, 4, TKE_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int TMQ_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, TMQ_id, "_ChunkSizes", NC_INT, 3, TMQ_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int TREFHT_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, TREFHT_id, "_ChunkSizes", NC_INT, 3, TREFHT_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int TREFMNAV_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, TREFMNAV_id, "_ChunkSizes", NC_INT, 3, TREFMNAV_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int TREFMXAV_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, TREFMXAV_id, "_ChunkSizes", NC_INT, 3, TREFMXAV_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int TROP_FD_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, TROP_FD_id, "_ChunkSizes", NC_INT, 3, TROP_FD_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int TROP_P_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, TROP_P_id, "_ChunkSizes", NC_INT, 3, TROP_P_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int TROP_PD_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, TROP_PD_id, "_ChunkSizes", NC_INT, 4, TROP_PD_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int TROP_T_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, TROP_T_id, "_ChunkSizes", NC_INT, 3, TROP_T_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int TROP_Z_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, TROP_Z_id, "_ChunkSizes", NC_INT, 3, TROP_Z_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int TS_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, TS_id, "_ChunkSizes", NC_INT, 3, TS_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int TSMN_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, TSMN_id, "_ChunkSizes", NC_INT, 3, TSMN_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int TSMX_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, TSMX_id, "_ChunkSizes", NC_INT, 3, TSMX_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int U_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, U_id, "_ChunkSizes", NC_INT, 4, U_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int UFLX_ChunkSizes_att[4] = {1, 31, 96, 144} ;
    stat = nc_put_att_int(ncid, UFLX_id, "_ChunkSizes", NC_INT, 4, UFLX_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int US_ChunkSizes_att[4] = {1, 30, 95, 144} ;
    stat = nc_put_att_int(ncid, US_id, "_ChunkSizes", NC_INT, 4, US_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int UU_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, UU_id, "_ChunkSizes", NC_INT, 4, UU_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int V_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, V_id, "_ChunkSizes", NC_INT, 4, V_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int VD01_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, VD01_id, "_ChunkSizes", NC_INT, 4, VD01_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int VFLX_ChunkSizes_att[4] = {1, 31, 96, 144} ;
    stat = nc_put_att_int(ncid, VFLX_id, "_ChunkSizes", NC_INT, 4, VFLX_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int VQ_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, VQ_id, "_ChunkSizes", NC_INT, 4, VQ_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int VS_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, VS_id, "_ChunkSizes", NC_INT, 4, VS_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int VT_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, VT_id, "_ChunkSizes", NC_INT, 4, VT_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int VU_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, VU_id, "_ChunkSizes", NC_INT, 4, VU_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int VV_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, VV_id, "_ChunkSizes", NC_INT, 4, VV_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int WGUSTD_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, WGUSTD_id, "_ChunkSizes", NC_INT, 3, WGUSTD_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int WTKE_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, WTKE_id, "_ChunkSizes", NC_INT, 4, WTKE_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int XPH_LWC_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, XPH_LWC_id, "_ChunkSizes", NC_INT, 4, XPH_LWC_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int Z3_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, Z3_id, "_ChunkSizes", NC_INT, 4, Z3_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int airFV_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, airFV_id, "_ChunkSizes", NC_INT, 3, airFV_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int bc_a1_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, bc_a1_id, "_ChunkSizes", NC_INT, 4, bc_a1_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int bc_a1DDF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, bc_a1DDF_id, "_ChunkSizes", NC_INT, 3, bc_a1DDF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int bc_a1GVF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, bc_a1GVF_id, "_ChunkSizes", NC_INT, 3, bc_a1GVF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int bc_a1SFSBC_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, bc_a1SFSBC_id, "_ChunkSizes", NC_INT, 3, bc_a1SFSBC_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int bc_a1SFSBS_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, bc_a1SFSBS_id, "_ChunkSizes", NC_INT, 3, bc_a1SFSBS_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int bc_a1SFSIC_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, bc_a1SFSIC_id, "_ChunkSizes", NC_INT, 3, bc_a1SFSIC_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int bc_a1SFSIS_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, bc_a1SFSIS_id, "_ChunkSizes", NC_INT, 3, bc_a1SFSIS_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int bc_a1SFWET_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, bc_a1SFWET_id, "_ChunkSizes", NC_INT, 3, bc_a1SFWET_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int bc_a1TBF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, bc_a1TBF_id, "_ChunkSizes", NC_INT, 3, bc_a1TBF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int bc_a1_CLXF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, bc_a1_CLXF_id, "_ChunkSizes", NC_INT, 3, bc_a1_CLXF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int bc_a1_XFRC_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, bc_a1_XFRC_id, "_ChunkSizes", NC_INT, 4, bc_a1_XFRC_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int bc_c1_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, bc_c1_id, "_ChunkSizes", NC_INT, 4, bc_c1_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int bc_c1DDF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, bc_c1DDF_id, "_ChunkSizes", NC_INT, 3, bc_c1DDF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int bc_c1GVF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, bc_c1GVF_id, "_ChunkSizes", NC_INT, 3, bc_c1GVF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int bc_c1SFSBC_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, bc_c1SFSBC_id, "_ChunkSizes", NC_INT, 3, bc_c1SFSBC_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int bc_c1SFSBS_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, bc_c1SFSBS_id, "_ChunkSizes", NC_INT, 3, bc_c1SFSBS_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int bc_c1SFSIC_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, bc_c1SFSIC_id, "_ChunkSizes", NC_INT, 3, bc_c1SFSIC_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int bc_c1SFSIS_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, bc_c1SFSIS_id, "_ChunkSizes", NC_INT, 3, bc_c1SFSIS_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int bc_c1SFWET_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, bc_c1SFWET_id, "_ChunkSizes", NC_INT, 3, bc_c1SFWET_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int bc_c1TBF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, bc_c1TBF_id, "_ChunkSizes", NC_INT, 3, bc_c1TBF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int chem_trop_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, chem_trop_id, "_ChunkSizes", NC_INT, 4, chem_trop_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int chem_trop_tropop_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, chem_trop_tropop_id, "_ChunkSizes", NC_INT, 4, chem_trop_tropop_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int dgnd_a01_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, dgnd_a01_id, "_ChunkSizes", NC_INT, 4, dgnd_a01_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int dgnd_a02_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, dgnd_a02_id, "_ChunkSizes", NC_INT, 4, dgnd_a02_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int dgnd_a03_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, dgnd_a03_id, "_ChunkSizes", NC_INT, 4, dgnd_a03_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int dgnw_a01_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, dgnw_a01_id, "_ChunkSizes", NC_INT, 4, dgnw_a01_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int dgnw_a02_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, dgnw_a02_id, "_ChunkSizes", NC_INT, 4, dgnw_a02_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int dgnw_a03_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, dgnw_a03_id, "_ChunkSizes", NC_INT, 4, dgnw_a03_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int dst_a1_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, dst_a1_id, "_ChunkSizes", NC_INT, 4, dst_a1_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int dst_a1DDF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, dst_a1DDF_id, "_ChunkSizes", NC_INT, 3, dst_a1DDF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int dst_a1GVF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, dst_a1GVF_id, "_ChunkSizes", NC_INT, 3, dst_a1GVF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int dst_a1SF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, dst_a1SF_id, "_ChunkSizes", NC_INT, 3, dst_a1SF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int dst_a1SFSBC_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, dst_a1SFSBC_id, "_ChunkSizes", NC_INT, 3, dst_a1SFSBC_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int dst_a1SFSBS_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, dst_a1SFSBS_id, "_ChunkSizes", NC_INT, 3, dst_a1SFSBS_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int dst_a1SFSIC_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, dst_a1SFSIC_id, "_ChunkSizes", NC_INT, 3, dst_a1SFSIC_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int dst_a1SFSIS_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, dst_a1SFSIS_id, "_ChunkSizes", NC_INT, 3, dst_a1SFSIS_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int dst_a1SFWET_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, dst_a1SFWET_id, "_ChunkSizes", NC_INT, 3, dst_a1SFWET_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int dst_a1TBF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, dst_a1TBF_id, "_ChunkSizes", NC_INT, 3, dst_a1TBF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int dst_a3_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, dst_a3_id, "_ChunkSizes", NC_INT, 4, dst_a3_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int dst_a3DDF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, dst_a3DDF_id, "_ChunkSizes", NC_INT, 3, dst_a3DDF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int dst_a3GVF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, dst_a3GVF_id, "_ChunkSizes", NC_INT, 3, dst_a3GVF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int dst_a3SF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, dst_a3SF_id, "_ChunkSizes", NC_INT, 3, dst_a3SF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int dst_a3SFSBC_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, dst_a3SFSBC_id, "_ChunkSizes", NC_INT, 3, dst_a3SFSBC_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int dst_a3SFSBS_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, dst_a3SFSBS_id, "_ChunkSizes", NC_INT, 3, dst_a3SFSBS_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int dst_a3SFSIC_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, dst_a3SFSIC_id, "_ChunkSizes", NC_INT, 3, dst_a3SFSIC_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int dst_a3SFSIS_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, dst_a3SFSIS_id, "_ChunkSizes", NC_INT, 3, dst_a3SFSIS_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int dst_a3SFWET_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, dst_a3SFWET_id, "_ChunkSizes", NC_INT, 3, dst_a3SFWET_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int dst_a3TBF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, dst_a3TBF_id, "_ChunkSizes", NC_INT, 3, dst_a3TBF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int dst_c1_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, dst_c1_id, "_ChunkSizes", NC_INT, 4, dst_c1_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int dst_c1DDF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, dst_c1DDF_id, "_ChunkSizes", NC_INT, 3, dst_c1DDF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int dst_c1GVF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, dst_c1GVF_id, "_ChunkSizes", NC_INT, 3, dst_c1GVF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int dst_c1SFSBC_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, dst_c1SFSBC_id, "_ChunkSizes", NC_INT, 3, dst_c1SFSBC_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int dst_c1SFSBS_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, dst_c1SFSBS_id, "_ChunkSizes", NC_INT, 3, dst_c1SFSBS_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int dst_c1SFSIC_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, dst_c1SFSIC_id, "_ChunkSizes", NC_INT, 3, dst_c1SFSIC_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int dst_c1SFSIS_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, dst_c1SFSIS_id, "_ChunkSizes", NC_INT, 3, dst_c1SFSIS_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int dst_c1SFWET_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, dst_c1SFWET_id, "_ChunkSizes", NC_INT, 3, dst_c1SFWET_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int dst_c1TBF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, dst_c1TBF_id, "_ChunkSizes", NC_INT, 3, dst_c1TBF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int dst_c3_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, dst_c3_id, "_ChunkSizes", NC_INT, 4, dst_c3_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int dst_c3DDF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, dst_c3DDF_id, "_ChunkSizes", NC_INT, 3, dst_c3DDF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int dst_c3GVF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, dst_c3GVF_id, "_ChunkSizes", NC_INT, 3, dst_c3GVF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int dst_c3SFSBC_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, dst_c3SFSBC_id, "_ChunkSizes", NC_INT, 3, dst_c3SFSBC_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int dst_c3SFSBS_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, dst_c3SFSBS_id, "_ChunkSizes", NC_INT, 3, dst_c3SFSBS_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int dst_c3SFSIC_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, dst_c3SFSIC_id, "_ChunkSizes", NC_INT, 3, dst_c3SFSIC_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int dst_c3SFSIS_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, dst_c3SFSIS_id, "_ChunkSizes", NC_INT, 3, dst_c3SFSIS_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int dst_c3SFWET_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, dst_c3SFWET_id, "_ChunkSizes", NC_INT, 3, dst_c3SFWET_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int dst_c3TBF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, dst_c3TBF_id, "_ChunkSizes", NC_INT, 3, dst_c3TBF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int ncl_a1_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, ncl_a1_id, "_ChunkSizes", NC_INT, 4, ncl_a1_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int ncl_a1DDF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, ncl_a1DDF_id, "_ChunkSizes", NC_INT, 3, ncl_a1DDF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int ncl_a1GVF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, ncl_a1GVF_id, "_ChunkSizes", NC_INT, 3, ncl_a1GVF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int ncl_a1SF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, ncl_a1SF_id, "_ChunkSizes", NC_INT, 3, ncl_a1SF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int ncl_a1SFSBC_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, ncl_a1SFSBC_id, "_ChunkSizes", NC_INT, 3, ncl_a1SFSBC_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int ncl_a1SFSBS_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, ncl_a1SFSBS_id, "_ChunkSizes", NC_INT, 3, ncl_a1SFSBS_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int ncl_a1SFSIC_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, ncl_a1SFSIC_id, "_ChunkSizes", NC_INT, 3, ncl_a1SFSIC_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int ncl_a1SFSIS_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, ncl_a1SFSIS_id, "_ChunkSizes", NC_INT, 3, ncl_a1SFSIS_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int ncl_a1SFWET_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, ncl_a1SFWET_id, "_ChunkSizes", NC_INT, 3, ncl_a1SFWET_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int ncl_a1TBF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, ncl_a1TBF_id, "_ChunkSizes", NC_INT, 3, ncl_a1TBF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int ncl_a1_sfcoag1_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, ncl_a1_sfcoag1_id, "_ChunkSizes", NC_INT, 3, ncl_a1_sfcoag1_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int ncl_a1_sfcsiz3_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, ncl_a1_sfcsiz3_id, "_ChunkSizes", NC_INT, 3, ncl_a1_sfcsiz3_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int ncl_a1_sfcsiz4_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, ncl_a1_sfcsiz4_id, "_ChunkSizes", NC_INT, 3, ncl_a1_sfcsiz4_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int ncl_a1_sfgaex2_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, ncl_a1_sfgaex2_id, "_ChunkSizes", NC_INT, 3, ncl_a1_sfgaex2_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int ncl_a2_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, ncl_a2_id, "_ChunkSizes", NC_INT, 4, ncl_a2_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int ncl_a2DDF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, ncl_a2DDF_id, "_ChunkSizes", NC_INT, 3, ncl_a2DDF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int ncl_a2GVF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, ncl_a2GVF_id, "_ChunkSizes", NC_INT, 3, ncl_a2GVF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int ncl_a2SF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, ncl_a2SF_id, "_ChunkSizes", NC_INT, 3, ncl_a2SF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int ncl_a2SFSBC_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, ncl_a2SFSBC_id, "_ChunkSizes", NC_INT, 3, ncl_a2SFSBC_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int ncl_a2SFSBS_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, ncl_a2SFSBS_id, "_ChunkSizes", NC_INT, 3, ncl_a2SFSBS_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int ncl_a2SFSIC_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, ncl_a2SFSIC_id, "_ChunkSizes", NC_INT, 3, ncl_a2SFSIC_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int ncl_a2SFSIS_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, ncl_a2SFSIS_id, "_ChunkSizes", NC_INT, 3, ncl_a2SFSIS_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int ncl_a2SFWET_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, ncl_a2SFWET_id, "_ChunkSizes", NC_INT, 3, ncl_a2SFWET_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int ncl_a2TBF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, ncl_a2TBF_id, "_ChunkSizes", NC_INT, 3, ncl_a2TBF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int ncl_a2_sfcoag1_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, ncl_a2_sfcoag1_id, "_ChunkSizes", NC_INT, 3, ncl_a2_sfcoag1_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int ncl_a2_sfcsiz3_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, ncl_a2_sfcsiz3_id, "_ChunkSizes", NC_INT, 3, ncl_a2_sfcsiz3_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int ncl_a2_sfcsiz4_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, ncl_a2_sfcsiz4_id, "_ChunkSizes", NC_INT, 3, ncl_a2_sfcsiz4_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int ncl_a2_sfgaex2_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, ncl_a2_sfgaex2_id, "_ChunkSizes", NC_INT, 3, ncl_a2_sfgaex2_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int ncl_a3_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, ncl_a3_id, "_ChunkSizes", NC_INT, 4, ncl_a3_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int ncl_a3DDF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, ncl_a3DDF_id, "_ChunkSizes", NC_INT, 3, ncl_a3DDF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int ncl_a3GVF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, ncl_a3GVF_id, "_ChunkSizes", NC_INT, 3, ncl_a3GVF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int ncl_a3SF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, ncl_a3SF_id, "_ChunkSizes", NC_INT, 3, ncl_a3SF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int ncl_a3SFSBC_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, ncl_a3SFSBC_id, "_ChunkSizes", NC_INT, 3, ncl_a3SFSBC_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int ncl_a3SFSBS_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, ncl_a3SFSBS_id, "_ChunkSizes", NC_INT, 3, ncl_a3SFSBS_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int ncl_a3SFSIC_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, ncl_a3SFSIC_id, "_ChunkSizes", NC_INT, 3, ncl_a3SFSIC_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int ncl_a3SFSIS_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, ncl_a3SFSIS_id, "_ChunkSizes", NC_INT, 3, ncl_a3SFSIS_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int ncl_a3SFWET_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, ncl_a3SFWET_id, "_ChunkSizes", NC_INT, 3, ncl_a3SFWET_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int ncl_a3TBF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, ncl_a3TBF_id, "_ChunkSizes", NC_INT, 3, ncl_a3TBF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int ncl_c1_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, ncl_c1_id, "_ChunkSizes", NC_INT, 4, ncl_c1_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int ncl_c1DDF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, ncl_c1DDF_id, "_ChunkSizes", NC_INT, 3, ncl_c1DDF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int ncl_c1GVF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, ncl_c1GVF_id, "_ChunkSizes", NC_INT, 3, ncl_c1GVF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int ncl_c1SFSBC_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, ncl_c1SFSBC_id, "_ChunkSizes", NC_INT, 3, ncl_c1SFSBC_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int ncl_c1SFSBS_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, ncl_c1SFSBS_id, "_ChunkSizes", NC_INT, 3, ncl_c1SFSBS_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int ncl_c1SFSIC_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, ncl_c1SFSIC_id, "_ChunkSizes", NC_INT, 3, ncl_c1SFSIC_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int ncl_c1SFSIS_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, ncl_c1SFSIS_id, "_ChunkSizes", NC_INT, 3, ncl_c1SFSIS_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int ncl_c1SFWET_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, ncl_c1SFWET_id, "_ChunkSizes", NC_INT, 3, ncl_c1SFWET_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int ncl_c1TBF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, ncl_c1TBF_id, "_ChunkSizes", NC_INT, 3, ncl_c1TBF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int ncl_c1_sfcsiz3_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, ncl_c1_sfcsiz3_id, "_ChunkSizes", NC_INT, 3, ncl_c1_sfcsiz3_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int ncl_c1_sfcsiz4_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, ncl_c1_sfcsiz4_id, "_ChunkSizes", NC_INT, 3, ncl_c1_sfcsiz4_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int ncl_c1_sfgaex2_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, ncl_c1_sfgaex2_id, "_ChunkSizes", NC_INT, 3, ncl_c1_sfgaex2_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int ncl_c2_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, ncl_c2_id, "_ChunkSizes", NC_INT, 4, ncl_c2_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int ncl_c2DDF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, ncl_c2DDF_id, "_ChunkSizes", NC_INT, 3, ncl_c2DDF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int ncl_c2GVF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, ncl_c2GVF_id, "_ChunkSizes", NC_INT, 3, ncl_c2GVF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int ncl_c2SFSBC_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, ncl_c2SFSBC_id, "_ChunkSizes", NC_INT, 3, ncl_c2SFSBC_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int ncl_c2SFSBS_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, ncl_c2SFSBS_id, "_ChunkSizes", NC_INT, 3, ncl_c2SFSBS_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int ncl_c2SFSIC_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, ncl_c2SFSIC_id, "_ChunkSizes", NC_INT, 3, ncl_c2SFSIC_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int ncl_c2SFSIS_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, ncl_c2SFSIS_id, "_ChunkSizes", NC_INT, 3, ncl_c2SFSIS_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int ncl_c2SFWET_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, ncl_c2SFWET_id, "_ChunkSizes", NC_INT, 3, ncl_c2SFWET_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int ncl_c2TBF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, ncl_c2TBF_id, "_ChunkSizes", NC_INT, 3, ncl_c2TBF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int ncl_c2_sfcsiz3_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, ncl_c2_sfcsiz3_id, "_ChunkSizes", NC_INT, 3, ncl_c2_sfcsiz3_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int ncl_c2_sfcsiz4_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, ncl_c2_sfcsiz4_id, "_ChunkSizes", NC_INT, 3, ncl_c2_sfcsiz4_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int ncl_c2_sfgaex2_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, ncl_c2_sfgaex2_id, "_ChunkSizes", NC_INT, 3, ncl_c2_sfgaex2_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int ncl_c3_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, ncl_c3_id, "_ChunkSizes", NC_INT, 4, ncl_c3_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int ncl_c3DDF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, ncl_c3DDF_id, "_ChunkSizes", NC_INT, 3, ncl_c3DDF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int ncl_c3GVF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, ncl_c3GVF_id, "_ChunkSizes", NC_INT, 3, ncl_c3GVF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int ncl_c3SFSBC_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, ncl_c3SFSBC_id, "_ChunkSizes", NC_INT, 3, ncl_c3SFSBC_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int ncl_c3SFSBS_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, ncl_c3SFSBS_id, "_ChunkSizes", NC_INT, 3, ncl_c3SFSBS_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int ncl_c3SFSIC_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, ncl_c3SFSIC_id, "_ChunkSizes", NC_INT, 3, ncl_c3SFSIC_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int ncl_c3SFSIS_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, ncl_c3SFSIS_id, "_ChunkSizes", NC_INT, 3, ncl_c3SFSIS_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int ncl_c3SFWET_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, ncl_c3SFWET_id, "_ChunkSizes", NC_INT, 3, ncl_c3SFWET_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int ncl_c3TBF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, ncl_c3TBF_id, "_ChunkSizes", NC_INT, 3, ncl_c3TBF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int num_a1_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, num_a1_id, "_ChunkSizes", NC_INT, 4, num_a1_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int num_a1DDF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, num_a1DDF_id, "_ChunkSizes", NC_INT, 3, num_a1DDF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int num_a1GVF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, num_a1GVF_id, "_ChunkSizes", NC_INT, 3, num_a1GVF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int num_a1SFSBC_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, num_a1SFSBC_id, "_ChunkSizes", NC_INT, 3, num_a1SFSBC_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int num_a1SFSBS_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, num_a1SFSBS_id, "_ChunkSizes", NC_INT, 3, num_a1SFSBS_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int num_a1SFSIC_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, num_a1SFSIC_id, "_ChunkSizes", NC_INT, 3, num_a1SFSIC_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int num_a1SFSIS_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, num_a1SFSIS_id, "_ChunkSizes", NC_INT, 3, num_a1SFSIS_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int num_a1SFWET_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, num_a1SFWET_id, "_ChunkSizes", NC_INT, 3, num_a1SFWET_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int num_a1TBF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, num_a1TBF_id, "_ChunkSizes", NC_INT, 3, num_a1TBF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int num_a1_CLXF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, num_a1_CLXF_id, "_ChunkSizes", NC_INT, 3, num_a1_CLXF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int num_a1_XFRC_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, num_a1_XFRC_id, "_ChunkSizes", NC_INT, 4, num_a1_XFRC_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int num_a1_sfcoag1_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, num_a1_sfcoag1_id, "_ChunkSizes", NC_INT, 3, num_a1_sfcoag1_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int num_a1_sfcsiz1_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, num_a1_sfcsiz1_id, "_ChunkSizes", NC_INT, 3, num_a1_sfcsiz1_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int num_a1_sfcsiz2_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, num_a1_sfcsiz2_id, "_ChunkSizes", NC_INT, 3, num_a1_sfcsiz2_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int num_a1_sfcsiz3_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, num_a1_sfcsiz3_id, "_ChunkSizes", NC_INT, 3, num_a1_sfcsiz3_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int num_a1_sfcsiz4_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, num_a1_sfcsiz4_id, "_ChunkSizes", NC_INT, 3, num_a1_sfcsiz4_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int num_a1_sfgaex2_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, num_a1_sfgaex2_id, "_ChunkSizes", NC_INT, 3, num_a1_sfgaex2_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int num_a2_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, num_a2_id, "_ChunkSizes", NC_INT, 4, num_a2_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int num_a2DDF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, num_a2DDF_id, "_ChunkSizes", NC_INT, 3, num_a2DDF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int num_a2GVF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, num_a2GVF_id, "_ChunkSizes", NC_INT, 3, num_a2GVF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int num_a2SFSBC_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, num_a2SFSBC_id, "_ChunkSizes", NC_INT, 3, num_a2SFSBC_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int num_a2SFSBS_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, num_a2SFSBS_id, "_ChunkSizes", NC_INT, 3, num_a2SFSBS_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int num_a2SFSIC_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, num_a2SFSIC_id, "_ChunkSizes", NC_INT, 3, num_a2SFSIC_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int num_a2SFSIS_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, num_a2SFSIS_id, "_ChunkSizes", NC_INT, 3, num_a2SFSIS_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int num_a2SFWET_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, num_a2SFWET_id, "_ChunkSizes", NC_INT, 3, num_a2SFWET_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int num_a2TBF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, num_a2TBF_id, "_ChunkSizes", NC_INT, 3, num_a2TBF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int num_a2_CLXF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, num_a2_CLXF_id, "_ChunkSizes", NC_INT, 3, num_a2_CLXF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int num_a2_XFRC_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, num_a2_XFRC_id, "_ChunkSizes", NC_INT, 4, num_a2_XFRC_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int num_a2_sfcoag1_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, num_a2_sfcoag1_id, "_ChunkSizes", NC_INT, 3, num_a2_sfcoag1_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int num_a2_sfcsiz1_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, num_a2_sfcsiz1_id, "_ChunkSizes", NC_INT, 3, num_a2_sfcsiz1_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int num_a2_sfcsiz2_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, num_a2_sfcsiz2_id, "_ChunkSizes", NC_INT, 3, num_a2_sfcsiz2_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int num_a2_sfcsiz3_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, num_a2_sfcsiz3_id, "_ChunkSizes", NC_INT, 3, num_a2_sfcsiz3_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int num_a2_sfcsiz4_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, num_a2_sfcsiz4_id, "_ChunkSizes", NC_INT, 3, num_a2_sfcsiz4_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int num_a2_sfgaex2_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, num_a2_sfgaex2_id, "_ChunkSizes", NC_INT, 3, num_a2_sfgaex2_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int num_a2_sfnnuc1_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, num_a2_sfnnuc1_id, "_ChunkSizes", NC_INT, 3, num_a2_sfnnuc1_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int num_a3_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, num_a3_id, "_ChunkSizes", NC_INT, 4, num_a3_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int num_a3DDF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, num_a3DDF_id, "_ChunkSizes", NC_INT, 3, num_a3DDF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int num_a3GVF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, num_a3GVF_id, "_ChunkSizes", NC_INT, 3, num_a3GVF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int num_a3SFSBC_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, num_a3SFSBC_id, "_ChunkSizes", NC_INT, 3, num_a3SFSBC_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int num_a3SFSBS_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, num_a3SFSBS_id, "_ChunkSizes", NC_INT, 3, num_a3SFSBS_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int num_a3SFSIC_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, num_a3SFSIC_id, "_ChunkSizes", NC_INT, 3, num_a3SFSIC_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int num_a3SFSIS_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, num_a3SFSIS_id, "_ChunkSizes", NC_INT, 3, num_a3SFSIS_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int num_a3SFWET_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, num_a3SFWET_id, "_ChunkSizes", NC_INT, 3, num_a3SFWET_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int num_a3TBF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, num_a3TBF_id, "_ChunkSizes", NC_INT, 3, num_a3TBF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int num_a3_sfcsiz1_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, num_a3_sfcsiz1_id, "_ChunkSizes", NC_INT, 3, num_a3_sfcsiz1_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int num_a3_sfcsiz2_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, num_a3_sfcsiz2_id, "_ChunkSizes", NC_INT, 3, num_a3_sfcsiz2_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int num_c1_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, num_c1_id, "_ChunkSizes", NC_INT, 4, num_c1_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int num_c1DDF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, num_c1DDF_id, "_ChunkSizes", NC_INT, 3, num_c1DDF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int num_c1GVF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, num_c1GVF_id, "_ChunkSizes", NC_INT, 3, num_c1GVF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int num_c1SFSBC_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, num_c1SFSBC_id, "_ChunkSizes", NC_INT, 3, num_c1SFSBC_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int num_c1SFSBS_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, num_c1SFSBS_id, "_ChunkSizes", NC_INT, 3, num_c1SFSBS_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int num_c1SFSIC_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, num_c1SFSIC_id, "_ChunkSizes", NC_INT, 3, num_c1SFSIC_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int num_c1SFSIS_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, num_c1SFSIS_id, "_ChunkSizes", NC_INT, 3, num_c1SFSIS_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int num_c1SFWET_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, num_c1SFWET_id, "_ChunkSizes", NC_INT, 3, num_c1SFWET_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int num_c1TBF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, num_c1TBF_id, "_ChunkSizes", NC_INT, 3, num_c1TBF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int num_c1_sfcsiz1_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, num_c1_sfcsiz1_id, "_ChunkSizes", NC_INT, 3, num_c1_sfcsiz1_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int num_c1_sfcsiz2_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, num_c1_sfcsiz2_id, "_ChunkSizes", NC_INT, 3, num_c1_sfcsiz2_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int num_c1_sfcsiz3_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, num_c1_sfcsiz3_id, "_ChunkSizes", NC_INT, 3, num_c1_sfcsiz3_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int num_c1_sfcsiz4_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, num_c1_sfcsiz4_id, "_ChunkSizes", NC_INT, 3, num_c1_sfcsiz4_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int num_c1_sfgaex2_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, num_c1_sfgaex2_id, "_ChunkSizes", NC_INT, 3, num_c1_sfgaex2_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int num_c2_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, num_c2_id, "_ChunkSizes", NC_INT, 4, num_c2_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int num_c2DDF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, num_c2DDF_id, "_ChunkSizes", NC_INT, 3, num_c2DDF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int num_c2GVF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, num_c2GVF_id, "_ChunkSizes", NC_INT, 3, num_c2GVF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int num_c2SFSBC_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, num_c2SFSBC_id, "_ChunkSizes", NC_INT, 3, num_c2SFSBC_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int num_c2SFSBS_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, num_c2SFSBS_id, "_ChunkSizes", NC_INT, 3, num_c2SFSBS_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int num_c2SFSIC_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, num_c2SFSIC_id, "_ChunkSizes", NC_INT, 3, num_c2SFSIC_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int num_c2SFSIS_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, num_c2SFSIS_id, "_ChunkSizes", NC_INT, 3, num_c2SFSIS_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int num_c2SFWET_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, num_c2SFWET_id, "_ChunkSizes", NC_INT, 3, num_c2SFWET_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int num_c2TBF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, num_c2TBF_id, "_ChunkSizes", NC_INT, 3, num_c2TBF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int num_c2_sfcsiz1_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, num_c2_sfcsiz1_id, "_ChunkSizes", NC_INT, 3, num_c2_sfcsiz1_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int num_c2_sfcsiz2_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, num_c2_sfcsiz2_id, "_ChunkSizes", NC_INT, 3, num_c2_sfcsiz2_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int num_c2_sfcsiz3_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, num_c2_sfcsiz3_id, "_ChunkSizes", NC_INT, 3, num_c2_sfcsiz3_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int num_c2_sfcsiz4_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, num_c2_sfcsiz4_id, "_ChunkSizes", NC_INT, 3, num_c2_sfcsiz4_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int num_c2_sfgaex2_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, num_c2_sfgaex2_id, "_ChunkSizes", NC_INT, 3, num_c2_sfgaex2_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int num_c3_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, num_c3_id, "_ChunkSizes", NC_INT, 4, num_c3_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int num_c3DDF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, num_c3DDF_id, "_ChunkSizes", NC_INT, 3, num_c3DDF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int num_c3GVF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, num_c3GVF_id, "_ChunkSizes", NC_INT, 3, num_c3GVF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int num_c3SFSBC_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, num_c3SFSBC_id, "_ChunkSizes", NC_INT, 3, num_c3SFSBC_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int num_c3SFSBS_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, num_c3SFSBS_id, "_ChunkSizes", NC_INT, 3, num_c3SFSBS_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int num_c3SFSIC_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, num_c3SFSIC_id, "_ChunkSizes", NC_INT, 3, num_c3SFSIC_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int num_c3SFSIS_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, num_c3SFSIS_id, "_ChunkSizes", NC_INT, 3, num_c3SFSIS_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int num_c3SFWET_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, num_c3SFWET_id, "_ChunkSizes", NC_INT, 3, num_c3SFWET_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int num_c3TBF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, num_c3TBF_id, "_ChunkSizes", NC_INT, 3, num_c3TBF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int num_c3_sfcsiz1_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, num_c3_sfcsiz1_id, "_ChunkSizes", NC_INT, 3, num_c3_sfcsiz1_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int num_c3_sfcsiz2_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, num_c3_sfcsiz2_id, "_ChunkSizes", NC_INT, 3, num_c3_sfcsiz2_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int pom_a1_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, pom_a1_id, "_ChunkSizes", NC_INT, 4, pom_a1_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int pom_a1DDF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, pom_a1DDF_id, "_ChunkSizes", NC_INT, 3, pom_a1DDF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int pom_a1GVF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, pom_a1GVF_id, "_ChunkSizes", NC_INT, 3, pom_a1GVF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int pom_a1SFSBC_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, pom_a1SFSBC_id, "_ChunkSizes", NC_INT, 3, pom_a1SFSBC_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int pom_a1SFSBS_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, pom_a1SFSBS_id, "_ChunkSizes", NC_INT, 3, pom_a1SFSBS_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int pom_a1SFSIC_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, pom_a1SFSIC_id, "_ChunkSizes", NC_INT, 3, pom_a1SFSIC_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int pom_a1SFSIS_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, pom_a1SFSIS_id, "_ChunkSizes", NC_INT, 3, pom_a1SFSIS_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int pom_a1SFWET_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, pom_a1SFWET_id, "_ChunkSizes", NC_INT, 3, pom_a1SFWET_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int pom_a1TBF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, pom_a1TBF_id, "_ChunkSizes", NC_INT, 3, pom_a1TBF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int pom_a1_CLXF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, pom_a1_CLXF_id, "_ChunkSizes", NC_INT, 3, pom_a1_CLXF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int pom_a1_XFRC_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, pom_a1_XFRC_id, "_ChunkSizes", NC_INT, 4, pom_a1_XFRC_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int pom_c1_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, pom_c1_id, "_ChunkSizes", NC_INT, 4, pom_c1_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int pom_c1DDF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, pom_c1DDF_id, "_ChunkSizes", NC_INT, 3, pom_c1DDF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int pom_c1GVF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, pom_c1GVF_id, "_ChunkSizes", NC_INT, 3, pom_c1GVF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int pom_c1SFSBC_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, pom_c1SFSBC_id, "_ChunkSizes", NC_INT, 3, pom_c1SFSBC_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int pom_c1SFSBS_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, pom_c1SFSBS_id, "_ChunkSizes", NC_INT, 3, pom_c1SFSBS_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int pom_c1SFSIC_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, pom_c1SFSIC_id, "_ChunkSizes", NC_INT, 3, pom_c1SFSIC_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int pom_c1SFSIS_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, pom_c1SFSIS_id, "_ChunkSizes", NC_INT, 3, pom_c1SFSIS_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int pom_c1SFWET_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, pom_c1SFWET_id, "_ChunkSizes", NC_INT, 3, pom_c1SFWET_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int pom_c1TBF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, pom_c1TBF_id, "_ChunkSizes", NC_INT, 3, pom_c1TBF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int so4_a1_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, so4_a1_id, "_ChunkSizes", NC_INT, 4, so4_a1_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int so4_a1DDF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, so4_a1DDF_id, "_ChunkSizes", NC_INT, 3, so4_a1DDF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int so4_a1GVF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, so4_a1GVF_id, "_ChunkSizes", NC_INT, 3, so4_a1GVF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int so4_a1SFSBC_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, so4_a1SFSBC_id, "_ChunkSizes", NC_INT, 3, so4_a1SFSBC_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int so4_a1SFSBS_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, so4_a1SFSBS_id, "_ChunkSizes", NC_INT, 3, so4_a1SFSBS_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int so4_a1SFSIC_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, so4_a1SFSIC_id, "_ChunkSizes", NC_INT, 3, so4_a1SFSIC_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int so4_a1SFSIS_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, so4_a1SFSIS_id, "_ChunkSizes", NC_INT, 3, so4_a1SFSIS_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int so4_a1SFWET_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, so4_a1SFWET_id, "_ChunkSizes", NC_INT, 3, so4_a1SFWET_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int so4_a1TBF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, so4_a1TBF_id, "_ChunkSizes", NC_INT, 3, so4_a1TBF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int so4_a1_CLXF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, so4_a1_CLXF_id, "_ChunkSizes", NC_INT, 3, so4_a1_CLXF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int so4_a1_XFRC_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, so4_a1_XFRC_id, "_ChunkSizes", NC_INT, 4, so4_a1_XFRC_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int so4_a1_sfcoag1_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, so4_a1_sfcoag1_id, "_ChunkSizes", NC_INT, 3, so4_a1_sfcoag1_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int so4_a1_sfcsiz3_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, so4_a1_sfcsiz3_id, "_ChunkSizes", NC_INT, 3, so4_a1_sfcsiz3_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int so4_a1_sfcsiz4_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, so4_a1_sfcsiz4_id, "_ChunkSizes", NC_INT, 3, so4_a1_sfcsiz4_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int so4_a1_sfgaex1_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, so4_a1_sfgaex1_id, "_ChunkSizes", NC_INT, 3, so4_a1_sfgaex1_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int so4_a1_sfgaex2_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, so4_a1_sfgaex2_id, "_ChunkSizes", NC_INT, 3, so4_a1_sfgaex2_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int so4_a2_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, so4_a2_id, "_ChunkSizes", NC_INT, 4, so4_a2_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int so4_a2DDF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, so4_a2DDF_id, "_ChunkSizes", NC_INT, 3, so4_a2DDF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int so4_a2GVF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, so4_a2GVF_id, "_ChunkSizes", NC_INT, 3, so4_a2GVF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int so4_a2SFSBC_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, so4_a2SFSBC_id, "_ChunkSizes", NC_INT, 3, so4_a2SFSBC_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int so4_a2SFSBS_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, so4_a2SFSBS_id, "_ChunkSizes", NC_INT, 3, so4_a2SFSBS_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int so4_a2SFSIC_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, so4_a2SFSIC_id, "_ChunkSizes", NC_INT, 3, so4_a2SFSIC_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int so4_a2SFSIS_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, so4_a2SFSIS_id, "_ChunkSizes", NC_INT, 3, so4_a2SFSIS_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int so4_a2SFWET_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, so4_a2SFWET_id, "_ChunkSizes", NC_INT, 3, so4_a2SFWET_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int so4_a2TBF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, so4_a2TBF_id, "_ChunkSizes", NC_INT, 3, so4_a2TBF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int so4_a2_CLXF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, so4_a2_CLXF_id, "_ChunkSizes", NC_INT, 3, so4_a2_CLXF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int so4_a2_XFRC_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, so4_a2_XFRC_id, "_ChunkSizes", NC_INT, 4, so4_a2_XFRC_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int so4_a2_sfcoag1_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, so4_a2_sfcoag1_id, "_ChunkSizes", NC_INT, 3, so4_a2_sfcoag1_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int so4_a2_sfcsiz3_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, so4_a2_sfcsiz3_id, "_ChunkSizes", NC_INT, 3, so4_a2_sfcsiz3_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int so4_a2_sfcsiz4_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, so4_a2_sfcsiz4_id, "_ChunkSizes", NC_INT, 3, so4_a2_sfcsiz4_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int so4_a2_sfgaex1_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, so4_a2_sfgaex1_id, "_ChunkSizes", NC_INT, 3, so4_a2_sfgaex1_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int so4_a2_sfgaex2_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, so4_a2_sfgaex2_id, "_ChunkSizes", NC_INT, 3, so4_a2_sfgaex2_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int so4_a2_sfnnuc1_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, so4_a2_sfnnuc1_id, "_ChunkSizes", NC_INT, 3, so4_a2_sfnnuc1_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int so4_a3_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, so4_a3_id, "_ChunkSizes", NC_INT, 4, so4_a3_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int so4_a3DDF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, so4_a3DDF_id, "_ChunkSizes", NC_INT, 3, so4_a3DDF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int so4_a3GVF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, so4_a3GVF_id, "_ChunkSizes", NC_INT, 3, so4_a3GVF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int so4_a3SFSBC_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, so4_a3SFSBC_id, "_ChunkSizes", NC_INT, 3, so4_a3SFSBC_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int so4_a3SFSBS_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, so4_a3SFSBS_id, "_ChunkSizes", NC_INT, 3, so4_a3SFSBS_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int so4_a3SFSIC_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, so4_a3SFSIC_id, "_ChunkSizes", NC_INT, 3, so4_a3SFSIC_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int so4_a3SFSIS_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, so4_a3SFSIS_id, "_ChunkSizes", NC_INT, 3, so4_a3SFSIS_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int so4_a3SFWET_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, so4_a3SFWET_id, "_ChunkSizes", NC_INT, 3, so4_a3SFWET_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int so4_a3TBF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, so4_a3TBF_id, "_ChunkSizes", NC_INT, 3, so4_a3TBF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int so4_a3_sfgaex1_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, so4_a3_sfgaex1_id, "_ChunkSizes", NC_INT, 3, so4_a3_sfgaex1_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int so4_c1_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, so4_c1_id, "_ChunkSizes", NC_INT, 4, so4_c1_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int so4_c1AQH2SO4_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, so4_c1AQH2SO4_id, "_ChunkSizes", NC_INT, 3, so4_c1AQH2SO4_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int so4_c1AQSO4_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, so4_c1AQSO4_id, "_ChunkSizes", NC_INT, 3, so4_c1AQSO4_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int so4_c1DDF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, so4_c1DDF_id, "_ChunkSizes", NC_INT, 3, so4_c1DDF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int so4_c1GVF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, so4_c1GVF_id, "_ChunkSizes", NC_INT, 3, so4_c1GVF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int so4_c1SFSBC_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, so4_c1SFSBC_id, "_ChunkSizes", NC_INT, 3, so4_c1SFSBC_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int so4_c1SFSBS_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, so4_c1SFSBS_id, "_ChunkSizes", NC_INT, 3, so4_c1SFSBS_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int so4_c1SFSIC_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, so4_c1SFSIC_id, "_ChunkSizes", NC_INT, 3, so4_c1SFSIC_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int so4_c1SFSIS_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, so4_c1SFSIS_id, "_ChunkSizes", NC_INT, 3, so4_c1SFSIS_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int so4_c1SFWET_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, so4_c1SFWET_id, "_ChunkSizes", NC_INT, 3, so4_c1SFWET_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int so4_c1TBF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, so4_c1TBF_id, "_ChunkSizes", NC_INT, 3, so4_c1TBF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int so4_c1_sfcsiz3_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, so4_c1_sfcsiz3_id, "_ChunkSizes", NC_INT, 3, so4_c1_sfcsiz3_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int so4_c1_sfcsiz4_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, so4_c1_sfcsiz4_id, "_ChunkSizes", NC_INT, 3, so4_c1_sfcsiz4_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int so4_c1_sfgaex2_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, so4_c1_sfgaex2_id, "_ChunkSizes", NC_INT, 3, so4_c1_sfgaex2_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int so4_c2_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, so4_c2_id, "_ChunkSizes", NC_INT, 4, so4_c2_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int so4_c2AQH2SO4_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, so4_c2AQH2SO4_id, "_ChunkSizes", NC_INT, 3, so4_c2AQH2SO4_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int so4_c2AQSO4_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, so4_c2AQSO4_id, "_ChunkSizes", NC_INT, 3, so4_c2AQSO4_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int so4_c2DDF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, so4_c2DDF_id, "_ChunkSizes", NC_INT, 3, so4_c2DDF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int so4_c2GVF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, so4_c2GVF_id, "_ChunkSizes", NC_INT, 3, so4_c2GVF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int so4_c2SFSBC_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, so4_c2SFSBC_id, "_ChunkSizes", NC_INT, 3, so4_c2SFSBC_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int so4_c2SFSBS_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, so4_c2SFSBS_id, "_ChunkSizes", NC_INT, 3, so4_c2SFSBS_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int so4_c2SFSIC_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, so4_c2SFSIC_id, "_ChunkSizes", NC_INT, 3, so4_c2SFSIC_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int so4_c2SFSIS_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, so4_c2SFSIS_id, "_ChunkSizes", NC_INT, 3, so4_c2SFSIS_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int so4_c2SFWET_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, so4_c2SFWET_id, "_ChunkSizes", NC_INT, 3, so4_c2SFWET_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int so4_c2TBF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, so4_c2TBF_id, "_ChunkSizes", NC_INT, 3, so4_c2TBF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int so4_c2_sfcsiz3_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, so4_c2_sfcsiz3_id, "_ChunkSizes", NC_INT, 3, so4_c2_sfcsiz3_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int so4_c2_sfcsiz4_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, so4_c2_sfcsiz4_id, "_ChunkSizes", NC_INT, 3, so4_c2_sfcsiz4_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int so4_c2_sfgaex2_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, so4_c2_sfgaex2_id, "_ChunkSizes", NC_INT, 3, so4_c2_sfgaex2_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int so4_c3_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, so4_c3_id, "_ChunkSizes", NC_INT, 4, so4_c3_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int so4_c3AQH2SO4_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, so4_c3AQH2SO4_id, "_ChunkSizes", NC_INT, 3, so4_c3AQH2SO4_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int so4_c3AQSO4_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, so4_c3AQSO4_id, "_ChunkSizes", NC_INT, 3, so4_c3AQSO4_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int so4_c3DDF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, so4_c3DDF_id, "_ChunkSizes", NC_INT, 3, so4_c3DDF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int so4_c3GVF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, so4_c3GVF_id, "_ChunkSizes", NC_INT, 3, so4_c3GVF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int so4_c3SFSBC_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, so4_c3SFSBC_id, "_ChunkSizes", NC_INT, 3, so4_c3SFSBC_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int so4_c3SFSBS_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, so4_c3SFSBS_id, "_ChunkSizes", NC_INT, 3, so4_c3SFSBS_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int so4_c3SFSIC_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, so4_c3SFSIC_id, "_ChunkSizes", NC_INT, 3, so4_c3SFSIC_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int so4_c3SFSIS_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, so4_c3SFSIS_id, "_ChunkSizes", NC_INT, 3, so4_c3SFSIS_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int so4_c3SFWET_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, so4_c3SFWET_id, "_ChunkSizes", NC_INT, 3, so4_c3SFWET_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int so4_c3TBF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, so4_c3TBF_id, "_ChunkSizes", NC_INT, 3, so4_c3TBF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int soa_a1_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, soa_a1_id, "_ChunkSizes", NC_INT, 4, soa_a1_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int soa_a1DDF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, soa_a1DDF_id, "_ChunkSizes", NC_INT, 3, soa_a1DDF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int soa_a1GVF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, soa_a1GVF_id, "_ChunkSizes", NC_INT, 3, soa_a1GVF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int soa_a1SFSBC_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, soa_a1SFSBC_id, "_ChunkSizes", NC_INT, 3, soa_a1SFSBC_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int soa_a1SFSBS_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, soa_a1SFSBS_id, "_ChunkSizes", NC_INT, 3, soa_a1SFSBS_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int soa_a1SFSIC_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, soa_a1SFSIC_id, "_ChunkSizes", NC_INT, 3, soa_a1SFSIC_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int soa_a1SFSIS_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, soa_a1SFSIS_id, "_ChunkSizes", NC_INT, 3, soa_a1SFSIS_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int soa_a1SFWET_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, soa_a1SFWET_id, "_ChunkSizes", NC_INT, 3, soa_a1SFWET_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int soa_a1TBF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, soa_a1TBF_id, "_ChunkSizes", NC_INT, 3, soa_a1TBF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int soa_a1_sfcoag1_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, soa_a1_sfcoag1_id, "_ChunkSizes", NC_INT, 3, soa_a1_sfcoag1_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int soa_a1_sfcsiz3_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, soa_a1_sfcsiz3_id, "_ChunkSizes", NC_INT, 3, soa_a1_sfcsiz3_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int soa_a1_sfcsiz4_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, soa_a1_sfcsiz4_id, "_ChunkSizes", NC_INT, 3, soa_a1_sfcsiz4_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int soa_a1_sfgaex1_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, soa_a1_sfgaex1_id, "_ChunkSizes", NC_INT, 3, soa_a1_sfgaex1_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int soa_a1_sfgaex2_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, soa_a1_sfgaex2_id, "_ChunkSizes", NC_INT, 3, soa_a1_sfgaex2_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int soa_a2_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, soa_a2_id, "_ChunkSizes", NC_INT, 4, soa_a2_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int soa_a2DDF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, soa_a2DDF_id, "_ChunkSizes", NC_INT, 3, soa_a2DDF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int soa_a2GVF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, soa_a2GVF_id, "_ChunkSizes", NC_INT, 3, soa_a2GVF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int soa_a2SFSBC_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, soa_a2SFSBC_id, "_ChunkSizes", NC_INT, 3, soa_a2SFSBC_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int soa_a2SFSBS_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, soa_a2SFSBS_id, "_ChunkSizes", NC_INT, 3, soa_a2SFSBS_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int soa_a2SFSIC_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, soa_a2SFSIC_id, "_ChunkSizes", NC_INT, 3, soa_a2SFSIC_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int soa_a2SFSIS_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, soa_a2SFSIS_id, "_ChunkSizes", NC_INT, 3, soa_a2SFSIS_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int soa_a2SFWET_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, soa_a2SFWET_id, "_ChunkSizes", NC_INT, 3, soa_a2SFWET_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int soa_a2TBF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, soa_a2TBF_id, "_ChunkSizes", NC_INT, 3, soa_a2TBF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int soa_a2_sfcoag1_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, soa_a2_sfcoag1_id, "_ChunkSizes", NC_INT, 3, soa_a2_sfcoag1_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int soa_a2_sfcsiz3_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, soa_a2_sfcsiz3_id, "_ChunkSizes", NC_INT, 3, soa_a2_sfcsiz3_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int soa_a2_sfcsiz4_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, soa_a2_sfcsiz4_id, "_ChunkSizes", NC_INT, 3, soa_a2_sfcsiz4_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int soa_a2_sfgaex1_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, soa_a2_sfgaex1_id, "_ChunkSizes", NC_INT, 3, soa_a2_sfgaex1_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int soa_a2_sfgaex2_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, soa_a2_sfgaex2_id, "_ChunkSizes", NC_INT, 3, soa_a2_sfgaex2_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int soa_c1_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, soa_c1_id, "_ChunkSizes", NC_INT, 4, soa_c1_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int soa_c1DDF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, soa_c1DDF_id, "_ChunkSizes", NC_INT, 3, soa_c1DDF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int soa_c1GVF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, soa_c1GVF_id, "_ChunkSizes", NC_INT, 3, soa_c1GVF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int soa_c1SFSBC_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, soa_c1SFSBC_id, "_ChunkSizes", NC_INT, 3, soa_c1SFSBC_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int soa_c1SFSBS_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, soa_c1SFSBS_id, "_ChunkSizes", NC_INT, 3, soa_c1SFSBS_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int soa_c1SFSIC_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, soa_c1SFSIC_id, "_ChunkSizes", NC_INT, 3, soa_c1SFSIC_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int soa_c1SFSIS_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, soa_c1SFSIS_id, "_ChunkSizes", NC_INT, 3, soa_c1SFSIS_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int soa_c1SFWET_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, soa_c1SFWET_id, "_ChunkSizes", NC_INT, 3, soa_c1SFWET_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int soa_c1TBF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, soa_c1TBF_id, "_ChunkSizes", NC_INT, 3, soa_c1TBF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int soa_c1_sfcsiz3_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, soa_c1_sfcsiz3_id, "_ChunkSizes", NC_INT, 3, soa_c1_sfcsiz3_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int soa_c1_sfcsiz4_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, soa_c1_sfcsiz4_id, "_ChunkSizes", NC_INT, 3, soa_c1_sfcsiz4_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int soa_c1_sfgaex2_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, soa_c1_sfgaex2_id, "_ChunkSizes", NC_INT, 3, soa_c1_sfgaex2_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int soa_c2_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, soa_c2_id, "_ChunkSizes", NC_INT, 4, soa_c2_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int soa_c2DDF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, soa_c2DDF_id, "_ChunkSizes", NC_INT, 3, soa_c2DDF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int soa_c2GVF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, soa_c2GVF_id, "_ChunkSizes", NC_INT, 3, soa_c2GVF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int soa_c2SFSBC_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, soa_c2SFSBC_id, "_ChunkSizes", NC_INT, 3, soa_c2SFSBC_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int soa_c2SFSBS_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, soa_c2SFSBS_id, "_ChunkSizes", NC_INT, 3, soa_c2SFSBS_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int soa_c2SFSIC_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, soa_c2SFSIC_id, "_ChunkSizes", NC_INT, 3, soa_c2SFSIC_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int soa_c2SFSIS_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, soa_c2SFSIS_id, "_ChunkSizes", NC_INT, 3, soa_c2SFSIS_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int soa_c2SFWET_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, soa_c2SFWET_id, "_ChunkSizes", NC_INT, 3, soa_c2SFWET_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int soa_c2TBF_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, soa_c2TBF_id, "_ChunkSizes", NC_INT, 3, soa_c2TBF_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int soa_c2_sfcsiz3_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, soa_c2_sfcsiz3_id, "_ChunkSizes", NC_INT, 3, soa_c2_sfcsiz3_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int soa_c2_sfcsiz4_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, soa_c2_sfcsiz4_id, "_ChunkSizes", NC_INT, 3, soa_c2_sfcsiz4_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int soa_c2_sfgaex2_ChunkSizes_att[3] = {1, 96, 144} ;
    stat = nc_put_att_int(ncid, soa_c2_sfgaex2_id, "_ChunkSizes", NC_INT, 3, soa_c2_sfgaex2_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int wat_a1_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, wat_a1_id, "_ChunkSizes", NC_INT, 4, wat_a1_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int wat_a2_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, wat_a2_id, "_ChunkSizes", NC_INT, 4, wat_a2_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }
    { /* _ChunkSizes */
    static const int wat_a3_ChunkSizes_att[4] = {1, 30, 96, 144} ;
    stat = nc_put_att_int(ncid, wat_a3_id, "_ChunkSizes", NC_INT, 4, wat_a3_ChunkSizes_att);
    check_err(stat,__LINE__,__FILE__);
    }


    /* leave define mode */
    stat = nc_enddef (ncid);
    check_err(stat,__LINE__,__FILE__);

    /* assign variable data */

    stat = nc_close(ncid);
    check_err(stat,__LINE__,__FILE__);
    return 0;
}
