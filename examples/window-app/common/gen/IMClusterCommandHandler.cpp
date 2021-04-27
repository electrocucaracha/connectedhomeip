/*
 *
 *    Copyright (c) 2021 Project CHIP Authors
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

// THIS FILE IS GENERATED BY ZAP

#include <cstdint>
#include <cinttypes>

#include "af-structs.h"
#include "call-command-handler.h"
#include "callback.h"
#include "cluster-id.h"
#include "command-id.h"
#include "app/util/util.h"

#include <app/InteractionModelEngine.h>

// Currently we need some work to keep compatible with ember lib.
#include <util/ember-compatibility-functions.h>

namespace chip {
namespace app {

// Cluster specific command parsing

namespace clusters {

namespace WindowCovering {

void DispatchServerCommand(app::Command * apCommandObj, CommandId aCommandId, EndpointId aEndpointId, TLV::TLVReader & aDataTlv)
{
    {
        switch (aCommandId)
        {
        case ZCL_WINDOW_COVERING_DOWN_CLOSE_COMMAND_ID: {

        // TODO(#5098) We should pass the Command Object and EndpointId to the cluster callbacks.
        emberAfWindowCoveringClusterWindowCoveringDownCloseCallback(apCommandObj);
                    break;
        }
        case ZCL_WINDOW_COVERING_GO_TO_LIFT_PERCENTAGE_COMMAND_ID: {
        // We are using TLVUnpackError and TLVError here since both of them can be CHIP_END_OF_TLV
// When TLVError is CHIP_END_OF_TLV, it means we have iterated all of the items, which is not a real error.
// Any error value TLVUnpackError means we have received an illegal value.
CHIP_ERROR TLVError = CHIP_NO_ERROR;
CHIP_ERROR TLVUnpackError = CHIP_NO_ERROR;
uint8_t percentageLiftValue;
bool percentageLiftValueExists = false;
uint32_t validArgumentCount = 0;

while ((TLVError = aDataTlv.Next()) == CHIP_NO_ERROR)
{
  switch (TLV::TagNumFromTag(aDataTlv.GetTag()))
  {
    case 0:
      if (percentageLiftValueExists)
      {
            ChipLogProgress(Zcl, "Duplicate TLV tag %" PRIx32, TLV::TagNumFromTag(aDataTlv.GetTag()));
            TLVUnpackError = CHIP_ERROR_IM_MALFORMED_COMMAND_DATA_ELEMENT;
            break;
      }
      TLVUnpackError = aDataTlv.Get(percentageLiftValue);
      if (CHIP_NO_ERROR == TLVUnpackError)
      {
            percentageLiftValueExists = true;
            validArgumentCount++;
      }
      break;
    default:
      // Unsupported tag, ignore it.
      ChipLogProgress(Zcl, "Unknown TLV tag during processing.");
      break;
  }
  if (TLVUnpackError != CHIP_NO_ERROR)
  {
    ChipLogProgress(Zcl, "Failed to decode TLV data with tag %" PRIx32 ": %" PRId32, TLV::TagNumFromTag(aDataTlv.GetTag()), TLVUnpackError);
    break;
  }
}

if (CHIP_END_OF_TLV == TLVError)
{
      // CHIP_END_OF_TLV means we have iterated all items in the structure, which is not a real error.
      TLVError = CHIP_NO_ERROR;
}
else
{
      ChipLogProgress(Zcl, "Failed to decode TLV data: %" PRId32, TLVError);
}

        // TODO(#5590) We should encode a response of status code for invalid TLV.
if (CHIP_NO_ERROR == TLVError && CHIP_NO_ERROR == TLVUnpackError && 1 == validArgumentCount)
{
// TODO(#5098) We should pass the Command Object and EndpointId to the cluster callbacks.
        emberAfWindowCoveringClusterWindowCoveringGoToLiftPercentageCallback(apCommandObj, percentageLiftValue);
        }
else
{
      apCommandObj->AddStatusCode(nullptr, Protocols::SecureChannel::GeneralStatusCode::kBadRequest, Protocols::SecureChannel::Id,
                      Protocols::SecureChannel::kProtocolCodeGeneralFailure);
      ChipLogProgress(Zcl, "Failed to dispatch command, %d/%" PRIu32 " arguments parsed, TLVError=%" PRIu32 ", UnpackError=%" PRIu32, 1, validArgumentCount, TLVError, TLVUnpackError);
}
            break;
        }
        case ZCL_WINDOW_COVERING_GO_TO_LIFT_VALUE_COMMAND_ID: {
        // We are using TLVUnpackError and TLVError here since both of them can be CHIP_END_OF_TLV
// When TLVError is CHIP_END_OF_TLV, it means we have iterated all of the items, which is not a real error.
// Any error value TLVUnpackError means we have received an illegal value.
CHIP_ERROR TLVError = CHIP_NO_ERROR;
CHIP_ERROR TLVUnpackError = CHIP_NO_ERROR;
uint16_t liftValue;
bool liftValueExists = false;
uint32_t validArgumentCount = 0;

while ((TLVError = aDataTlv.Next()) == CHIP_NO_ERROR)
{
  switch (TLV::TagNumFromTag(aDataTlv.GetTag()))
  {
    case 0:
      if (liftValueExists)
      {
            ChipLogProgress(Zcl, "Duplicate TLV tag %" PRIx32, TLV::TagNumFromTag(aDataTlv.GetTag()));
            TLVUnpackError = CHIP_ERROR_IM_MALFORMED_COMMAND_DATA_ELEMENT;
            break;
      }
      TLVUnpackError = aDataTlv.Get(liftValue);
      if (CHIP_NO_ERROR == TLVUnpackError)
      {
            liftValueExists = true;
            validArgumentCount++;
      }
      break;
    default:
      // Unsupported tag, ignore it.
      ChipLogProgress(Zcl, "Unknown TLV tag during processing.");
      break;
  }
  if (TLVUnpackError != CHIP_NO_ERROR)
  {
    ChipLogProgress(Zcl, "Failed to decode TLV data with tag %" PRIx32 ": %" PRId32, TLV::TagNumFromTag(aDataTlv.GetTag()), TLVUnpackError);
    break;
  }
}

if (CHIP_END_OF_TLV == TLVError)
{
      // CHIP_END_OF_TLV means we have iterated all items in the structure, which is not a real error.
      TLVError = CHIP_NO_ERROR;
}
else
{
      ChipLogProgress(Zcl, "Failed to decode TLV data: %" PRId32, TLVError);
}

        // TODO(#5590) We should encode a response of status code for invalid TLV.
if (CHIP_NO_ERROR == TLVError && CHIP_NO_ERROR == TLVUnpackError && 1 == validArgumentCount)
{
// TODO(#5098) We should pass the Command Object and EndpointId to the cluster callbacks.
        emberAfWindowCoveringClusterWindowCoveringGoToLiftValueCallback(apCommandObj, liftValue);
        }
else
{
      apCommandObj->AddStatusCode(nullptr, Protocols::SecureChannel::GeneralStatusCode::kBadRequest, Protocols::SecureChannel::Id,
                      Protocols::SecureChannel::kProtocolCodeGeneralFailure);
      ChipLogProgress(Zcl, "Failed to dispatch command, %d/%" PRIu32 " arguments parsed, TLVError=%" PRIu32 ", UnpackError=%" PRIu32, 1, validArgumentCount, TLVError, TLVUnpackError);
}
            break;
        }
        case ZCL_WINDOW_COVERING_GO_TO_TILT_PERCENTAGE_COMMAND_ID: {
        // We are using TLVUnpackError and TLVError here since both of them can be CHIP_END_OF_TLV
// When TLVError is CHIP_END_OF_TLV, it means we have iterated all of the items, which is not a real error.
// Any error value TLVUnpackError means we have received an illegal value.
CHIP_ERROR TLVError = CHIP_NO_ERROR;
CHIP_ERROR TLVUnpackError = CHIP_NO_ERROR;
uint8_t percentageTiltValue;
bool percentageTiltValueExists = false;
uint32_t validArgumentCount = 0;

while ((TLVError = aDataTlv.Next()) == CHIP_NO_ERROR)
{
  switch (TLV::TagNumFromTag(aDataTlv.GetTag()))
  {
    case 0:
      if (percentageTiltValueExists)
      {
            ChipLogProgress(Zcl, "Duplicate TLV tag %" PRIx32, TLV::TagNumFromTag(aDataTlv.GetTag()));
            TLVUnpackError = CHIP_ERROR_IM_MALFORMED_COMMAND_DATA_ELEMENT;
            break;
      }
      TLVUnpackError = aDataTlv.Get(percentageTiltValue);
      if (CHIP_NO_ERROR == TLVUnpackError)
      {
            percentageTiltValueExists = true;
            validArgumentCount++;
      }
      break;
    default:
      // Unsupported tag, ignore it.
      ChipLogProgress(Zcl, "Unknown TLV tag during processing.");
      break;
  }
  if (TLVUnpackError != CHIP_NO_ERROR)
  {
    ChipLogProgress(Zcl, "Failed to decode TLV data with tag %" PRIx32 ": %" PRId32, TLV::TagNumFromTag(aDataTlv.GetTag()), TLVUnpackError);
    break;
  }
}

if (CHIP_END_OF_TLV == TLVError)
{
      // CHIP_END_OF_TLV means we have iterated all items in the structure, which is not a real error.
      TLVError = CHIP_NO_ERROR;
}
else
{
      ChipLogProgress(Zcl, "Failed to decode TLV data: %" PRId32, TLVError);
}

        // TODO(#5590) We should encode a response of status code for invalid TLV.
if (CHIP_NO_ERROR == TLVError && CHIP_NO_ERROR == TLVUnpackError && 1 == validArgumentCount)
{
// TODO(#5098) We should pass the Command Object and EndpointId to the cluster callbacks.
        emberAfWindowCoveringClusterWindowCoveringGoToTiltPercentageCallback(apCommandObj, percentageTiltValue);
        }
else
{
      apCommandObj->AddStatusCode(nullptr, Protocols::SecureChannel::GeneralStatusCode::kBadRequest, Protocols::SecureChannel::Id,
                      Protocols::SecureChannel::kProtocolCodeGeneralFailure);
      ChipLogProgress(Zcl, "Failed to dispatch command, %d/%" PRIu32 " arguments parsed, TLVError=%" PRIu32 ", UnpackError=%" PRIu32, 1, validArgumentCount, TLVError, TLVUnpackError);
}
            break;
        }
        case ZCL_WINDOW_COVERING_GO_TO_TILT_VALUE_COMMAND_ID: {
        // We are using TLVUnpackError and TLVError here since both of them can be CHIP_END_OF_TLV
// When TLVError is CHIP_END_OF_TLV, it means we have iterated all of the items, which is not a real error.
// Any error value TLVUnpackError means we have received an illegal value.
CHIP_ERROR TLVError = CHIP_NO_ERROR;
CHIP_ERROR TLVUnpackError = CHIP_NO_ERROR;
uint16_t tiltValue;
bool tiltValueExists = false;
uint32_t validArgumentCount = 0;

while ((TLVError = aDataTlv.Next()) == CHIP_NO_ERROR)
{
  switch (TLV::TagNumFromTag(aDataTlv.GetTag()))
  {
    case 0:
      if (tiltValueExists)
      {
            ChipLogProgress(Zcl, "Duplicate TLV tag %" PRIx32, TLV::TagNumFromTag(aDataTlv.GetTag()));
            TLVUnpackError = CHIP_ERROR_IM_MALFORMED_COMMAND_DATA_ELEMENT;
            break;
      }
      TLVUnpackError = aDataTlv.Get(tiltValue);
      if (CHIP_NO_ERROR == TLVUnpackError)
      {
            tiltValueExists = true;
            validArgumentCount++;
      }
      break;
    default:
      // Unsupported tag, ignore it.
      ChipLogProgress(Zcl, "Unknown TLV tag during processing.");
      break;
  }
  if (TLVUnpackError != CHIP_NO_ERROR)
  {
    ChipLogProgress(Zcl, "Failed to decode TLV data with tag %" PRIx32 ": %" PRId32, TLV::TagNumFromTag(aDataTlv.GetTag()), TLVUnpackError);
    break;
  }
}

if (CHIP_END_OF_TLV == TLVError)
{
      // CHIP_END_OF_TLV means we have iterated all items in the structure, which is not a real error.
      TLVError = CHIP_NO_ERROR;
}
else
{
      ChipLogProgress(Zcl, "Failed to decode TLV data: %" PRId32, TLVError);
}

        // TODO(#5590) We should encode a response of status code for invalid TLV.
if (CHIP_NO_ERROR == TLVError && CHIP_NO_ERROR == TLVUnpackError && 1 == validArgumentCount)
{
// TODO(#5098) We should pass the Command Object and EndpointId to the cluster callbacks.
        emberAfWindowCoveringClusterWindowCoveringGoToTiltValueCallback(apCommandObj, tiltValue);
        }
else
{
      apCommandObj->AddStatusCode(nullptr, Protocols::SecureChannel::GeneralStatusCode::kBadRequest, Protocols::SecureChannel::Id,
                      Protocols::SecureChannel::kProtocolCodeGeneralFailure);
      ChipLogProgress(Zcl, "Failed to dispatch command, %d/%" PRIu32 " arguments parsed, TLVError=%" PRIu32 ", UnpackError=%" PRIu32, 1, validArgumentCount, TLVError, TLVUnpackError);
}
            break;
        }
        case ZCL_WINDOW_COVERING_STOP_COMMAND_ID: {

        // TODO(#5098) We should pass the Command Object and EndpointId to the cluster callbacks.
        emberAfWindowCoveringClusterWindowCoveringStopCallback(apCommandObj);
                    break;
        }
        case ZCL_WINDOW_COVERING_UP_OPEN_COMMAND_ID: {

        // TODO(#5098) We should pass the Command Object and EndpointId to the cluster callbacks.
        emberAfWindowCoveringClusterWindowCoveringUpOpenCallback(apCommandObj);
                    break;
        }
        default: {
            // Unrecognized command ID, error status will apply.
            apCommandObj->AddStatusCode(nullptr, Protocols::SecureChannel::GeneralStatusCode::kNotFound, Protocols::SecureChannel::Id,
                            Protocols::SecureChannel::kProtocolCodeGeneralFailure);
            ChipLogError(Zcl, "Unknown command %" PRIx16 " for cluster %" PRIx16, aCommandId, ZCL_WINDOW_COVERING_CLUSTER_ID);
            break;
        }
        }
    }
}

}


} // namespace clusters

void DispatchSingleClusterCommand(chip::ClusterId aClusterId, chip::CommandId aCommandId, chip::EndpointId aEndPointId,
                             chip::TLV::TLVReader & aReader, Command * apCommandObj)
{
    ChipLogDetail(Zcl, "Received Cluster Command: Cluster=%" PRIx16 " Command=%" PRIx8 " Endpoint=%" PRIx8, aClusterId,
                  aCommandId, aEndPointId);
    Compatibility::SetupEmberAfObjects(apCommandObj, aClusterId, aCommandId, aEndPointId);
    TLV::TLVType dataTlvType;
    SuccessOrExit(aReader.EnterContainer(dataTlvType));
    switch (aClusterId)
    {
    case ZCL_WINDOW_COVERING_CLUSTER_ID :
        clusters::WindowCovering::DispatchServerCommand(apCommandObj, aCommandId, aEndPointId, aReader);
        break;
    default:
        // Unrecognized cluster ID, error status will apply.
        apCommandObj->AddStatusCode(nullptr, Protocols::SecureChannel::GeneralStatusCode::kNotFound, Protocols::SecureChannel::Id,
                            Protocols::SecureChannel::kProtocolCodeGeneralFailure);
        ChipLogError(Zcl, "Unknown cluster %" PRIx16, aClusterId);
        break;
    }
exit:
    Compatibility::ResetEmberAfObjects();
    aReader.ExitContainer(dataTlvType);
}

} // namespace app
} // namespace chip
