import unreal

PREFIX_RULES = {
    "StaticMesh": "SM_",
    "SkeletalMesh": "SK_",
    "Material": "M_",
    "MaterialInstanceConstant": "MI_",
    "Texture2D": "T_",
    "Texture": "T_",
    "Blueprint": "BP_",
    "AnimBlueprint": "ABP_",
    "SoundCue": "SC_",
    "NiagaraSystem": "NS_",
    "NiagaraEmitter": "FXE_",
    "NiagaraFunction": "FXF_",
    "DataTable": "DT_",
    "CurveFloat": "Curve_",
    "CurveTable": "Curve_",
    "LevelSequence": "LS_",
    "SoundWave": "A_",
    "PhysicalMaterial": "PM_",
    "PhysicsAsset": "PHYS_",
    "ParticleSystem": "PS_",
    "WidgetBlueprint": "WBP_",
    "BlueprintInterface": "BI_",
    "Enum": "E_",
    "Struct": "F_",
    "AnimationSequence": "A_",
    "AnimationMontage": "AM_",
    "BlendSpace": "BS_",
    "Skeleton": "SKEL_",
    "Rig": "Rig_",
    "MorphTarget": "MT_",
    "FoliageType": "FT_",
    "ForceFeedbackEffect": "FFE_",
    "LandscapeGrassType": "LG_",
    "LandscapeLayerInfo": "LL_",
    "MediaPlayer": "MP_",
    "MediaSoundWave": "MSW_",
    "MediaSource": "MS_",
    "MediaProfile": "MPR_",
    "ReverbEffect": "Reverb_",
    "SoundAttenuation": "ATT_",
    "MaterialFunction": "MF_",
    "MaterialParameterCollection": "MPC_",
    "Sprite": "SPR_",
    "SpriteSheet": "SS_",
    "PaperFlipbook": "PFB_",
    "TileMap": "TM_",
    "TileSet": "TS_",
    "SubstanceGraphInstance": "SGI_",
    "SubstanceInstanceFactory": "SIF_",
    "DestructibleMesh": "DM_",
    "ApexClothAsset": "AC_",
    "ApexDestructibleAsset": "AD_",
    "VectorFieldAnimated": "VFA_",
    "StaticVectorField": "VF_",
    "CameraAnim": "CA_",
    "ColorCurve": "Curve_",
    "VectorCurve": "Curve_",
    "MaterialInstanceTimeVarying": "MITV_",
    "RenderTarget": "RT_",
    "MetaHumanCharacter": "MHC_",
    "MetaHumanIdentity": "MHID_",
    "MetaHumanPerformance": "MHP_",
    "MetaHumanWardrobeItem": "WI_",
    "CaptureData": "CD_"
}


asset_registry = unreal.AssetRegistryHelpers.get_asset_registry()
all_assets = asset_registry.get_assets_by_path("/Game", recursive=True)

unreal.log(f"Checker found {len(all_assets)} ojects.")

incorrect_assets = []

for asset_data in all_assets:

    asset_class = asset_data.get_class().get_name()
    asset_name = asset_data.get_full_name().split(" ")[1].split(".")[-1]
    expected_prefix = PREFIX_RULES.get(asset_class)

    if expected_prefix and not asset_name.startswith(expected_prefix):
        incorrect_assets.append((asset_name, asset_class, expected_prefix))

if incorrect_assets:
    unreal.log_warning(f"--- {len(incorrect_assets)} wrong names found ---")
    for asset in incorrect_assets:
        path, asset_class, expected = asset
        unreal.log_warning(f"[{asset_class}] {path} -> should start with '{expected}'")

else:
    unreal.log("✅ All assets are properly named according to defined rules.")
