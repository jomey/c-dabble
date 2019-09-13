#include "gdal.h"
#include "cpl_conv.h"
#include <string.h>

/*
 * gcc -o gdal_vrt_meta gdal_vrt.c -I/Volumes/warehouse/projects/miniconda/envs/dem_tools/include 
 *                                 -L/Volumes/warehouse/projects/miniconda/envs/dem_tools/lib
 *                                 -lgdal
 *
 * install_name_tool -add_rpath $CONDA_PREFIX/lib gdal_vrt_meta
*/

#define RpcMetadataDomain "RPC"

void addeMetadata(GDALDatasetH *file, char * key, char * value) {
  GDALSetMetadataItem(file, key, value, RpcMetadataDomain);
}


int main(int argc, char **argv) {

  const char *pszFormatVrt = "VRT";

  GDALAllRegister();

  GDALDriverH *poDriverVrt = (GDALDriverH *) GDALGetDriverByName(pszFormatVrt);
  GDALDatasetH *poGTiffDS, *poVrtDS;

  printf("Source: %s\n", argv[1]) ;
  printf("Destination: %s\n", argv[2]);

  poGTiffDS = GDALOpenShared(argv[1], GA_ReadOnly);
  poVrtDS = GDALCreateCopy(
      poDriverVrt, 
      argv[2],
      poGTiffDS, 
      FALSE, NULL, NULL, NULL 
  );

  addeMetadata(poVrtDS, "key", "value");

  GDALClose((GDALDatasetH) poVrtDS);
  GDALClose((GDALDatasetH) poGTiffDS);
}

